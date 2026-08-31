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
 * @file mtb_touchpad_driver.h
 * @brief Public API for the CAPSENSE™ Touchpad I2C Host middleware.
 *
 */

#ifndef MTB_TOUCHPAD_DRIVER_H_
#define MTB_TOUCHPAD_DRIVER_H_
/**
 * @defgroup mtb_touchpad_api CAPSENSE™ Touchpad I2C Host
 * @brief Portable host middleware for the PSOC™ 4000T CAPSENSE™ touchpad.
 */

/**
 * @defgroup mtb_touchpad_macro CAPSENSE™ Touchpad I2C Host macros
 * @ingroup mtb_touchpad_api
 * @brief Register-map, size, limit, and helper macros.
 */

/**
 * @defgroup touchpad_low_level_driver Low-Level Interface
 * @ingroup mtb_touchpad_api
 * @brief Callback types used to connect the middleware to a host bus.
 */


#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif




/******************************************************************************
 * Macros
 *****************************************************************************/
/**
 * @defgroup Touchpad CAPSENSE™ Touchpad I2C Host macros
 * @ingroup mtb_touchpad_api
 * @brief Macros for the CAPSENSE™ Touchpad I2C Host middleware.
 * @{
 */

/**
 * @brief CAPSENSE™ Touchpad I2C Host middleware API return type.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_RET_TYPE uint32_t

/**
 * @brief Register address for FW version of the I2C Touchpad device.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER              (REG_FW_VER_MAJ)

/**
 * @brief Register address for major FW version of the I2C Touchpad device.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER_MAJ          0x00

/**
 * @brief Register address for minor FW version of the I2C Touchpad device.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER_MIN          0x01

/**
 * @brief Register address for build FW version of the I2C Touchpad device.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER_BLD          0x03

/**
 * @brief Register address for reset cause.
 * @ingroup mtb_touchpad_macro
 */
#define REG_RST_CAUSE           0x05

/**
 * @brief Register address for command execution.
 * @ingroup mtb_touchpad_macro
 */
#define REG_CMD                 0x06

/**
 * @brief Register address for test status.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TEST_STATUS         0x08

/**
 * @brief Register address for shorted sensor ID.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SHORTED_SNS_ID      0x09

/**
 * @brief Register address for interrupt source enable.
 * @ingroup mtb_touchpad_macro
 */
#define REG_INT_SRC_EN          0x0D

/**
 * @brief Register address for interrupt status.
 * @ingroup mtb_touchpad_macro
 */
#define REG_INT_STATUS          0x0E

/**
 * @brief Register address for error status.
 * @ingroup mtb_touchpad_macro
 */
#define REG_ERROR_STATUS        0x0F

/**
 * @brief Register address for scan mode configuration.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SCAN_MODE           0x10

/**
 * @brief Register address for shield enable and disable configuration.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SHIELD_EN           0x11

/**
 * @brief Register address for active mode timeout.
 * @ingroup mtb_touchpad_macro
 */
#define REG_MODE_TIMEOUT_ACT    0x12

/**
 * @brief Register address for alert mode timeout.
 * @ingroup mtb_touchpad_macro
 */
#define REG_MODE_TIMEOUT_ALR    0x16

/**
 * @brief Register address for sensor filter configuration.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_FILT_CFG        0x24

/**
 * @brief Register address for active mode sensor refresh rate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_REF_RATE_ACT    0x26

/**
 * @brief Register address for ALR mode sensor refresh rate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_REF_RATE_ALR    0x27

/**
 * @brief Base register address for first touch (TCH0) position.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS            (REG_TCH0_POS_X)

/**
 * @brief Register address for TCH0 X coordinate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS_X          0x28

/**
 * @brief Register address for TCH0 Y coordinate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS_Y          0x2A

/**
 * @brief Register address for TCH0 Z coordinate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS_Z          0x2C

/**
 * @brief Base register address for second touch (TCH1) position.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS            (REG_TCH1_POS_X)

/**
 * @brief Register address for TCH1 X coordinate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS_X          0x2E

/**
 * @brief Register address for TCH1 Y coordinate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS_Y          0x30

/**
 * @brief Register address for TCH1 Z coordinate.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS_Z          0x32

/**
 * @brief Register address for number of detected touches.
 * @ingroup mtb_touchpad_macro
 */
#define REG_NUM_TOUCH           0x34

/**
 * @brief Register address for gesture detection.
 * @ingroup mtb_touchpad_macro
 */
#define REG_GESTURE_DET         0x35

/**
 * @brief Register address for gesture direction.
 * @ingroup mtb_touchpad_macro
 */
#define REG_GESTURE_DIR         0x39

/**
 * @brief Register address to enable and disable liquid detection.
 * @ingroup mtb_touchpad_macro
 */
#define REG_LIQUID_DETECT_EN    0x3D

/**
 * @brief Register address for liquid detection status.
 * @ingroup mtb_touchpad_macro
 */
#define REG_LIQUID_DETECTED     0x3E

/**
 * @brief Register address for liquid detection duty cycle.
 * @ingroup mtb_touchpad_macro
 */
#define REG_LIQUID_DUTY_CYCLE   0x3F

/**
 * @brief Register address to enable and disable Donn feature.
 * @ingroup mtb_touchpad_macro
 */
#define REG_DONN_EN             0x40

/**
 * @brief Register address for Donn detection status.
 * @ingroup mtb_touchpad_macro
 */
#define REG_DONN_DETECT         0x41

/**
 * @brief Register address for stored flag.
 * @ingroup mtb_touchpad_macro
 */
#define REG_STORED_FLAG         0x5F

/**
 * @brief Register address for user data length.
 * @ingroup mtb_touchpad_macro
 */
#define REG_USER_DATA_LEN       0x60

/**
 * @brief Register address for number of sensors.
 * @ingroup mtb_touchpad_macro
 */
#define REG_NUM_SNS             0x62

/**
 * @brief Base register address for sensor raw data.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_RAW             0x63

/**
 * @brief Macro to get baseline register address for a sensor index.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_BSL(x)          (REG_SNS_RAW + (2 * (x)))

/**
 * @brief Macro to get capacitance measurement register address for a sensor index.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_CP_MEASURE(x)   (REG_SNS_RAW + (4 * (x)))

/**
 * @brief Macro to get user data register address.
 * @ingroup mtb_touchpad_macro
 */
#define REG_USER_DATA(x)        (REG_SNS_RAW + (8 * (x)))

/**
 * @brief Macro to get address of raw index for a sensor.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_RAW_IDX(x)      REG_SNS_BSL(x)

/**
 * @brief Macro to get address of baseline for given sensor.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_BSL_IDX(x, y)   ((REG_SNS_BSL(x)) + (2 * (y)))

/**
 * @brief Macro to get address of capacitance for given sensor.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_CP_IDX(x, y)    ((REG_SNS_CP_MEASURE(x)) + (4 * (y)))

/**
 * @brief Size of major firmware version register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER_MAJ_SIZE    1

/**
 * @brief Size of minor firmware version register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER_MIN_SIZE    2

/**
 * @brief Size of build firmware version register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_FW_VER_BLD_SIZE    2

/**
 * @brief Size of reset cause register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_RST_CAUSE_SIZE     1

/**
 * @brief Size of command register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_CMD_SIZE           2

/**
 * @brief Size of test status register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TEST_STATUS_SIZE   1

/**
 * @brief Size of shorted sensor ID register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SHORTED_SNS_ID_SIZE 4

/**
 * @brief Size of interrupt source enable register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_INT_SRC_EN_SIZE    1

/**
 * @brief Size of interrupt status register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_INT_STATUS_SIZE    1

/**
 * @brief Size of error status register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_ERROR_STATUS_SIZE  1

/**
 * @brief Size of scan mode register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SCAN_MODE_SIZE     1

/**
 * @brief Size of shield enable register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SHIELD_EN_SIZE     1

/**
 * @brief Size of active mode timeout register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_MODE_TIMEOUT_ACT_SIZE 4

/**
 * @brief Size of ALR mode timeout register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_MODE_TIMEOUT_ALR_SIZE 4

/**
 * @brief Size of sensor filter configuration register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_FILT_CFG_SIZE  2

/**
 * @brief Size of active mode sensor refresh rate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_REF_RATE_ACT_SIZE 1

/**
 * @brief Size of ALR mode sensor refresh rate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_REF_RATE_ALR_SIZE 1

/**
 * @brief Number of words used for touch XYZ data.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH_XYZ_SIZE_WORD  3

/**
 * @brief Size in bytes of touch XYZ data.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH_XYZ_SIZE_BYTES (REG_TCH_XYZ_SIZE_WORD * 2)

/**
 * @brief Size of TCH0 X coordinate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS_X_SIZE    2

/**
 * @brief Size of TCH0 Y coordinate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS_Y_SIZE    2

/**
 * @brief Size of TCH0 Z coordinate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH0_POS_Z_SIZE    2

/**
 * @brief Size of TCH1 X coordinate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS_X_SIZE    2

/**
 * @brief Size of TCH1 Y coordinate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS_Y_SIZE    2

/**
 * @brief Size of TCH1 Z coordinate register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_TCH1_POS_Z_SIZE    2

/**
 * @brief Size of number of touches register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_NUM_TOUCH_SIZE     1

/**
 * @brief Size of gesture detection register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_GESTURE_DET_SIZE   4

/**
 * @brief Size of gesture direction register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_GESTURE_DIR_SIZE   4

/**
 * @brief Size of liquid detect enable register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_LIQUID_DETECT_EN_SIZE 1

/**
 * @brief Size of liquid detected status register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_LIQUID_DETECTED_SIZE 1

/**
 * @brief Size of liquid duty cycle register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_LIQUID_DUTY_CYCLE_SIZE 1

/**
 * @brief Size of Donn enable register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_DONN_EN_SIZE       1

/**
 * @brief Size of Donn detect register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_DONN_DETECT_SIZE   1

/**
 * @brief Size of reserved block 1 in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_RESERVED_1_SIZE    29

/**
 * @brief Size of stored flag register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_STORED_FLAG_SIZE   1

/**
 * @brief Size of user data length register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_USER_DATA_LEN_SIZE 2

/**
 * @brief Size of number of sensors register in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define REG_NUM_SNS_SIZE       1

/**
 * @brief Size of raw sensor data per sensor in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define SNS_RAW_SIZE           2

/**
 * @brief Size of baseline value per sensor in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define BASELINE_SIZE          2

/**
 * @brief Size of capacitance value per sensor in bytes.
 * @ingroup mtb_touchpad_macro
 */
