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

/**
 * @file mtb_touchpad_i2c_port.h
 * @brief PSOC™ Edge reference-port API for CAPSENSE™ Touchpad I2C Host.
 *
 */

#ifndef MTB_TOUCHPAD_I2C_PORT_H_
#define MTB_TOUCHPAD_I2C_PORT_H_
/**
 * @defgroup touchpad_i2c_functions PSOC Edge I2C Port Functions
 * @ingroup mtb_touchpad_api
 * @brief Reference I2C port functions for PSOC Edge E84.
 */



#if defined(__cplusplus)
extern "C" {
#endif



/******************************************************************************
 * Macros
 *****************************************************************************/
 #define I2C_INTR_PRIORITY   (7UL)
/*******************************************************************************
* Function Prototypes
*******************************************************************************/
/**
 * \brief Initializes the I2C interface for the touchpad.
 *
 * This function initializes the I2C peripheral and configures it for
 * communication with the touchpad device. It must be called before any
 * read or write operations are performed.
 *
 * \return  : 0 - Initialization successful
 *            Non-zero - Initialization failed
 *
 * \note Ensure that the I2C hardware and pins are properly configured.
 *
 * \ingroup touchpad_i2c_functions
 */
uint32_t touchpad_i2c_init(void);

/**
 * \brief Reads data from the touchpad device over I2C.
 *
 * This function reads a specified number of bytes from the given
 * subaddress (register) of the touchpad device and stores the data
 * in the provided buffer.
 *
 * \param[in] subaddress : Register address to read from.
 * \param[out] data      : Pointer to buffer where read data will be stored.
 * \param[in] length     : Number of bytes to read.
 * \param[in] intf_ptr   : Pointer to interface-specific context (e.g., I2C handle or slave address).
 *
 * \return               : 0 - Read successful
 *                         Non-zero - Read failed
 *
 * \note The 'data' pointer must be valid and have sufficient space.
 *
 * \ingroup touchpad_i2c_functions
 */
uint32_t touchpad_i2c_read(
    uint16_t subaddress,
    uint8_t* data,
    uint16_t length,
    void* intf_ptr);

/**
 * \brief Writes data to the touchpad device over I2C.
 *
 * This function writes a specified number of bytes to the given
 * subaddress (register) of the touchpad device using the provided data buffer.
 *
 * \param[in] subaddress : Register address to write to.
 * \param[in] data       : Pointer to buffer containing data to be written.
 * \param[in] length     : Number of bytes to write.
 * \param[in] intf_ptr   : Pointer to interface-specific context (e.g., I2C handle or slave address).
 *
 * \return               : 0 - Write successful
 *                         Non-zero - Write failed
 *
 * \note The 'data' pointer must be valid and contain at least 'length' bytes.
 *
 * \ingroup touchpad_i2c_functions
 */
uint32_t touchpad_i2c_write(
    uint16_t subaddress,
    uint8_t* data,
    uint16_t length,
    void* intf_ptr);

#if defined(__cplusplus)
}
#endif



#endif /* MTB_TOUCHPAD_I2C_PORT_H_ */
