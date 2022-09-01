/* generated common source file - do not edit */
#include "common_data.h"
dtc_instance_ctrl_t g_transfer1_ctrl;

transfer_info_t g_transfer1_info =
{
    .dest_addr_mode      = TRANSFER_ADDR_MODE_INCREMENTED,
    .repeat_area         = TRANSFER_REPEAT_AREA_DESTINATION,
    .irq                 = TRANSFER_IRQ_END,
    .chain_mode          = TRANSFER_CHAIN_MODE_DISABLED,
    .src_addr_mode       = TRANSFER_ADDR_MODE_FIXED,
    .size                = TRANSFER_SIZE_2_BYTE,
    .mode                = TRANSFER_MODE_NORMAL,
    .p_dest              = (void *) NULL,
    .p_src               = (void const *) NULL,
    .num_blocks          = 0,
    .length              = 0,
};
const dtc_extended_cfg_t g_transfer1_cfg_extend =
{
    .activation_source   = VECTOR_NUMBER_CTSU_READ,
};
const transfer_cfg_t g_transfer1_cfg =
{
    .p_info              = &g_transfer1_info,
    .p_extend            = &g_transfer1_cfg_extend,
};

/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 =
{
    .p_ctrl        = &g_transfer1_ctrl,
    .p_cfg         = &g_transfer1_cfg,
    .p_api         = &g_transfer_on_dtc
};
dtc_instance_ctrl_t g_transfer0_ctrl;

transfer_info_t g_transfer0_info =
{
    .dest_addr_mode      = TRANSFER_ADDR_MODE_FIXED,
    .repeat_area         = TRANSFER_REPEAT_AREA_SOURCE,
    .irq                 = TRANSFER_IRQ_END,
    .chain_mode          = TRANSFER_CHAIN_MODE_DISABLED,
    .src_addr_mode       = TRANSFER_ADDR_MODE_INCREMENTED,
    .size                = TRANSFER_SIZE_2_BYTE,
    .mode                = TRANSFER_MODE_NORMAL,
    .p_dest              = (void *) NULL,
    .p_src               = (void const *) NULL,
    .num_blocks          = 0,
    .length              = 0,
};
const dtc_extended_cfg_t g_transfer0_cfg_extend =
{
    .activation_source   = VECTOR_NUMBER_CTSU_WRITE,
};
const transfer_cfg_t g_transfer0_cfg =
{
    .p_info              = &g_transfer0_info,
    .p_extend            = &g_transfer0_cfg_extend,
};

/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 =
{
    .p_ctrl        = &g_transfer0_ctrl,
    .p_cfg         = &g_transfer0_cfg,
    .p_api         = &g_transfer_on_dtc
};
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
        {
            .p_api = &g_ioport_on_ioport,
            .p_ctrl = &g_ioport_ctrl,
            .p_cfg = &g_bsp_pin_cfg,
        };
void g_common_init(void) {
}