#define CAPACITANCE_SIZE       4

/**
 * @brief Total size of raw sensor data for given number of sensors.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_RAW_SIZE(x)               (SNS_RAW_SIZE * (x))

/**
 * @brief Total baseline data size for given number of sensors.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_BSL_SIZE(x)    (BASELINE_SIZE * (x))

/**
 * @brief Total capacitance data size for given number of sensors.
 * @ingroup mtb_touchpad_macro
 */
#define REG_SNS_CP_MEASURE_SIZE(x) (CAPACITANCE_SIZE * (x))

/**
 * @brief Invalid number of sensors.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_INVALID_NUM_SNS 0x00

/**
 * @brief Clear interrupt pin status.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_CLEAR_INT_STATUS 0x00

/**
 * @brief Minimum valid value for interrupt source enable register (at least one source must be enabled).
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_INT_SRC_EN_MIN 0x01

/**
 * @brief Maximum valid value for interrupt source enable register (all bits 0-7).
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_INT_SRC_EN_MAX 0xFF

/**
 * @brief Maximum valid value for interrupt status register (all bits 0-7).
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_INT_STATUS_MAX 0xFF

/**
 * @brief SNS_REFRESH_RATE_ACT maximum value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_SNS_REFRESH_RATE_ACT_MAX 0xFF

/**
 * @brief SNS_REFRESH_RATE_ACT minimum value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_SNS_REFRESH_RATE_ACT_MIN 0x01

/**
 * @brief SNS_REFRESH_RATE_ALR maximum value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_SNS_REFRESH_RATE_ALR_MAX 0xFF

/**
 * @brief SNS_REFRESH_RATE_ALR minimum value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_SNS_REFRESH_RATE_ALR_MIN 0x01

/**
 * @brief Liquid rejection enabled max value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_LIQUID_DETECT_EN_MAX 0x01

/**
 * @brief Liquid rejection enabled min value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_LIQUID_DETECT_EN_MIN 0x00

/**
 * @brief Liquid rejection duty cycle max value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_LIQUID_DUTY_CYCLE_MAX 0x63

/**
 * @brief Liquid rejection duty cycle min value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_LIQUID_DUTY_CYCLE_MIN 0x00

/**
 * @brief Donn Enable max value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_DONN_EN_MAX 0x01

/**
 * @brief Donn Enable min value.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_DONN_EN_MIN 0x00

/**
 * @brief Total size of firmware version registers.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_FW_VER_SIZE (REG_FW_VER_MAJ_SIZE + \
                               REG_FW_VER_MIN_SIZE + \
                               REG_FW_VER_BLD_SIZE)
/**
 * @brief Index of major firmware version.
 * @ingroup mtb_touchpad_macro
 */
#define FW_VER_MAJ_IDX    0

/**
 * @brief Index of minor firmware version.
 * @ingroup mtb_touchpad_macro
 */
#define FW_VER_MIN_IDX    1

/**
 * @brief Index of build firmware version.
 * @ingroup mtb_touchpad_macro
 */
#define FW_VER_BLD_IDX    3

/**
 * @brief Total size of coordinates and number of touch register.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_GET_POS_SIZE (REG_TCH0_POS_X_SIZE + \
                                REG_TCH0_POS_Y_SIZE + \
                                REG_TCH0_POS_Z_SIZE + \
                                REG_TCH1_POS_X_SIZE + \
                                REG_TCH1_POS_Y_SIZE + \
                                REG_TCH1_POS_Z_SIZE + \
                                REG_NUM_TOUCH_SIZE)

/**
 * @brief Index of X coordinate for touch 0.
 * @ingroup mtb_touchpad_macro
 */
#define TCH0_X_IDX 0

/**
 * @brief Index of Y coordinate for touch 0.
 * @ingroup mtb_touchpad_macro
 */
#define TCH0_Y_IDX 2

/**
 * @brief Index of Z coordinate for touch 0.
 * @ingroup mtb_touchpad_macro
 */
#define TCH0_Z_IDX 4

/**
 * @brief Index of X coordinate for touch 1.
 * @ingroup mtb_touchpad_macro
 */
#define TCH1_X_IDX 6

/**
 * @brief Index of Y coordinate for touch 1.
 * @ingroup mtb_touchpad_macro
 */
#define TCH1_Y_IDX 8

/**
 * @brief Index of Z coordinate for touch 1.
 * @ingroup mtb_touchpad_macro
 */
#define TCH1_Z_IDX 10

/**
 * @brief Index of number of touch detected.
 * @ingroup mtb_touchpad_macro
 */
#define NUM_TOUCH_IDX 12

/**
 * @brief Checks if timeout is enabled in the given scan mode.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_TIMEOUT_ENABLED(mode)   ((mode) & MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE)

/**
 * @brief Checks if timeout is disabled in the given scan mode.
 * @ingroup mtb_touchpad_macro
 */
#define MTB_TOUCHPAD_TIMEOUT_DISABLED(mode)  (!((mode) & MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE))

/** @} */

/******************************************************************************
 * Typedefs
 *****************************************************************************/

/**
 * @defgroup touchpad_enum CAPSENSE™ Touchpad I2C Host enumerated types
 * @ingroup mtb_touchpad_api
 * @brief Enumerated types for the CAPSENSE™ Touchpad I2C Host middleware.
 */

/**
 * @defgroup touchpad_structures CAPSENSE™ Touchpad I2C Host structures
 * @ingroup mtb_touchpad_api
 * @brief Data structures for the CAPSENSE™ Touchpad I2C Host middleware.
 */

/**
 * @defgroup touchpad_functions CAPSENSE™ Touchpad I2C Host functions
 * @ingroup mtb_touchpad_api
 * @brief Function prototypes for the CAPSENSE™ Touchpad I2C Host middleware.
 */

/**
 * @enum MTB_TOUCHPAD_COMMAND_t
 * @ingroup touchpad_enum
 * @brief Enum representing command for touchpad operations.
 *
 * This enum defines command used to trigger various operations
 * in the touchpad firmware.
 */

typedef enum
{
    MTB_TOUCHPAD_CMD_SOFTWARE_RESET  = 0x0001, /**< Bit 0: Trigger a software reset */
    MTB_TOUCHPAD_CMD_SAVE            = 0x0002, /**< Bit 1: Save configuration to NVM */
    MTB_TOUCHPAD_CMD_RESTORE         = 0x0004, /**< Bit 2: Restore configuration from NVM */
    MTB_TOUCHPAD_CMD_CP_TEST         = 0x0008, /**< Bit 3: Trigger parasitic capacitance test */
    MTB_TOUCHPAD_CMD_SHORT_TEST      = 0x0010, /**< Bit 4: Trigger short circuit test */
    MTB_TOUCHPAD_CMD_BOOTLOADER_JUMP = 0x0020  /**< Bit 5: Jump to bootloader */
} MTB_TOUCHPAD_COMMAND_t;


/**
 * @enum MTB_TOUCHPAD_RET_TYPE_t
 * @ingroup touchpad_enum
 * @brief Enum which represents result codes for the middleware API.
 *
 * This enum represents the result of the middleware API. Each value
 * indicates either successful operation or a specific type of error condition.
 */
typedef enum
{
    /** Operation was successful. */
    MTB_TOUCHPAD_RSLT_SUCCESS = 0,
    /** Invalid input parameter. */
    MTB_TOUCHPAD_RSLT_INVALID_PARAM = 1,
    /** Communication error */
    MTB_TOUCHPAD_RET_ERROR = 2
} MTB_TOUCHPAD_RET_TYPE_t;


