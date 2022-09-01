/* generated vector source file - do not edit */
        #include "bsp_api.h"
        /* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [1] = r_icu_isr, /* ICU IRQ1 (External pin interrupt 1) */
            [2] = ctsu_read_isr, /* CTSU READ (Measurement data transfer request interrupt) */
            [3] = ctsu_end_isr, /* CTSU END (Measurement end interrupt) */
            [4] = sci_uart_rxi_isr, /* SCI9 RXI (Received data full) */
            [5] = sci_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [6] = sci_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [7] = sci_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [9] = ctsu_write_isr, /* CTSU WRITE (Write request interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [1] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ1), /* ICU IRQ1 (External pin interrupt 1) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_CTSU_READ), /* CTSU READ (Measurement data transfer request interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_CTSU_END), /* CTSU END (Measurement end interrupt) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI9_RXI), /* SCI9 RXI (Received data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI9_ERI), /* SCI9 ERI (Receive error) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_CTSU_WRITE), /* CTSU WRITE (Write request interrupt) */
        };
        #endif