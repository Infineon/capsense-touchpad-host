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
* \file mtb_touchpad_driver.c
*
* \brief
* Implements the CAPSENSE™ Touchpad I2C Host middleware API.
*
*******************************************************************************/

/*******************************************************************************
 * Include header file
 ******************************************************************************/
#include "mtb_touchpad_driver.h"
#include <stdint.h>
#include <string.h>

/******************************************************************************
 * Functions
 *****************************************************************************/
MTB_TOUCHPAD_RET_TYPE mtb_touchpad_init(mtb_touchpad_write_handle_t bus_write, mtb_touchpad_read_handle_t bus_read,
                                        void* intf_ptr, mtb_touchpad_intf_context_t* context)
{
    (void)intf_ptr;

    uint8_t num_of_sensor = MTB_TOUCHPAD_INVALID_NUM_SNS;
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == bus_write) || (NULL == bus_read) || (NULL == context))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    context->bus_read = bus_read;
    context->bus_write = bus_write;
    context->num_sensors = MTB_TOUCHPAD_INVALID_NUM_SNS;

    ret = context->bus_read(REG_NUM_SNS, &num_of_sensor, REG_NUM_SNS_SIZE, NULL);

    if (MTB_TOUCHPAD_RSLT_SUCCESS == ret)
    {
        context->num_sensors = num_of_sensor;
    }

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_fw_ver(mtb_touchpad_fw_ver_t* ver, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint8_t fw_ver[MTB_TOUCHPAD_FW_VER_SIZE] = { 0 };

    if ((NULL == ver) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_FW_VER, (uint8_t*)fw_ver, MTB_TOUCHPAD_FW_VER_SIZE, NULL);
    if (MTB_TOUCHPAD_RSLT_SUCCESS == ret)
    {
        ver->major = fw_ver[FW_VER_MAJ_IDX];
        ver->minor = ((uint16_t)fw_ver[FW_VER_MIN_IDX + 1] << 8) | fw_ver[FW_VER_MIN_IDX];
        ver->build = ((uint16_t)fw_ver[FW_VER_BLD_IDX + 1] << 8) | fw_ver[FW_VER_BLD_IDX];
    }

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_reset_cause(uint8_t* rst_cause, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == rst_cause) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_RST_CAUSE, rst_cause, REG_RST_CAUSE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_cmd(uint16_t cmd, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if (((cmd != MTB_TOUCHPAD_CMD_SOFTWARE_RESET) && (cmd != MTB_TOUCHPAD_CMD_SAVE) && (cmd != MTB_TOUCHPAD_CMD_RESTORE)
         && (cmd != MTB_TOUCHPAD_CMD_CP_TEST) && (cmd != MTB_TOUCHPAD_CMD_SHORT_TEST) &&
         (cmd != MTB_TOUCHPAD_CMD_BOOTLOADER_JUMP))
        || (NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_sw_reset(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t sw_reset_cmd = MTB_TOUCHPAD_CMD_SOFTWARE_RESET;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&sw_reset_cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_save_nvm(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t save_nvm_cmd = MTB_TOUCHPAD_CMD_SAVE;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&save_nvm_cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_load_nvm(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t load_nvm_cmd = MTB_TOUCHPAD_CMD_RESTORE;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&load_nvm_cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_run_cap_test(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t cap_test_cmd = MTB_TOUCHPAD_CMD_CP_TEST;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&cap_test_cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_run_short_test(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t short_test_cmd = MTB_TOUCHPAD_CMD_SHORT_TEST;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&short_test_cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_bootloader_jump(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t jump_to_bootloader_cmd = MTB_TOUCHPAD_CMD_BOOTLOADER_JUMP;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_CMD, (uint8_t*)&jump_to_bootloader_cmd, REG_CMD_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_test_status(MTB_TOUCHPAD_TEST_STATUS_t* test_status,
                                                   mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == test_status) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_TEST_STATUS, (uint8_t*)test_status, REG_TEST_STATUS_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_short_pin_ids(uint32_t* pin_ids, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == pin_ids) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SHORTED_SNS_ID, (uint8_t*)pin_ids, REG_SHORTED_SNS_ID_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_int_src_en(uint8_t src_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) ||
        (src_en < MTB_TOUCHPAD_INT_SRC_EN_MIN))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_INT_SRC_EN, &src_en, REG_INT_SRC_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_int_src_en(uint8_t* src_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == src_en) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_INT_SRC_EN, src_en, REG_INT_SRC_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_int_status(uint8_t int_status, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_INT_STATUS, &int_status, REG_INT_STATUS_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_int_status(uint8_t* int_status, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == int_status) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_INT_STATUS, int_status, REG_INT_STATUS_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_clear_all_int_status(mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint8_t val = MTB_TOUCHPAD_CLEAR_INT_STATUS;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_INT_STATUS, &val, REG_INT_STATUS_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_error_status(uint8_t* error_status, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == error_status) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_ERROR_STATUS, error_status, REG_ERROR_STATUS_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_scan_mode(MTB_TOUCHPAD_SCAN_MODE_t scan_mode,
                                                 mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint8_t combinable_mask = (uint8_t)(MTB_TOUCHPAD_SCAN_MODE_IDLE | MTB_TOUCHPAD_SCAN_MODE_ACTIVE);
    uint8_t current_scan_mode;
    uint8_t new_scan_mode;

    if ((NULL == context) || (NULL == context->bus_write) || (NULL == context->bus_read) ||
        (0 == scan_mode) ||
        (((uint8_t)scan_mode & ~combinable_mask) != 0))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SCAN_MODE, &current_scan_mode, REG_SCAN_MODE_SIZE, NULL);
    if (MTB_TOUCHPAD_RSLT_SUCCESS != ret)
    {
        return ret;
    }

    new_scan_mode = (uint8_t)scan_mode | (current_scan_mode & (uint8_t)MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE);

    ret = context->bus_write(REG_SCAN_MODE, &new_scan_mode, REG_SCAN_MODE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_scan_mode(MTB_TOUCHPAD_SCAN_MODE_t* scan_mode,
                                                 mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == scan_mode) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SCAN_MODE, (uint8_t*)scan_mode, REG_SCAN_MODE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_mode_timeout_en(uint8_t mode_timeout_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint8_t scan_mode;

    if ((NULL == context) || (NULL == context->bus_write) || (NULL == context->bus_read) ||
        (mode_timeout_en > 1U))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SCAN_MODE, &scan_mode, REG_SCAN_MODE_SIZE, NULL);
    if (MTB_TOUCHPAD_RSLT_SUCCESS != ret)
    {
        return ret;
    }

    if (0U != mode_timeout_en)
    {
        scan_mode |= (uint8_t)MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE;
    }
    else
    {
        scan_mode &= (uint8_t) ~MTB_TOUCHPAD_SCAN_MODE_TIMEOUT_ENABLE;
    }

    ret = context->bus_write(REG_SCAN_MODE, &scan_mode, REG_SCAN_MODE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_mode_timeout_en(uint8_t* mode_timeout_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint8_t scan_mode;

    if ((NULL == mode_timeout_en) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SCAN_MODE, &scan_mode, REG_SCAN_MODE_SIZE, NULL);

    if (MTB_TOUCHPAD_RSLT_SUCCESS == ret)
    {
        *mode_timeout_en = MTB_TOUCHPAD_TIMEOUT_ENABLED(scan_mode) ? 1U : 0U;
    }

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_shield_en(MTB_TOUCHPAD_SHIELD_EN_t shield_en,
                                                 mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) ||
        ((shield_en != MTB_TOUCHPAD_SHIELD_DISABLED) &&
         (shield_en != MTB_TOUCHPAD_SHIELD_ENABLED)))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_SHIELD_EN, (uint8_t*)&shield_en, REG_SHIELD_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_shield_en(MTB_TOUCHPAD_SHIELD_EN_t* shield_en,
                                                 mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == shield_en) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SHIELD_EN, (uint8_t*)shield_en, REG_SHIELD_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_sns_filt_cfg(uint16_t sns_filt_cfg, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) || !((sns_filt_cfg == MTB_TOUCHPAD_FILTER_NONE) ||
                                                               (sns_filt_cfg == MTB_TOUCHPAD_FILTER_MEDIAN) ||
                                                               (sns_filt_cfg == MTB_TOUCHPAD_FILTER_AVERAGE) ||
                                                               (sns_filt_cfg == MTB_TOUCHPAD_FILTER_IIR) ||
                                                               (((sns_filt_cfg &
                                                                  MTB_TOUCHPAD_FILTER_SW_IIR_COEFF_MASK) != 0U) &&
                                                                ((sns_filt_cfg &
                                                                  ~MTB_TOUCHPAD_FILTER_SW_IIR_COEFF_MASK) == 0U))
                                                               ))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_SNS_FILT_CFG, (uint8_t*)&sns_filt_cfg, REG_SNS_FILT_CFG_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_filt_cfg(uint16_t* sns_filt_cfg, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == sns_filt_cfg) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_FILT_CFG, (uint8_t*)sns_filt_cfg, REG_SNS_FILT_CFG_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_active_refresh_rate(uint8_t refresh_rate, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) || (MTB_TOUCHPAD_SNS_REFRESH_RATE_ACT_MIN > refresh_rate))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_SNS_REF_RATE_ACT, &refresh_rate, REG_SNS_REF_RATE_ACT_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_active_refresh_rate(uint8_t* refresh_rate, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == refresh_rate) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_REF_RATE_ACT, refresh_rate, REG_SNS_REF_RATE_ACT_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_mode_timeout_act(uint32_t timeout_act, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_MODE_TIMEOUT_ACT, (uint8_t*)&timeout_act, REG_MODE_TIMEOUT_ACT_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_mode_timeout_act(uint32_t* timeout_act, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == timeout_act) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_MODE_TIMEOUT_ACT, (uint8_t*)timeout_act, REG_MODE_TIMEOUT_ACT_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_alr_refresh_rate(uint8_t refresh_rate, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) || (MTB_TOUCHPAD_SNS_REFRESH_RATE_ALR_MIN > refresh_rate))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_SNS_REF_RATE_ALR, &refresh_rate, REG_SNS_REF_RATE_ALR_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_alr_refresh_rate(uint8_t* refresh_rate, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == refresh_rate) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_REF_RATE_ALR, refresh_rate, REG_SNS_REF_RATE_ALR_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_mode_timeout_alr(uint32_t timeout_alr, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_MODE_TIMEOUT_ALR, (uint8_t*)&timeout_alr, REG_MODE_TIMEOUT_ALR_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_mode_timeout_alr(uint32_t* timeout_alr, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == timeout_alr) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_MODE_TIMEOUT_ALR, (uint8_t*)timeout_alr, REG_MODE_TIMEOUT_ALR_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_pos(mtb_touchpad_pos_t* positions, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint8_t touch_coordinates[MTB_TOUCHPAD_GET_POS_SIZE] = { 0 };

    if ((NULL == positions) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_TCH0_POS_X, (uint8_t*)touch_coordinates, MTB_TOUCHPAD_GET_POS_SIZE, NULL);
    if (MTB_TOUCHPAD_RSLT_SUCCESS == ret)
    {
        positions->tch0.x = ((uint16_t)touch_coordinates[TCH0_X_IDX + 1] << 8) | touch_coordinates[TCH0_X_IDX];
        positions->tch0.y = ((uint16_t)touch_coordinates[TCH0_Y_IDX + 1] << 8) | touch_coordinates[TCH0_Y_IDX];
        positions->tch0.z = ((uint16_t)touch_coordinates[TCH0_Z_IDX + 1] << 8) | touch_coordinates[TCH0_Z_IDX];
        positions->tch1.x = ((uint16_t)touch_coordinates[TCH1_X_IDX + 1] << 8) | touch_coordinates[TCH1_X_IDX];
        positions->tch1.y = ((uint16_t)touch_coordinates[TCH1_Y_IDX + 1] << 8) | touch_coordinates[TCH1_Y_IDX];
        positions->tch1.z = ((uint16_t)touch_coordinates[TCH1_Z_IDX + 1] << 8) | touch_coordinates[TCH1_Z_IDX];
        positions->num_touch = touch_coordinates[NUM_TOUCH_IDX];
    }

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_gestures(uint32_t* gestures, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == gestures) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_GESTURE_DET, (uint8_t*)gestures, REG_GESTURE_DET_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_gestures_dir(uint32_t* gestures, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == gestures) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_GESTURE_DIR, (uint8_t*)gestures, REG_GESTURE_DIR_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_liquid_detect_en(uint8_t liquid_detect_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) || (liquid_detect_en > MTB_TOUCHPAD_LIQUID_DETECT_EN_MAX))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_LIQUID_DETECT_EN, &liquid_detect_en, REG_LIQUID_DETECT_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_liquid_detect_en(uint8_t* liquid_detect_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == liquid_detect_en) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_LIQUID_DETECT_EN, liquid_detect_en, REG_LIQUID_DETECT_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_liquid_detected(uint8_t* liquid_detect, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == liquid_detect) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_LIQUID_DETECTED, liquid_detect, REG_LIQUID_DETECTED_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_liquid_duty_cycle(uint8_t duty_cycle, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) || (duty_cycle > MTB_TOUCHPAD_LIQUID_DUTY_CYCLE_MAX))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_LIQUID_DUTY_CYCLE, &duty_cycle, REG_LIQUID_DUTY_CYCLE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_liquid_duty_cycle(uint8_t* duty_cycle, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == duty_cycle) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_LIQUID_DUTY_CYCLE, duty_cycle, REG_LIQUID_DUTY_CYCLE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_set_donn_en(uint8_t donn_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == context->bus_write) || (donn_en > MTB_TOUCHPAD_DONN_EN_MAX))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_write(REG_DONN_EN, &donn_en, REG_DONN_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_donn_en(uint8_t* donn_en, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == donn_en) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_DONN_EN, donn_en, REG_DONN_EN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_donn_detect(uint8_t* donn_detect, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == donn_detect) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_DONN_DETECT, donn_detect, REG_DONN_DETECT_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_nvm_flag(MTB_TOUCHPAD_CONFIG_STORED_t* stored_flag,
                                                mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == stored_flag) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_STORED_FLAG, (uint8_t*)stored_flag, REG_STORED_FLAG_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_num_sns(uint8_t* num_sns, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == num_sns) || (NULL == context) || (NULL == context->bus_read) ||
        (MTB_TOUCHPAD_INVALID_NUM_SNS == context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_NUM_SNS, num_sns, REG_NUM_SNS_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_raw_count(uint8_t sns_idx, uint16_t* raw_count,
                                                     mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == raw_count) || (NULL == context->bus_read) || (sns_idx >= context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_RAW_IDX(sns_idx), (uint8_t*)raw_count, BASELINE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_all_sns_raw_count(uint16_t* buff, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == buff) || (NULL == context) || (NULL == context->bus_read) ||
        (MTB_TOUCHPAD_INVALID_NUM_SNS == context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_RAW, (uint8_t*)buff, REG_SNS_RAW_SIZE(context->num_sensors), NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_baseline(uint8_t sns_idx, uint16_t* baseline,
                                                    mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == baseline) || (NULL == context->bus_read) || (sns_idx >= context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_BSL_IDX(context->num_sensors, sns_idx), (uint8_t*)baseline, BASELINE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_all_sns_baseline(uint16_t* buff, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == buff) || (NULL == context) || (NULL == context->bus_read) ||
        (MTB_TOUCHPAD_INVALID_NUM_SNS == context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_SNS_BSL(context->num_sensors), (uint8_t*)buff, REG_SNS_BSL_SIZE(
                                context->num_sensors), NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_sns_capacitance(uint8_t sns_idx, uint32_t* capacitance,
                                                       mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == context) || (NULL == capacitance) || (NULL == context->bus_read) || (sns_idx >= context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret =
        context->bus_read(REG_SNS_CP_IDX(context->num_sensors, sns_idx), (uint8_t*)capacitance, CAPACITANCE_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_all_sns_capacitance(uint32_t* capacitances, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == capacitances) || (NULL == context) || (NULL == context->bus_read) ||
        (MTB_TOUCHPAD_INVALID_NUM_SNS == context->num_sensors))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret =
        context->bus_read(REG_SNS_CP_MEASURE(context->num_sensors), (uint8_t*)capacitances,
                          REG_SNS_CP_MEASURE_SIZE(context->num_sensors), NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_user_data_size(uint16_t* size, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;

    if ((NULL == size) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_USER_DATA_LEN, (uint8_t*)size, REG_USER_DATA_LEN_SIZE, NULL);

    return ret;
}


MTB_TOUCHPAD_RET_TYPE mtb_touchpad_get_user_data(uint8_t* buf, uint16_t len, mtb_touchpad_intf_context_t* context)
{
    MTB_TOUCHPAD_RET_TYPE ret;
    uint16_t user_data_size;

    if ((NULL == buf) || (0 == len) || (NULL == context) || (NULL == context->bus_read))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = mtb_touchpad_get_user_data_size(&user_data_size, context);

    if (MTB_TOUCHPAD_RSLT_SUCCESS != ret)
    {
        return ret;
    }

    if ((0 == user_data_size) || (len > user_data_size))
    {
        return MTB_TOUCHPAD_RSLT_INVALID_PARAM;
    }

    ret = context->bus_read(REG_USER_DATA(context->num_sensors), buf, len, NULL);

    return ret;
}