/**
 * @typedef mtb_touchpad_read_handle_t
 * @ingroup touchpad_low_level_driver
 * @brief Function pointer type for touchpad read operation.
 *
 * This function pointer defines the interface for reading data from the
 * touchpad device. The implementation should handle communication with
 * the hardware (e.g., I2C) and retrieve data from the specified
 * subaddress.
 *
 * @param subaddress  Register or memory address within the touchpad device.
 * @param data        Pointer to buffer where read data will be stored.
 * @param length      Number of bytes to read.
 * @param intf_ptr    Pointer to interface-specific context or handle.
 *
 * @return Status of the read operation of type MTB_TOUCHPAD_RET_TYPE.
 */
typedef MTB_TOUCHPAD_RET_TYPE (* mtb_touchpad_read_handle_t)(
    uint16_t subaddress,
    uint8_t* data,
    uint16_t length,
    void* intf_ptr);

/**
 * @typedef mtb_touchpad_write_handle_t
 * @ingroup touchpad_low_level_driver
 * @brief Function pointer type for touchpad write operation.
 *
 * This function pointer defines the interface for writing data to the
 * touchpad device. The implementation should handle communication with
 * the hardware (e.g., I2C) and write data to the specified
 * subaddress.
 *
 * @param subaddress  Register or memory address within the touchpad device.
 * @param data        Pointer to buffer containing data to be written.
 * @param length      Number of bytes to write.
 * @param intf_ptr    Pointer to interface-specific context or handle.
 *
 * @return Status of the write operation of type MTB_TOUCHPAD_RET_TYPE.
 */
typedef MTB_TOUCHPAD_RET_TYPE (* mtb_touchpad_write_handle_t)(
    uint16_t subaddress,
    uint8_t* data,
    uint16_t length,
    void* intf_ptr);

/**
 * @enum MTB_TOUCHPAD_TEST_STATUS_t
 * @ingroup touchpad_enum
 * @brief Enum representing test status results for the touchpad.
 *
 * This enum defines the possible outcomes of various touchpad test operations.
 * Each value indicates whether the test passed, failed, or encountered a specific condition.
 */
typedef enum
{
    MTB_TOUCHPAD_TEST_SUCCESS        = 0x00, /**< Test completed successfully */
    MTB_TOUCHPAD_TEST_RESERVED       = 0x01, /**< Reserved status */
    MTB_TOUCHPAD_HW_BUSY             = 0x02, /**< Hardware is busy */
    MTB_TOUCHPAD_TEST_FAIL           = 0x05, /**< Test failed */
    MTB_TOUCHPAD_SHORT_DETECTED      = 0x0F  /**< Short circuit detected */
} MTB_TOUCHPAD_TEST_STATUS_t;


/**
 * @enum MTB_TOUCHPAD_SHIELD_EN_t
 * @ingroup touchpad_enum
 * @brief Enum representing shield enable/disable state.
 *
 * This enum controls whether the touchpad shield functionality is enabled
 * or disabled.
 */
typedef enum
{
    MTB_TOUCHPAD_SHIELD_DISABLED = 0x00, /**< Shield is disabled */
    MTB_TOUCHPAD_SHIELD_ENABLED  = 0x01  /**< Shield is enabled */
} MTB_TOUCHPAD_SHIELD_EN_t;


/**
 * @enum MTB_TOUCHPAD_SCAN_MODE_t
 * @ingroup touchpad_enum
 * @brief Enum representing scan modes of the touchpad.
 *
 * This enum defines different operational scan modes supported by the touchpad.
 */
typedef enum
{
    MTB_TOUCHPAD_SCAN_MODE_IDLE           = 0x01, /**< Idle mode */
    MTB_TOUCHPAD_SCAN_MODE_ACTIVE         = 0x02, /**< Active scanning mode */
    MTB_TOUCHPAD_SCAN_MODE_ALR            = 0x04, /**< Adaptive low refresh mode */
    MTB_TOUCHPAD_SCAN_MODE_WAKE_ON_TOUCH  = 0x08,  /**< Wake on touch mode */
    MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE   = 0x80  /**< Timeout enabled */
} MTB_TOUCHPAD_SCAN_MODE_t;

/**
 * @enum MTB_TOUCHPAD_CONFIG_STORED_t
 * @ingroup touchpad_enum
 * @brief Enum representing the storage status of touchpad configuration in NVM.
 *
 * This enum indicates whether the touchpad configuration registers
 * have been successfully stored in Non-Volatile Memory (NVM).
 */
typedef enum
{
    MTB_TOUCHPAD_REGISTER_CNFG_NOT_PRST = 0x00, /**< Configuration not present in NVM */
    MTB_TOUCHPAD_REGISTER_CNFG_STORED   = 0x01  /**< Configuration stored in NVM */
} MTB_TOUCHPAD_CONFIG_STORED_t;

/**
 * @enum MTB_TOUCHPAD_INT_SOURCE_t
 * @ingroup touchpad_enum
 * @brief Enum representing enabled interrupt sources.
 *
 * This enum defines the interrupt sources that can be enabled
 * in the touchpad firmware.
 */
typedef enum
{
    MTB_TOUCHPAD_INT_SCAN_FRAME_RESULT_READY    = 0x01, /**< Bit 0: Scan Frame Result Ready interrupt source */
    MTB_TOUCHPAD_INT_TOUCH_DETECTED             = 0x02, /**< Bit 1: Touch Detected interrupt source */
    MTB_TOUCHPAD_INT_TEST_RESULT_READY          = 0x04, /**< Bit 2: Test Result Ready interrupt source */
    MTB_TOUCHPAD_INT_SENSING_APP_RUNNING        = 0x08, /**< Bit 3: Sensing App Running interrupt source */
    MTB_TOUCHPAD_INT_GESTURE_DETECTED           = 0x10, /**< Bit 4: Gesture Detected interrupt source */
    MTB_TOUCHPAD_INT_LIFTOFF_TOUCHDOWN_DETECTED = 0x20, /**< Bit 5: Liftoff/Touchdown Detected interrupt source */
    MTB_TOUCHPAD_INT_USER_DATA_READY            = 0x40, /**< Bit 6: User Data Ready interrupt source */
    MTB_TOUCHPAD_INT_APPLICATION_ERROR          = 0x80  /**< Bit 7: Application Error interrupt source */
} MTB_TOUCHPAD_INT_SOURCE_t;


/**
 * @enum MTB_TOUCHPAD_INT_STATUS_t
 * @ingroup touchpad_enum
 * @brief Enum representing pending interrupt status.
 *
 * This enum defines the current status of pending interrupts.
 * Write '0' to the associated bit to clear the pending interrupt.
 */
typedef enum
{
    MTB_TOUCHPAD_INT_STATUS_NONE                        = 0x00, /**< No pending interrupts */
    MTB_TOUCHPAD_INT_STATUS_SCAN_COMPLETE               = 0x01, /**< Bit 0: Scan-Complete pending interrupt */
    MTB_TOUCHPAD_INT_STATUS_TOUCH_DETECTED              = 0x02, /**< Bit 1: Touch Detected pending interrupt */
    MTB_TOUCHPAD_INT_STATUS_TEST_RESULT_READY           = 0x04, /**< Bit 2: Test Result Ready pending interrupt */
    MTB_TOUCHPAD_INT_STATUS_SENSING_APP_RUNNING         = 0x08, /**< Bit 3: Sensing App Running pending interrupt */
    MTB_TOUCHPAD_INT_STATUS_GESTURE_DETECTED            = 0x10, /**< Bit 4: Gesture Detected pending interrupt */
    MTB_TOUCHPAD_INT_STATUS_LIFTOFF_TOUCHDOWN_DETECTED  = 0x20, /**< Bit 5: Liftoff/Touchdown Detected pending interrupt
                                                                 */
    MTB_TOUCHPAD_INT_STATUS_USER_DATA_READY             = 0x40, /**< Bit 6: User Data Ready pending interrupt */
    MTB_TOUCHPAD_INT_STATUS_APPLICATION_ERROR           = 0x80  /**< Bit 7: Application Error pending interrupt */
} MTB_TOUCHPAD_INT_STATUS_t;


/**
 * @enum MTB_TOUCHPAD_ERROR_STATUS_t
 * @ingroup touchpad_enum
 * @brief Enum representing error status.
 *
 * This enum defines the current status of any errors that are
 * not otherwise covered by other registers.
 */
typedef enum
{
    MTB_TOUCHPAD_ERROR_STATUS_NONE                = 0x00, /**< No errors */
    MTB_TOUCHPAD_ERROR_STATUS_INVALID_PARAM       = 0x01, /**< Bit 0: Requested parameter is invalid */
    MTB_TOUCHPAD_ERROR_STATUS_I2C_TIMEOUT         = 0x02, /**< Bit 1: I2C Timeout Expired */
    MTB_TOUCHPAD_ERROR_STATUS_CAPSENSE_CALIB_FAIL = 0x04  /**< Bit 2: CAPSENSE Auto-Calibration Failed */
} MTB_TOUCHPAD_ERROR_STATUS_t;


