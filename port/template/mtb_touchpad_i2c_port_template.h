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

#ifndef MTB_TOUCHPAD_I2C_PORT_TEMPLATE_H_
#define MTB_TOUCHPAD_I2C_PORT_TEMPLATE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Initializes the platform I2C peripheral.
*
* Return:
*   0 on success, non-zero on failure.
******************************************************************************/
uint32_t touchpad_i2c_init(void);

/******************************************************************************
* Reads data from the touchpad over I2C.
*
* Parameters:
*   subaddress - 16-bit register address.
*   data       - Destination buffer.
*   length     - Number of bytes to read.
*   intf_ptr   - Optional platform-specific context.
*
* Return:
*   0 on success, non-zero on failure.
******************************************************************************/
uint32_t touchpad_i2c_read(uint16_t subaddress,
                           uint8_t* data,
                           uint16_t length,
                           void* intf_ptr);

/******************************************************************************
* Writes data to the touchpad over I2C.
*
* Parameters:
*   subaddress - 16-bit register address.
*   data       - Source buffer.
*   length     - Number of bytes to write.
*   intf_ptr   - Optional platform-specific context.
*
* Return:
*   0 on success, non-zero on failure.
******************************************************************************/
uint32_t touchpad_i2c_write(uint16_t subaddress,
                            uint8_t* data,
                            uint16_t length,
                            void* intf_ptr);

#ifdef __cplusplus
}
#endif

#endif /* MTB_TOUCHPAD_I2C_PORT_TEMPLATE_H_ */
