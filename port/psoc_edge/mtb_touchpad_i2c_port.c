/******************************************************************************
 * Copyright (c) 2025-2026, Infineon Technologies AG or an affiliate of
 * Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/***************************************************************************//**
* \file mtb_touchpad_i2c_port.c
*
* \brief
* Implements the PSOC™ Edge reference port for CAPSENSE™ Touchpad I2C Host.
*
*******************************************************************************/

/*******************************************************************************
 * Include header file
 ******************************************************************************/
#include <stdint.h>
#include "cybsp.h"
#include "mtb_touchpad_i2c_port.h"
/******************************************************************************
 * Defines
 *****************************************************************************/
#define TOUCHPAD_I2C_ADD    (0x0D)
/******************************************************************************
 * Global Variables
 *****************************************************************************/
cy_stc_scb_i2c_context_t i2cContext;
const cy_stc_sysint_t i2cIntrConfig =
{
    .intrSrc      = CYBSP_I2C_CONTROLLER_IRQ,
    .intrPriority = I2C_INTR_PRIORITY,
};
cy_stc_scb_i2c_master_xfer_config_t transfer;
/******************************************************************************
 * Functions
 *****************************************************************************/
void I2C_Isr(void)
{
    Cy_SCB_I2C_Interrupt(CYBSP_I2C_CONTROLLER_HW, &i2cContext);
}


uint32_t touchpad_i2c_init()
{
    cy_en_scb_i2c_status_t ret_i2c_init;
    cy_en_sysint_status_t ret_sysint_init;

    /* Initialize I2C */
    ret_i2c_init = Cy_SCB_I2C_Init(CYBSP_I2C_CONTROLLER_HW, &CYBSP_I2C_CONTROLLER_config, &i2cContext);

    if (CY_SCB_I2C_SUCCESS != ret_i2c_init)
    {
        return ret_i2c_init;
    }

    /* Hook interrupt service routine and enable interrupt */
    ret_sysint_init = Cy_SysInt_Init(&i2cIntrConfig, &I2C_Isr);

    if (CY_SYSINT_SUCCESS != ret_sysint_init)
    {
        return ret_sysint_init;
    }

    NVIC_EnableIRQ(CYBSP_I2C_CONTROLLER_IRQ);

    /* Enable I2C to operate */
    Cy_SCB_I2C_Enable(CYBSP_I2C_CONTROLLER_HW);

    /* Enable global interrupts */
    __enable_irq();

    return CY_SCB_I2C_SUCCESS;
}


uint32_t touchpad_i2c_read(uint16_t subaddress, uint8_t* data, uint16_t length, void* intf_ptr)
{
    (void)intf_ptr;

    cy_en_scb_i2c_status_t ret;
    uint8_t sub_addres[2] = { 0 };
    sub_addres[1] = (uint8_t)subaddress;
    sub_addres[0] = (uint16_t)subaddress >> 8;

    /* Configure sub-address write transaction */
    transfer.slaveAddress = TOUCHPAD_I2C_ADD;
    transfer.buffer       = sub_addres;
    transfer.bufferSize   = 2;
    transfer.xferPending  = true; /* Do not generate Stop; keep the bus for ReStart */

    /* Initiate write transaction.
     * The Start condition is generated to begin this transaction.
     */
    ret = Cy_SCB_I2C_MasterWrite(CYBSP_I2C_CONTROLLER_HW, &transfer, &i2cContext);

    if (CY_SCB_I2C_SUCCESS != ret)
    {
        return ret;
    }

    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(CYBSP_I2C_CONTROLLER_HW, &i2cContext)))
    {
    }

    /* Configure read transaction */
    transfer.buffer       = data;
    transfer.bufferSize   = length;
    transfer.xferPending  = false; /* Generate Stop condition the end of transaction */

    /* Initiate read transaction.
     * The ReStart condition is generated to begin this transaction because
     * previous transaction was completed without Stop.
     */
    ret = Cy_SCB_I2C_MasterRead(CYBSP_I2C_CONTROLLER_HW, &transfer, &i2cContext);

    if (CY_SCB_I2C_SUCCESS != ret)
    {
        return ret;
    }

    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(CYBSP_I2C_CONTROLLER_HW, &i2cContext)))
    {
    }

    return CY_SCB_I2C_SUCCESS;
}


uint32_t touchpad_i2c_write(uint16_t subaddress, uint8_t* data, uint16_t length, void* intf_ptr)
{
    (void)intf_ptr;

    cy_en_scb_i2c_status_t ret;
    uint8_t sub_addres[50] = { 0 };
    sub_addres[1] = (uint8_t)subaddress;
    sub_addres[0] = (uint16_t)subaddress >> 8;
    memcpy(sub_addres+2, data, length);


    /* Configure sub-address write transaction */
    transfer.slaveAddress = TOUCHPAD_I2C_ADD;
    transfer.buffer       = sub_addres;
    transfer.bufferSize   = 2 + length;
    transfer.xferPending  = false; /* Do not generate Stop condition at the end of transaction */

    /* Initiate write transaction.
     * The Start condition is generated to begin this transaction.
     */
    ret = Cy_SCB_I2C_MasterWrite(CYBSP_I2C_CONTROLLER_HW, &transfer, &i2cContext);

    if (CY_SCB_I2C_SUCCESS != ret)
    {
        return ret;
    }

    /* Wait for transaction completion */
    while (0UL != (CY_SCB_I2C_MASTER_BUSY & Cy_SCB_I2C_MasterGetStatus(CYBSP_I2C_CONTROLLER_HW, &i2cContext)))
    {
    }

    return CY_SCB_I2C_SUCCESS;
}