/**
 * @enum MTB_TOUCHPAD_RESET_CAUSE_t
 * @ingroup touchpad_enum
 * @brief Enum representing the cause of the latest reset.
 *
 * This enum defines the possible causes of the latest reset.
 * Automatically updated after any reset.
 */
typedef enum
{
    MTB_TOUCHPAD_RESET_CAUSE_VOLTAGE          = 0x00, /**< Voltage reset (XRES, BOD, or Normal POR) */
    MTB_TOUCHPAD_RESET_CAUSE_WDT              = 0x01, /**< Bit 0: WDT reset */
    MTB_TOUCHPAD_RESET_CAUSE_PROTECTION_FAULT = 0x08, /**< Bit 3: Protection Fault reset */
    MTB_TOUCHPAD_RESET_CAUSE_SOFTWARE         = 0x10  /**< Bit 4: Software reset */
} MTB_TOUCHPAD_RESET_CAUSE_t;


/**
 * @enum MTB_TOUCHPAD_FILTER_t
 * @ingroup touchpad_enum
 * @brief Enum representing CAPSENSE raw count filters.
 *
 * This enum defines the filters applied to the CAPSENSE raw counts.
 * SW IIR filter is not applied if coefficient (bits 8-15) is 0.
 */
typedef enum
{
    MTB_TOUCHPAD_FILTER_NONE                    = 0x0000, /**< No filter applied */
    MTB_TOUCHPAD_FILTER_MEDIAN                  = 0x0001, /**< Bit 0: Median filter enable */
    MTB_TOUCHPAD_FILTER_AVERAGE                 = 0x0002, /**< Bit 1: Average filter enable */
    MTB_TOUCHPAD_FILTER_IIR                     = 0x0004, /**< Bit 2: IIR filter enable */
    MTB_TOUCHPAD_FILTER_SW_IIR_COEFF_MASK       = 0xFF00  /**< Bits 8-15: SW IIR coefficient mask */
} MTB_TOUCHPAD_FILTER_t;


/**
 * @enum MTB_TOUCHPAD_GESTURE_STATUS_t
 * @ingroup touchpad_enum
 * @brief Enum representing gesture status bits.
 *
 * This enum defines the gesture status bits used to identify
 * the type of gesture detected by the touchpad firmware.
 */
typedef enum
{
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_SINGLE_CLICK    = 0x00000001, /**< Bit 0:  One-finger single click gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_DOUBLE_CLICK    = 0x00000002, /**< Bit 1:  One-finger double click gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_CLICK_DRAG      = 0x00000004, /**< Bit 2:  One-finger click and drag gesture */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_SINGLE_CLICK    = 0x00000008, /**< Bit 3:  Two-finger single click gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_SCROLL          = 0x00000010, /**< Bit 4:  One-finger scroll gesture */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_SCROLL          = 0x00000020, /**< Bit 5:  Two-finger scroll gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_EDGE_SWIPE      = 0x00000040, /**< Bit 6:  One-finger edge swipe gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_FLICK           = 0x00000080, /**< Bit 7:  One-finger flick gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_ROTATE          = 0x00000100, /**< Bit 8:  One-finger rotate gesture */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_ZOOM            = 0x00000200, /**< Bit 9:  Two-finger zoom gesture */
    MTB_TOUCHPAD_GESTURE_LONG_PRESS                 = 0x00000400, /**< Bit 10: Long-press (Press and hold) gesture */
    MTB_TOUCHPAD_GESTURE_ONE_FINGER_TRIPLE_CLICK    = 0x00000800, /**< Bit 11: One-finger triple click (Unused) */
    MTB_TOUCHPAD_GESTURE_RESERVED_BIT12             = 0x00001000, /**< Bit 12: Reserved */
    MTB_TOUCHPAD_GESTURE_TOUCHDOWN                  = 0x00002000, /**< Bit 13: Touchdown event */
    MTB_TOUCHPAD_GESTURE_LIFTOFF                    = 0x00004000, /**< Bit 14: Liftoff event */
    MTB_TOUCHPAD_GESTURE_FILTERING                  = 0x00008000, /**< Bit 15: Gesture filtering enabled or disabled */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_DOUBLE_CLICK    = 0x00010000, /**< Bit 16: Two-finger double click (Unused) */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_LONG_PRESS      = 0x00020000, /**< Bit 17: Two-finger long press (Unused) */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_FLICK           = 0x00040000, /**< Bit 18: Two-finger flick (Unused) */
    MTB_TOUCHPAD_GESTURE_TWO_FINGER_EDGE_SWIPE      = 0x00080000  /**< Bit 19: Two-finger edge swipe (Unused) */
} MTB_TOUCHPAD_GESTURE_STATUS_t;


/**
 * @enum MTB_TOUCHPAD_GESTURE_DIR_t
 * @ingroup touchpad_enum
 * @brief Enum representing gesture direction fields.
 *
 * Each field group provides a POS (bit position), MASK, and pre-shifted
 * direction values. To check a direction, mask the raw value then compare
 * directly to the corresponding direction constant.
 *
 * Example (rotate):
 *   if ((dir & MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_ROTATE_MASK) ==
 *             MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_ROTATE_CCW) { ... }
 */
typedef enum
{
    /* One-finger scroll direction (bits 0..1) */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_SCROLL_POS           = 0x00000000, /**< Bits 0..1:   One-finger scroll bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_SCROLL_MASK          = 0x00000003, /**< Bits 0..1:   One-finger scroll mask */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_SCROLL_UP            = 0x00000000, /**< Bits 0..1:   One-finger scroll: Up */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_SCROLL_DOWN          = 0x00000001, /**< Bits 0..1:   One-finger scroll: Down */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_SCROLL_RIGHT         = 0x00000002, /**< Bits 0..1:   One-finger scroll: Right */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_SCROLL_LEFT          = 0x00000003, /**< Bits 0..1:   One-finger scroll: Left */

    /* Two-finger scroll direction (bits 2..3) */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_SCROLL_POS           = 0x00000002, /**< Bits 2..3:   Two-finger scroll bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_SCROLL_MASK          = 0x0000000C, /**< Bits 2..3:   Two-finger scroll mask */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_SCROLL_UP            = 0x00000000, /**< Bits 2..3:   Two-finger scroll: Up */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_SCROLL_DOWN          = 0x00000004, /**< Bits 2..3:   Two-finger scroll: Down */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_SCROLL_RIGHT         = 0x00000008, /**< Bits 2..3:   Two-finger scroll: Right */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_SCROLL_LEFT          = 0x0000000C, /**< Bits 2..3:   Two-finger scroll: Left */

    /* One-finger edge swipe direction (bits 4..5) */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_EDGE_SWIPE_POS       = 0x00000004, /**< Bits 4..5:   One-finger edge swipe bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_EDGE_SWIPE_MASK      = 0x00000030, /**< Bits 4..5:   One-finger edge swipe mask
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_EDGE_SWIPE_UP        = 0x00000000, /**< Bits 4..5:   One-finger edge swipe: Up
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_EDGE_SWIPE_DOWN      = 0x00000010, /**< Bits 4..5:   One-finger edge swipe: Down
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_EDGE_SWIPE_RIGHT     = 0x00000020, /**< Bits 4..5:   One-finger edge swipe:
                                                                              Right
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_EDGE_SWIPE_LEFT      = 0x00000030, /**< Bits 4..5:   One-finger edge swipe: Left
                                                                            */

    /* One-finger rotate direction (bit 6) */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_ROTATE_POS           = 0x00000006, /**< Bit  6:      One-finger rotate bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_ROTATE_MASK          = 0x00000040, /**< Bit  6:      One-finger rotate mask */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_ROTATE_CW            = 0x00000000, /**< Bit  6:      One-finger rotate:
                                                                              Clockwise
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_ROTATE_CCW           = 0x00000040, /**< Bit  6:      One-finger rotate:
                                                                              Counter-clockwise */

    /* Two-finger zoom direction (bit 7) */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_ZOOM_POS             = 0x00000007, /**< Bit  7:      Two-finger zoom bit
                                                                              position
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_ZOOM_MASK            = 0x00000080, /**< Bit  7:      Two-finger zoom mask */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_ZOOM_IN              = 0x00000000, /**< Bit  7:      Two-finger zoom: Zoom-in */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_ZOOM_OUT             = 0x00000080, /**< Bit  7:      Two-finger zoom: Zoom-out
                                                                            */

    /* One-finger flick direction (bits 8..10) */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_POS            = 0x00000008, /**< Bits 8..10:  One-finger flick bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_MASK           = 0x00000700, /**< Bits 8..10:  One-finger flick mask */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_UP             = 0x00000000, /**< Bits 8..10:  One-finger flick: Up */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_DOWN           = 0x00000100, /**< Bits 8..10:  One-finger flick: Down */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_RIGHT          = 0x00000200, /**< Bits 8..10:  One-finger flick: Right */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_LEFT           = 0x00000300, /**< Bits 8..10:  One-finger flick: Left */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_UP_RIGHT       = 0x00000400, /**< Bits 8..10:  One-finger flick: Up-right
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_DOWN_LEFT      = 0x00000500, /**< Bits 8..10:  One-finger flick: Down-left
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_DOWN_RIGHT     = 0x00000600, /**< Bits 8..10:  One-finger flick:
                                                                              Down-right
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_ONE_FINGER_FLICK_UP_LEFT        = 0x00000700, /**< Bits 8..10:  One-finger flick: Up-left
                                                                            */

    /* Two-finger edge swipe direction (bits 11..12) */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_EDGE_SWIPE_POS       = 0x0000000B, /**< Bits 11..12: Two-finger edge swipe bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_EDGE_SWIPE_MASK      = 0x00001800, /**< Bits 11..12: Two-finger edge swipe mask
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_EDGE_SWIPE_UP        = 0x00000000, /**< Bits 11..12: Two-finger edge swipe: Up
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_EDGE_SWIPE_DOWN      = 0x00000800, /**< Bits 11..12: Two-finger edge swipe: Down
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_EDGE_SWIPE_RIGHT     = 0x00001000, /**< Bits 11..12: Two-finger edge swipe:
                                                                              Right
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_EDGE_SWIPE_LEFT      = 0x00001800, /**< Bits 11..12: Two-finger edge swipe: Left
                                                                            */

    /* Two-finger flick direction (bits 13..15) */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_POS            = 0x0000000D, /**< Bits 13..15: Two-finger flick bit
                                                                              position */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_MASK           = 0x0000E000, /**< Bits 13..15: Two-finger flick mask */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_UP             = 0x00000000, /**< Bits 13..15: Two-finger flick: Up */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_DOWN           = 0x00002000, /**< Bits 13..15: Two-finger flick: Down */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_RIGHT          = 0x00004000, /**< Bits 13..15: Two-finger flick: Right */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_LEFT           = 0x00006000, /**< Bits 13..15: Two-finger flick: Left */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_UP_RIGHT       = 0x00008000, /**< Bits 13..15: Two-finger flick: Up-right
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_DOWN_LEFT      = 0x0000A000, /**< Bits 13..15: Two-finger flick: Down-left
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_DOWN_RIGHT     = 0x0000C000, /**< Bits 13..15: Two-finger flick:
                                                                              Down-right
                                                                            */
    MTB_TOUCHPAD_GESTURE_DIR_TWO_FINGER_FLICK_UP_LEFT        = 0x0000E000  /**< Bits 13..15: Two-finger flick: Up-left
                                                                            */
} MTB_TOUCHPAD_GESTURE_DIR_t;

