#include "qe_touch_config.h"
#include <rtthread.h>
#include <rtdevice.h>
#define TOUCH_SCAN_INTERVAL_EXAMPLE (20)    /* milliseconds */

uint64_t button_status;
#if (TOUCH_CFG_NUM_SLIDERS != 0)
    uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
    uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif

static rt_timer_t timer1;
rt_sem_t touch_sem = RT_NULL;

RT_WEAK void touch_button_callback(uint64_t status)
{
    rt_kprintf("button status callback!\n");
}

static void scan_timeout(void *parameter)
{
    fsp_err_t err;
    /* for [CONFIG01] configuration */
    err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);
    if (FSP_SUCCESS != err)
    {
        rt_kprintf("RM_TOUCH_Open fail\n");
        return;
    }
}

void qe_touch_main(void *parameter)
{
    fsp_err_t err;

    /* Open Touch middleware */
    rt_kprintf("TOUCH Open\n");
    err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
    if (FSP_SUCCESS != err)
    {
        rt_kprintf("RM_TOUCH_Open fail\n");
        return;
    }

    rt_kprintf("TOUCH ScanStart\n");
    touch_sem = rt_sem_create("tsem", 0, RT_IPC_FLAG_PRIO);
    if (touch_sem == RT_NULL)
    {
        rt_kprintf("create touch semaphore failed.\n");
        return;
    }
    timer1 = rt_timer_create("scan_t", scan_timeout,
                             RT_NULL, TOUCH_SCAN_INTERVAL_EXAMPLE * RT_TICK_PER_SECOND / 1000,
                             RT_TIMER_FLAG_PERIODIC);
    if (timer1 != RT_NULL) rt_timer_start(timer1);
    
    /* Main loop */
    while (true)
    {
        rt_sem_take(touch_sem, RT_WAITING_FOREVER);

        err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
        if (FSP_SUCCESS == err)
        {
            touch_button_callback(button_status);
        }
    }
}

int touch_init(void)
{
    rt_thread_t tid = rt_thread_create("touch", qe_touch_main, RT_NULL, 512, 10, 50);
    if (tid)
    {
        rt_thread_startup(tid);
    }
    return 0;
}
INIT_APP_EXPORT(touch_init);
//MSH_CMD_EXPORT(touch_init, touch_init);