/**
 * @enum MTB_TOUCHPAD_SHORT_TEST_IO_t
 * @ingroup touchpad_enum
 * @brief Enum representing IO IDs with a short circuit detected.
 *
 * This enum defines the IO IDs that indicate a short circuit when
 * TEST_STATUS = 0x0F. Each bit corresponds to a specific IO pin.
 */
typedef enum
{
    MTB_TOUCHPAD_SHORT_TEST_IO_D1 = 0x00000001, /**< Bit 0:  Short detected on IO D1 */
    MTB_TOUCHPAD_SHORT_TEST_IO_C3 = 0x00000002, /**< Bit 1:  Short detected on IO C3 */
    MTB_TOUCHPAD_SHORT_TEST_IO_C2 = 0x00000004, /**< Bit 2:  Short detected on IO C2 */
    MTB_TOUCHPAD_SHORT_TEST_IO_C1 = 0x00000008, /**< Bit 3:  Short detected on IO C1 */
    MTB_TOUCHPAD_SHORT_TEST_IO_B1 = 0x00000010, /**< Bit 4:  Short detected on IO B1 */
    MTB_TOUCHPAD_SHORT_TEST_IO_B2 = 0x00000020, /**< Bit 5:  Short detected on IO B2 */
    MTB_TOUCHPAD_SHORT_TEST_IO_A4 = 0x00000040, /**< Bit 6:  Short detected on IO A4 */
    MTB_TOUCHPAD_SHORT_TEST_IO_B4 = 0x00000080, /**< Bit 7:  Short detected on IO B4 */
    MTB_TOUCHPAD_SHORT_TEST_IO_A5 = 0x00000100, /**< Bit 8:  Short detected on IO A5 */
    MTB_TOUCHPAD_SHORT_TEST_IO_B5 = 0x00000200, /**< Bit 9:  Short detected on IO B5 */
    MTB_TOUCHPAD_SHORT_TEST_IO_C5 = 0x00000400, /**< Bit 10: Short detected on IO C5 */
    MTB_TOUCHPAD_SHORT_TEST_IO_C4 = 0x00000800, /**< Bit 11: Short detected on IO C4 */
    MTB_TOUCHPAD_SHORT_TEST_IO_D5 = 0x00001000, /**< Bit 12: Short detected on IO D5 */
    MTB_TOUCHPAD_SHORT_TEST_IO_E5 = 0x00002000, /**< Bit 13: Short detected on IO E5 */
    MTB_TOUCHPAD_SHORT_TEST_IO_D4 = 0x00004000, /**< Bit 14: Short detected on IO D4 */
    MTB_TOUCHPAD_SHORT_TEST_IO_E4 = 0x00008000, /**< Bit 15: Short detected on IO E4 */
    MTB_TOUCHPAD_SHORT_TEST_IO_D3 = 0x00010000, /**< Bit 16: Short detected on IO D3 */
    MTB_TOUCHPAD_SHORT_TEST_IO_E3 = 0x00020000, /**< Bit 17: Short detected on IO E3 */
    MTB_TOUCHPAD_SHORT_TEST_IO_D2 = 0x00040000, /**< Bit 18: Short detected on IO D2 */
    MTB_TOUCHPAD_SHORT_TEST_IO_E2 = 0x00080000, /**< Bit 19: Short detected on IO E2 */
    MTB_TOUCHPAD_SHORT_TEST_IO_E1 = 0x00100000  /**< Bit 20: Short detected on IO E1 */
} MTB_TOUCHPAD_SHORT_TEST_IO_t;

/******************************************************************************
* Structures
******************************************************************************/
/**
 * @struct mtb_touchpad_intf_context_t
 * @ingroup touchpad_structures
 * @brief Structure for touchpad interface context.
 *
 * This structure contains function pointers for platform-specific
 * read/write operations along with interface context and configuration
 * details required to communicate with the touchpad device.
 *
 * @var mtb_touchpad_intf_context_t::bus_read
 *   Function pointer to platform-specific read operation.
 * @var mtb_touchpad_intf_context_t::bus_write
 *   Function pointer to platform-specific write operation.
 * @var mtb_touchpad_intf_context_t::intf_ptr
 *   Pointer to interface-specific descriptor (e.g., slave address, bus handle).
 * @var mtb_touchpad_intf_context_t::num_sensors
 *   Number of sensors configured in the CapSense configurator.
 */
typedef struct
{
    mtb_touchpad_read_handle_t bus_read;   /**< Function pointer for read operation */
    mtb_touchpad_write_handle_t bus_write; /**< Function pointer for write operation */
    void* intf_ptr;                       /**< Interface-specific context pointer */
    uint8_t num_sensors;                  /**< Number of sensors */
} mtb_touchpad_intf_context_t;


/**
 * @struct mtb_touchpad_fw_ver_t
 * @ingroup touchpad_structures
 * @brief Structure for touchpad firmware version information.
 *
 * This structure holds the firmware version details of the touchpad device.
 *
 * @var mtb_touchpad_fw_ver_t::major
 *   Indicates the major revision of the firmware.
 * @var mtb_touchpad_fw_ver_t::minor
 *   Indicates the minor revision of the firmware.
 * @var mtb_touchpad_fw_ver_t::build
 *   Indicates the build revision of the firmware.
 */
typedef struct
{
    uint8_t major;   /**< Major firmware version number. */
    uint16_t minor;  /**< Minor firmware version number. */
    uint16_t build;  /**< Build firmware version number. */
} mtb_touchpad_fw_ver_t;


/**
 * @struct mtb_touchpad_coordinates
 * @ingroup touchpad_structures
 * @brief Structure representing touch coordinates.
 *
 * This structure stores the X, Y, and Z coordinates of a touch point.
 *
 * @var mtb_touchpad_coordinates::x
 *   X coordinate of the touch.
 * @var mtb_touchpad_coordinates::y
 *   Y coordinate of the touch.
 * @var mtb_touchpad_coordinates::z
 *   Z coordinate value of the touch.
 */
typedef struct
{
    uint16_t x; /**< X coordinate */
    uint16_t y; /**< Y coordinate */
    uint16_t z; /**< Z coordinate */
} mtb_touchpad_coordinates;


/**
 * @struct mtb_touchpad_pos_t
 * @ingroup touchpad_structures
 * @brief Structure representing touchpad position data.
 *
 * This structure contains coordinates for up to two touch points
 * along with the number of active touches detected.
 *
 * @var mtb_touchpad_pos_t::tch0
 *   Coordinates of the first touch point.
 * @var mtb_touchpad_pos_t::tch1
 *   Coordinates of the second touch point.
 * @var mtb_touchpad_pos_t::num_touch
 *   Number of touches currently detected.
 */
typedef struct
{
    mtb_touchpad_coordinates tch0; /**< First touch coordinates */
    mtb_touchpad_coordinates tch1; /**< Second touch coordinates */
    uint8_t num_touch;            /**< Number of touches detected */
} mtb_touchpad_pos_t;


/*******************************************************************************
* Function Prototypes
*******************************************************************************/
/**
 * \brief Initializes the touchpad interface.
 *
 * This function initializes CAPSENSE™ Touchpad I2C Host with platform-specific
 * read and write handlers along with the interface context. It sets up
 * the communication layer (e.g., I2C) required for interacting with
 * the touchpad device and stores the configuration in the provided
 * context structure.
 *
 * \param[in] bus_write   : Function pointer to platform-specific write operation.
 * \param[in] bus_read    : Function pointer to platform-specific read operation.
 * \param[in] intf_ptr    : Pointer to interface-specific context (e.g., I2C address, bus handle).
 * \param[out] context    : Pointer to touchpad interface context structure to be initialized.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Initialization successful
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The function pointers (bus_read and bus_write) must be valid and
 *       implemented before calling this function.
 * \note The context structure must be allocated by the caller.
 * \note This function must be called before performing any touchpad read/write operations.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_init(
    mtb_touchpad_write_handle_t bus_write,
    mtb_touchpad_read_handle_t bus_read,
    void* intf_ptr,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the firmware version of the touchpad device.
 *
 * This function reads the firmware version information from the touchpad
 * device and populates the provided version structure. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] ver      : Pointer to structure where firmware version will be stored.
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Firmware version retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'ver' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_fw_ver(
    mtb_touchpad_fw_ver_t* ver,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the reset cause of the touchpad device.
 *
 * This function reads the reset cause register from the touchpad device
 * and provides information about the reason for the last reset event
 * (e.g., watchdog reset, software reset, protection fault, voltage reset).
 *
 * \param[out] rst_cause : Pointer to variable where reset cause will be stored.
 * \param[in] context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Reset cause retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The rst_cause pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_reset_cause(
    uint8_t* rst_cause,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sends a command to the touchpad device.
 *
 * This function writes the specified command to the touchpad device using
 * the interface defined in the context. It is typically used to trigger
 * specific operations such as reset, configuration updates, load configuration, short test, and bootloader jump.
 *
 * \param[in] cmd       : Command value to be sent to the touchpad device.
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Command sent successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The command value must be valid as per device specification.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_cmd(
    uint16_t cmd,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Performs a software reset of the touchpad device.
 *
 * This function issues a software reset command to the touchpad device.
 *
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Reset command executed successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note A delay may be required after reset before issuing further commands.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_sw_reset(mtb_touchpad_intf_context_t* context);

/**
 * \brief Saves current configuration to non-volatile memory (NVM).
 *
 * This function stores the current touchpad configuration into the device's
 * non-volatile memory so that the settings are retained across resets or
 * power cycles.
 *
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Configuration saved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note Ensure that no other operations are in progress during NVM write.
 * \note Writing to NVM may take additional time; avoid issuing commands immediately after.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_save_nvm(mtb_touchpad_intf_context_t* context);

/**
 * \brief Loads configuration from non-volatile memory (NVM).
 *
 * This function reads the stored configuration from the touchpad device's
 * non-volatile memory and applies it to the active configuration. It is
 * typically used after reset or power-up to restore previously saved settings.
 *
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Configuration loaded successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note Ensure the device is ready before invoking this function after reset.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_load_nvm(mtb_touchpad_intf_context_t* context);

/**
 * \brief Executes capacitive self-test on the touchpad device.
 *
 * This function triggers a capacitive test routine on the touchpad device
 * to evaluate the health and functionality of the sensor elements. The
 * results of the test may be used for diagnostics or calibration purposes.
 *
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Test executed successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note Ensure no touch activity or other operations are in progress during the test.
 * \note Additional APIs may be required to retrieve detailed test results.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_run_cap_test(mtb_touchpad_intf_context_t* context);

/**
 * \brief Executes short-circuit self-test on the touchpad device.
 *
 * This function triggers a short test routine on the touchpad device
 * to detect potential short circuits between sensor electrodes or lines.
 * The test helps ensure the integrity of the touch sensing hardware.
 *
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Test executed successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note Ensure no touch activity or other operations are in progress during the test.
 * \note Additional APIs may be required to retrieve detailed test results.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_run_short_test(mtb_touchpad_intf_context_t* context);

/**
 * \brief Switches the touchpad device to bootloader mode.
 *
 * This function issues a command to the touchpad device to jump from
 * application firmware to bootloader mode. This is typically used for
 * firmware update operations.
 *
 * \param[in] context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Bootloader jump command sent successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note After this call, the device will no longer respond to normal application commands.
 * \note A firmware update procedure should be initiated after entering bootloader mode.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_bootloader_jump(mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the test status from the touchpad controller.
 *
 * This function reads the TEST_STATUS register from the touchpad controller
 * and stores the result in the provided pointer. The communication with the
 * device is performed using the interface defined in the context.
 *
 * \param[out] test_status  : Pointer to store the retrieved test status value.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Test status retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'test_status' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_test_status(
    MTB_TOUCHPAD_TEST_STATUS_t* test_status,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the shorted sensor pin IDs from the touchpad controller.
 *
 * This function reads the SHORTED_SNS_ID register from the touchpad controller
 * and stores the pin ID in the provided pointer. This is typically used
 * after running a short test to identify which sensor pins are shorted.
 *
 * \param[out] pin_ids  : Pointer to store the 32-bit shorted pin ID.
 * \param[in]  context  : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Short pin IDs retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'pin_ids' pointer must be a valid, non-NULL pointer.
 * \note Run mtb_touchpad_run_short_test() before calling this function for valid results.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_short_pin_ids(
    uint32_t* pin_ids,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the interrupt source enable mask for the touchpad controller.
 *
 * This function writes the interrupt source enable configuration to the touchpad
 * controller, allowing the caller to enable or disable specific interrupt sources
 * as defined by the src_en parameter. This controls which events will trigger an
 * interrupt from the touchpad hardware.
 *
 * \param[in]  src_en   : Interrupt sources to enable.
 * \param[in]  context  : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Interrupt source enable mask set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_int_src_en(
    uint8_t src_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the interrupt source enable register from the touchpad controller.
 *
 * This function reads the INT_SRC_EN register from the touchpad controller
 * and stores the enabled interrupt source flag in the provided pointer. The
 * communication with the device is performed using the interface defined in the context.
 *
 * \param[out] src_en   : Pointer to store the interrupt source enable flag.
 * \param[in]  context  : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Interrupt source enable flag retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'src_en' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_int_src_en(
    uint8_t* src_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the interrupt status register of the touchpad controller.
 *
 * This function writes the interrupt status value to the touchpad controller's
 * interrupt status register. This is typically used to clear or acknowledge
 * specific interrupt status flag after they have been serviced by the host.
 *
 * \param[in]  int_status : Interrupt status flag to write.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Interrupt status set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_int_status(
    uint8_t int_status,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the interrupt status from the touchpad controller.
 *
 * This function reads the INT_STATUS register from the touchpad controller
 * and stores the interrupt status flag in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] int_status  : Pointer to store the interrupt status flag.
 * \param[in]  context     : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Interrupt status retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'int_status' pointer must be a valid, non-NULL pointer.
 * \note Use mtb_touchpad_clear_all_int_status() to clear flag after processing.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_int_status(
    uint8_t* int_status,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Clears all interrupt status flag on the touchpad controller.
 *
 * This function writes to the INT_STATUS register of the touchpad controller
 * to clear all pending interrupt status flag. The communication with the
 * device is performed using the interface defined in the context.
 *
 * \param[in] context  : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Interrupt status cleared successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 * \note Call this function after processing interrupts to re-arm the interrupt line.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_clear_all_int_status(mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the error status from the touchpad controller.
 *
 * This function reads the ERROR_STATUS register from the touchpad controller
 * and stores the error flag in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] error_status  : Pointer to store the error status flag.
 * \param[in]  context       : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Error status retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'error_status' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_error_status(
    uint8_t* error_status,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the current scan mode of the touchpad controller.
 *
 * This function updates the base scan mode bits (IDLE, ACTIVE, or IDLE | ACTIVE)
 * of the SCAN_MODE register of the touchpad controller. It first reads back the
 * current register value so that the timeout-enable bit is preserved, then writes
 * only the requested base scan mode combined with that preserved bit. Use
 * mtb_touchpad_set_mode_timeout_en() to change the timeout-enable bit. The
 * communication with the device is performed using the interface defined in the
 * context.
 *
 * \param[in] scan_mode  : The scan mode value to set. Only MTB_TOUCHPAD_SCAN_MODE_IDLE
 *                         and/or MTB_TOUCHPAD_SCAN_MODE_ACTIVE bits may be set
 *                         (i.e. 'scan_mode' must be in the range 0x01 - 0x03).
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Scan mode set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read/write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 * \note Any bit outside MTB_TOUCHPAD_SCAN_MODE_IDLE | MTB_TOUCHPAD_SCAN_MODE_ACTIVE (0x03),
 *       including MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE, makes 'scan_mode' invalid.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_scan_mode(
    MTB_TOUCHPAD_SCAN_MODE_t scan_mode,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the current scan mode from the touchpad controller.
 *
 * This function reads the SCAN_MODE register from the touchpad controller
 * and stores the active scan mode in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] scan_mode  : Pointer to store the current scan mode value.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Scan mode retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'scan_mode' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_scan_mode(
    MTB_TOUCHPAD_SCAN_MODE_t* scan_mode,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the mode timeout enable flag for the touchpad controller.
 *
 * This function writes the mode timeout enable flag to the SCAN_MODE register of the touchpad controller.
 * The communication with the device is performed using the interface defined in the context.
 *
 * \param[in] mode_timeout_en : The mode timeout enable flag value to set.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Mode timeout enable flag set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_mode_timeout_en(
    uint8_t mode_timeout_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the current mode timeout enable flag from the touchpad controller.
 *
 * This function reads the mode timeout enable flag from the SCAN_MODE register of the touchpad controller.
 * The communication with the device is performed using the interface defined in the context.
 *
 * \param[out] mode_timeout_en : Pointer to store the current mode timeout enable flag value.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Mode timeout enable flag retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'mode_timeout_en' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_mode_timeout_en(
    uint8_t* mode_timeout_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the shield enable configuration of the touchpad controller.
 *
 * This function writes the shield enable configuration to the touchpad
 * controller, allowing the caller to enable or disable the shield electrode
 * functionality. The shield electrode is used to reduce the effect of
 * environmental noise and improve touch sensing accuracy.
 *
 * \param[in]  shield_en : Enumeration value specifying the shield enable state.
 *                         Refer to MTB_TOUCHPAD_SHIELD_EN_t for valid values.
 * \param[in]  context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Shield enable configuration set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_shield_en(
    MTB_TOUCHPAD_SHIELD_EN_t shield_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the shield enable status from the touchpad controller.
 *
 * This function reads the SHIELD_EN register from the touchpad controller
 * and stores the enable/disable status in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] shield_en  : Pointer to store the shield enable status value.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Shield enable status retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'shield_en' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_shield_en(
    MTB_TOUCHPAD_SHIELD_EN_t* shield_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the sensor filter configuration of the touchpad controller.
 *
 * This function writes the sensor filter configuration value to the touchpad
 * controller, allowing the caller to configure the filtering parameters applied
 * to raw sensor data. The filter configuration controls noise reduction and
 * signal smoothing behavior, directly affecting touch detection accuracy
 * and response time.
 *
 * \param[in]  sns_filt_cfg : 16-bit value specifying the sensor filter configuration.
 *                            Refer to the touchpad controller datasheet for valid
 *                            filter configurations.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Sensor filter configuration set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_sns_filt_cfg(
    uint16_t sns_filt_cfg,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the sensor filter configuration from the touchpad controller.
 *
 * This function reads the SNS_FILT_CFG register from the touchpad controller
 * and stores the 16-bit configuration value in the provided pointer. The
 * communication with the device is performed using the interface defined in the context.
 *
 * \param[out] sns_filt_cfg : Pointer to store the sensor filter configuration value.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Sensor filter configuration retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'sns_filt_cfg' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_filt_cfg(
    uint16_t* sns_filt_cfg,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the active mode refresh rate of the touchpad controller.
 *
 * This function writes the refresh rate configuration to the touchpad controller
 * for active operating mode, defining how frequently the touchpad scans and
 * updates sensor data. A higher refresh rate provides faster touch response
 * but increases power consumption, while a lower refresh rate conserves power
 * at the expense of touch responsiveness.
 *
 * \param[in]  refresh_rate : 8-bit value specifying the active mode refresh rate.
 *                            Refer to the touchpad controller datasheet for valid
 *                            refresh rate values and their corresponding scan intervals.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Active refresh rate set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 * \note This function configures the refresh rate only for active mode.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_active_refresh_rate(
    uint8_t refresh_rate,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the active mode refresh rate from the touchpad controller.
 *
 * This function reads the active mode refresh rate register from the touchpad
 * controller and stores the rate value in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] refresh_rate  : Pointer to store the active mode refresh rate value.
 * \param[in]  context       : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Active refresh rate retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'refresh_rate' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_active_refresh_rate(
    uint8_t* refresh_rate,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the Active mode timeout of the touchpad controller.
 *
 * This function configures the timeout, in milliseconds, before the touchpad
 * controller transitions from Active mode to Active Low Refresh (ALR) mode
 * when timeout-based power management is enabled.
 *
 * Writing a value of 0 disables Active mode.
 *
 * \param[in] timeout : 32-bit timeout value in milliseconds.
 *                      Refer to the touchpad controller datasheet for the
 *                      supported range of timeout values.
 * \param[in] context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Active mode timeout set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 * \note A timeout value of 0 disables Active mode.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_mode_timeout_act(
    uint32_t timeout,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the Active mode timeout from the touchpad controller.
 *
 * This function reads the timeout value, in milliseconds, that controls the
 * transition from Active mode to Active Low Refresh (ALR) mode when
 * timeout-based power management is enabled, and stores the value in the
 * provided pointer.
 *
 * A returned value of 0 indicates that Active mode is disabled.
 *
 * \param[out] timeout : Pointer to store the 32-bit Active mode timeout value
 *                       in milliseconds.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Active mode timeout retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'timeout' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_mode_timeout_act(
    uint32_t* timeout,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the active low refresh rate (ALR) mode refresh rate of the touchpad controller.
 *
 * This function writes the refresh rate configuration to the touchpad controller
 * for active low refresh rate (ALR) operating mode, defining how frequently the
 * touchpad scans and updates sensor data when the system is in a reduced activity
 * state. The ALR mode provides a balance between touch responsiveness and power
 * consumption during periods of low user interaction.
 *
 * \param[in]  refresh_rate : 8-bit value specifying the ALR mode refresh rate.
 *                            Refer to the touchpad controller datasheet for valid
 *                            refresh rate values and their corresponding scan intervals.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - ALR mode refresh rate set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 * \note This function configures the refresh rate only for ALR mode.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_alr_refresh_rate(
    uint8_t refresh_rate,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the active low refresh rate (ALR) mode refresh rate from the touchpad controller.
 *
 * This function reads the ALR mode refresh rate register from the touchpad
 * controller and stores the rate value in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] refresh_rate  : Pointer to store the ALR mode refresh rate value.
 * \param[in]  context       : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - ALR refresh rate retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'refresh_rate' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_alr_refresh_rate(
    uint8_t* refresh_rate,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Sets the Active Low Refresh (ALR) mode timeout of the touchpad controller.
 *
 * This function configures the timeout, in milliseconds, before the touchpad
 * controller transitions from Active Low Refresh (ALR) mode to Wake-on-Touch
 * (WoT) mode when timeout-based power management is enabled.
 *
 * Writing a value of 0 disables ALR mode.
 *
 * \param[in] timeout : 32-bit timeout value in milliseconds.
 *                      Refer to the touchpad controller datasheet for the
 *                      supported range of timeout values.
 * \param[in] context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - ALR mode timeout set successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'context' pointer must be a valid, non-NULL pointer.
 * \note A timeout value of 0 disables ALR mode.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_mode_timeout_alr(
    uint32_t timeout,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the Active Low Refresh (ALR) mode timeout from the touchpad controller.
 *
 * This function reads the timeout value, in milliseconds, that controls the
 * transition from Active Low Refresh (ALR) mode to Wake-on-Touch (WoT) mode
 * when timeout-based power management is enabled, and stores the value in the
 * provided pointer.
 *
 * A returned value of 0 indicates that ALR mode is disabled.
 *
 * \param[out] timeout : Pointer to store the 32-bit ALR mode timeout value
 *                       in milliseconds.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - ALR mode timeout retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'timeout' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_mode_timeout_alr(
    uint32_t* timeout,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the touch position data from the touchpad controller.
 *
 * This function reads the X, Y, and Z coordinates for the first and second
 * touch points, as well as the total number of active touches, from the
 * touchpad controller. The communication with the device is performed using
 * the interface defined in the context.
 *
 * \param[out] positions  : Pointer to a mtb_touchpad_pos_t structure where touch
 *                          coordinates and touch count will be stored.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Touch position data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'positions' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_pos(
    mtb_touchpad_pos_t* positions,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the gesture detection value from the touchpad controller.
 *
 * This function reads the GESTURE_DET register from the touchpad controller
 * and stores the detected gesture in the provided pointer. The
 * communication with the device is performed using the interface defined in the context.
 *
 * \param[out] gestures  : Pointer to store the 32-bit gesture detection value.
 * \param[in]  context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Gesture data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'gestures' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_gestures(
    uint32_t* gestures,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the gesture direction value from the touchpad controller.
 *
 * This function reads the GESTURE_DIR register from the touchpad controller
 * and stores the detected gesture in the provided pointer. The
 * communication with the device is performed using the interface defined in the context.
 *
 * \param[out] gestures  : Pointer to store the 32-bit gesture direction value.
 * \param[in]  context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Gesture data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'gestures' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_gestures_dir(
    uint32_t* gestures,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Enables or disables liquid detection functionality.
 *
 * This function writes the liquid detection enable configuration to the
 * touchpad controller. The communication with the device is performed
 * using the interface defined in the context.
 *
 * \param[in] liquid_detect_en : Liquid detection enable value.
 * \param[in] context          : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Liquid detection configuration updated successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_liquid_detect_en(
    uint8_t liquid_detect_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the liquid detection enable configuration.
 *
 * This function reads the liquid detection enable register from the
 * touchpad controller and stores the value in the provided pointer.
 * The communication with the device is performed using the interface
 * defined in the context.
 *
 * \param[out] liquid_detect_en : Pointer to store the liquid detection enable value.
 * \param[in]  context          : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Liquid detection configuration retrieved successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'liquid_detect_en' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_liquid_detect_en(
    uint8_t* liquid_detect_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the liquid detected status from the touchpad controller.
 *
 * This function reads the liquid detected status register from the
 * touchpad controller and stores the detection status in the provided pointer.
 * The communication with the device is performed using the interface defined in the context.
 *
 * \param[out] liquid_detected : Pointer to store the liquid detected status.
 * \param[in]  context         : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Liquid detection status retrieved successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or read failure

 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'liquid_detected' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_liquid_detected(
    uint8_t* liquid_detected,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Configures the liquid detection duty cycle value.
 *
 * This function writes the liquid detection duty cycle configuration
 * to the touchpad controller. The communication with the device is
 * performed using the interface defined in the context.
 *
 * \param[in] liquid_duty_cycle : Liquid detection duty cycle value.
 * \param[in] context           : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Duty cycle configured successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_liquid_duty_cycle(
    uint8_t liquid_duty_cycle,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the liquid detection duty cycle value.
 *
 * This function reads the liquid detection duty cycle register from the
 * touchpad controller and stores the value in the provided pointer.
 * The communication with the device is performed using the interface
 * defined in the context.
 *
 * \param[out] liquid_duty_cycle : Pointer to store the liquid detection duty cycle value.
 * \param[in]  context           : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Duty cycle retrieved successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or read failure

 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'liquid_duty_cycle' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_liquid_duty_cycle(
    uint8_t* liquid_duty_cycle,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Enables or disables DONN functionality.
 *
 * This function writes the DONN enable configuration to the
 * touchpad controller. The communication with the device is performed
 * using the interface defined in the context.
 *
 * \param[in] donn_en : DONN enable value.
 * \param[in] context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - DONN configuration updated successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or write failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_donn_en(
    uint8_t donn_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the DONN enable configuration.
 *
 * This function reads the DONN enable register from the touchpad
 * controller and stores the value in the provided pointer.
 * The communication with the device is performed using the interface
 * defined in the context.
 *
 * \param[out] donn_en : Pointer to store the DONN enable value.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - DONN configuration retrieved successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'donn_en' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_donn_en(
    uint8_t* donn_en,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the DONN detection status from the touchpad controller.
 *
 * This function reads the DONN detection status register from the
 * touchpad controller and stores the detection status in the provided pointer.
 * The communication with the device is performed using the interface defined in the context.
 *
 * \param[out] donn_detected : Pointer to store the DONN detection status.
 * \param[in]  context       : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - DONN detection status retrieved successfully
          MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
          MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'donn_detected' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_donn_detect(
    uint8_t* donn_detected,
    mtb_touchpad_intf_context_t* context);


/**
 * \brief Retrieves the NVM (Non-Volatile Memory) flag status from the touchpad controller.
 *
 * This function reads the NVM flag from the touchpad controller, indicating whether
 * configuration data is stored in non-volatile memory. The result is stored in the
 * provided pointer. Communication with the device uses the interface defined in the context.
 *
 * \param[out] stored_flag : Pointer to store the NVM flag status value.
 * \param[in]  context     : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - NVM flag retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'stored_flag' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_nvm_flag(
    MTB_TOUCHPAD_CONFIG_STORED_t* stored_flag,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the number of sensors from touchpad controller.
 *
 * This function reads the sensor count configuration from the touchpad controller
 * and stores the number of sensors in the provided pointer. The communication
 * with the device is performed using the interface defined in the context.
 *
 * \param[out] num_sns : Pointer to store the number of sensors value.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Number of sensors retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'num_sns' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_num_sns(
    uint8_t* num_sns,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the raw count value for a specific touchpad sensor.
 *
 * This function reads the raw count value of the specified sensor from
 * the touchpad device. The raw count represents the unprocessed sensor
 * measurement prior to baseline subtraction and filtering.
 *
 * \param[in]  sns_idx    : Index of the sensor for which raw count is requested.
 * \param[out] raw_count  : Pointer to variable where the raw count value will be stored.
 * \param[in]  context    : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Raw count retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'sns_idx' value must be within the valid range based on the number of sensors.
 * \note The 'raw_count' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_raw_count(
    uint8_t sns_idx,
    uint16_t* raw_count,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves raw count values for all sensors from the touchpad controller.
 *
 * This function reads the raw count data for all sensors from the touchpad controller
 * and stores the values sequentially in the provided buffer. The buffer must be large
 * enough to hold data for all sensors. The communication with the device is performed
 * using the interface defined in the context.
 *
 * \param[out] buff    : Pointer to buffer to store the raw count values for all sensors.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Raw count data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'buff' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_all_sns_raw_count(
    uint16_t* buff,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the baseline value for a specific touchpad sensor.
 *
 * This function reads the baseline value of the specified sensor from
 * the touchpad device. The baseline represents the reference capacitance
 * level used for touch detection for that sensor.
 *
 * \param[in]  sns_idx   : Index of the sensor for which baseline is requested.
 * \param[out] baseline  : Pointer to variable where the baseline value will be stored.
 * \param[in]  context   : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Baseline retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'sns_idx' value must be within the valid range based on the number of sensors.
 * \note The 'baseline' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_baseline(
    uint8_t sns_idx,
    uint16_t* baseline,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves baseline values for all touchpad sensors.
 *
 * This function reads the baseline data for all configured sensors from
 * the touchpad device and stores the values in the provided buffer.
 * Baseline values represent the reference capacitance levels used for
 * touch detection.
 *
 * \param[out] buff    : Pointer to buffer where baseline values will be stored.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Baseline data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'buff' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_all_sns_baseline(
    uint16_t* buff,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the capacitance value for a specific touchpad sensor.
 *
 * This function reads the capacitance value of the specified sensor from
 * the touchpad device. The capacitance value represents the measured
 * sensor signal used for touch detection and processing.
 *
 * \param[in]  sns_idx      : Index of the sensor for which capacitance is requested.
 * \param[out] capacitance  : Pointer to variable where the capacitance value will be stored.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Capacitance retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'sns_idx' value must be within the valid range based on the number of sensors.
 * \note The 'capacitance' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_capacitance(
    uint8_t sns_idx,
    uint32_t* capacitance,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves capacitance values for all touchpad sensors.
 *
 * This function reads the capacitance data for all configured sensors
 * from the touchpad device and stores the values in the provided buffer.
 *
 * \param[out] capacitances : Pointer to buffer where sensor capacitance values will be stored.
 * \param[in]  context      : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - Capacitance data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'capacitances' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_all_sns_capacitance(
    uint32_t* capacitances,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the size of the user data area of the touchpad controller.
 *
 * This function reads the USER_DATA_LEN register, which reports the number
 * of bytes available in the user data area located after the per-sensor
 * raw/baseline/capacitance data.
 *
 * \param[out] size    : Pointer to store the user data area size, in bytes.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - User data size retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'size' pointer must be a valid, non-NULL pointer.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_user_data_size(
    uint16_t* size,
    mtb_touchpad_intf_context_t* context);

/**
 * \brief Retrieves the user data from the touchpad controller.
 *
 * This function reads up to 'len' bytes from the user data area of the
 * touchpad device into the provided buffer. The location of the user data
 * area is derived from the configured number of sensors. The requested
 * length is validated against the USER_DATA_LEN register before the read
 * is performed.
 *
 * \param[out] buf     : Pointer to buffer where the user data will be stored.
 * \param[in]  len     : Number of bytes to read from the user data area.
 * \param[in]  context : Pointer to initialized touchpad interface context.
 *
 * \return MTB_TOUCHPAD_RET_SUCCESS - User data retrieved successfully
 *         MTB_TOUCHPAD_RET_INVALID_PARAM - Invalid input parameters, or 'len'
 *                                         exceeds the user data area size
 *         MTB_TOUCHPAD_RET_ERROR - Communication or read failure
 *
 * \note The context must be initialized using mtb_touchpad_init() before calling this function.
 * \note The 'buf' pointer must be a valid, non-NULL pointer, and must be at least 'len' bytes.
 *
 * \ingroup touchpad_functions
 */
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_user_data(
    uint8_t* buf,
    uint16_t len,
    mtb_touchpad_intf_context_t* context);

#if defined(__cplusplus)
}
#endif

#endif /* MTB_TOUCHPAD_DRIVER_H_ */
