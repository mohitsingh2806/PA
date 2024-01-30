#ifndef SC1905_H
#define SC1905_H

#define FW_VER_REG 0x003       // 8-bit R
#define FW_BUILD_MSB_REG 0x004 // 8-bit R
#define FW_BUILD_LSB_REG 0x00A // 8-bit R
#define STATUS_REG 0x005       // 8-bit R
#define ERROR_REG 0x006        // 8-bit R
#define WARNING_REG 0x007      // 8-bit R
#define OUTPUT_MODE_REG 0x008  // 8-bit RW

#define FREQ_RANGE_REG 0x010           // 8-bit R
#define MIN_FREQ_SCAN_REG 0x011        // 16-bit R
#define MAX_FREQ_SCAN_REG 0x013        // 16-bit R
#define ADAPTATION_MODE_REG 0x017      // 8-bit R
#define SIGNAL_BANDWIDTH_REG 0x018     // 16-bit R
#define UNSCALED_CENTER_FREQ_REG 0x01A // 16-bit R
#define ADAPTATION_STATE_REG 0x023     // 8-bit RW
#define GET_OUTPUT_STATUS_REG 0x032    // 8-bit R
#define NORMALIZATION_FACTOR_REG 0x033 // 8-bit R
#define UNNORMALIZED_COEFF_REG 0x034   // 16-bit R
#define RFIN_AGC_REG 0x23C             // 8-bit R
#define PRODUCT_ID_REG 0x959           // 8-bit R
#define RFFB_AGC_REG 0x9C4             // 8-bit R
#define SCALED_CENTER_FREQ_REG 0xBA8   // 16-bit

// SPECIAL COMMANDS
#define CLEAR_WARNING_COMMAND 0x10030000                          // Clear Warning Command
#define CLEAR_WARNING_REPLY 0x90030000                            // Clear Warning Reply
#define ACTIVATE_OUTPUT_COMMAND 0x10040000                        // Activate Output Command
#define ACTIVATE_OUTPUT_REPLY 0x90040000                          // Activate Output Reply
#define REQUEST_RESCAN_COMMAND 0x10050000                         // Request Rescan Command
#define REQUEST_RESCAN_REPLY 0x90050000                           // Request Rescan Reply
#define EXTEND_SCRATCH_READABLE_ACCESS_ENABLE_COMMAND 0x10CD0000  // Extend Scratch Readable Access Enable Command
#define EXTEND_SCRATCH_READABLE_ACCESS_ENABLE_REPLY 0x90CD0000    // Extend Scratch Readable Access Enable Reply
#define EXTEND_SCRATCH_READABLE_ACCESS_DISABLE_COMMAND 0x10CE0000 // Extend Scratch Readable Access Disable Command
#define EXTEND_SCRATCH_READABLE_ACCESS_DISABLE_REPLY 0x90CE0000   // Extend Scratch Readable Access Disable Reply
#define WAKE_UP_COMMAND 0x10FA0000                                // Wake-up Command
#define WAKE_UP_REPLY 0x90FA0000                                  // Wake-up Reply

// SPI Messages Communication Commands for Smooth Mode Calibration
#define CLEAR_MAX_PWR_CAL_PARAMS_A_COMMAND 0x10F30000 // Clear MaxPWRCalParameters A Command
#define CLEAR_MAX_PWR_CAL_PARAMS_A_REPLY 0x90F30000   // Clear MaxPWRCalParameters A Reply
#define CLEAR_MAX_PWR_CAL_PARAMS_B_COMMAND 0x10F40000 // Clear MaxPWRCalParameters B Command
#define CLEAR_MAX_PWR_CAL_PARAMS_B_REPLY 0x90F40000   // Clear MaxPWRCalParameters B Reply
#define WRITE_MAX_PWR_CAL_PARAMS_A_COMMAND 0x10F50000 // Write MaxPWRCalParameters A Command
#define WRITE_MAX_PWR_CAL_PARAMS_A_REPLY 0x90F50000   // Write MaxPWRCalParameters A Reply
#define WRITE_MAX_PWR_CAL_PARAMS_B_COMMAND 0x10F60000 // Write MaxPWRCalParameters B Command
#define WRITE_MAX_PWR_CAL_PARAMS_B_REPLY 0x90F60000   // Write MaxPWRCalParameters B Reply

// Scratch Parameters for Smooth Calibration Command Status
#define MAX_PWR_CLEAR_ONGOING 0xDC3 // MaxPWRClearOngoing (UNIT8 R)
#define MAX_PWR_CAL_A_ONGOING 0xDC4 // MaxPwrCalAOngoing (UNIT8 R)
#define MAX_PWR_CAL_B_ONGOING 0xDC6 // MaxPwrCalBOngoing (UNIT8 R)

// EEPROM Addresses for Customer Configuration Parameters

#define EEPROM_ADDRESS_MIN_FREQUENCY_SCAN 0xFC00                      // EEPROM Address (Hex) for MinFrequencyScan (UINT16)
#define EEPROM_ADDRESS_MAX_FREQUENCY_SCAN 0xFC02                      // EEPROM Address (Hex) for MaxFrequencyScan (UINT16)
#define EEPROM_ADDRESS_FREQUENCY_RANGE 0xFC04                         // EEPROM Address (Hex) for Frequency Range (UINT8)
#define EEPROM_ADDRESS_SEM_MEAS_BW_MHZ 0xFC10                         // EEPROM Address (Hex) for SemMeasBW_MHz (UINT8)
#define EEPROM_ADDRESS_LOWER_SEM_FREQ_A_MHZ 0xFC11                    // EEPROM Address (Hex) for LowerSemFreqA_MHz (INT8)
#define EEPROM_ADDRESS_DUTY_CYCLE_FEEDBACK_MODE 0xFC15                // EEPROM Address (Hex) for Duty Cycle Feedback Mode (UINT8)
#define EEPROM_ADDRESS_RFFB_REFERENCE_OFFSET 0xFC17                   // EEPROM Address (Hex) for RFFB Reference Offset (INT16)
#define EEPROM_ADDRESS_RFIN_REFERENCE_OFFSET 0xFC19                   // EEPROM Address (Hex) for RFIN Reference Offset (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_1A 0xFC1B                // EEPROM Address (Hex) for MaxPWRCalParameter1A (RFFB Max PWR A) (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_2A 0xFC1D                // EEPROM Address (Hex) for MaxPWRCalParameter2A (RFIN AGC Index A = PDET) (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_3A 0xFC1E                // EEPROM Address (Hex) for MaxPWRCalParameter3A (IC Temp A) (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_4A 0xFC20                // EEPROM Address (Hex) for MaxPWRCalParameter4A (Corr VGA Index A) (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_5A 0xFC21                // EEPROM Address (Hex) for MaxPWRCalParameter5A (PDET DC offset DAC Index A) (UINT8)
#define EEPROM_ADDRESS_TDD_DUTY_CYCLE_FACTOR 0xFC23                   // EEPROM Address (Hex) for TDD Duty Cycle Factor % (UINT8)
#define EEPROM_ADDRESS_PDET_TEMP_COMPENSATION_FLAG 0xFC24             // EEPROM Address (Hex) for PDET Temperature Compensation Flag (UINT8)
#define EEPROM_ADDRESS_UPPER_FREEZE_THRESHOLD 0xFC2F                  // EEPROM Address (Hex) for Upper Freeze Threshold (UINT8)
#define EEPROM_ADDRESS_LOWER_FREEZE_THRESHOLD 0xFC30                  // EEPROM Address (Hex) for Lower Freeze Threshold (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_6A 0xFC37                // EEPROM Address (Hex) for MaxPWRCalParameter6A (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_7A 0xFC38                // EEPROM Address (Hex) for MaxPWRCalParameter7A (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_8A 0xFC50                // EEPROM Address (Hex) for MaxPWRCalParameter8A (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_9A 0xFC51                // EEPROM Address (Hex) for MaxPWRCalParameter9A (RFIN Max PWR A) (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_10A 0xFC53               // EEPROM Address (Hex) for MaxPWRCalParameter10A (Center Freq A) (UINT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_1B 0xFC55                // EEPROM Address (Hex) for MaxPWRCalParameter1B (RFFB Max PWR B) (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_2B 0xFC57                // EEPROM Address (Hex) for MaxPWRCalParameter2B (RFIN AGC Index B) (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_3B 0xFC58                // EEPROM Address (Hex) for MaxPWRCalParameter3B (IC Temp B) (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_4B 0xFC5A                // EEPROM Address (Hex) for MaxPWRCalParameter4B (Corr VGA Index B) (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_5B 0xFC5B                // EEPROM Address (Hex) for MaxPWRCalParameter5B (PDET DC offset DAC Index B) (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_9B 0xFC5C                // EEPROM Address (Hex) for MaxPWRCalParameter9B (RFIN Max PWR B) (INT16)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_10B 0xFC5E               // EEPROM Address (Hex) for MaxPWRCalParameter10B (Center Freq B) (UINT16)
#define EEPROM_ADDRESS_PDET_PA_GAIN_COMPENSATION_FLAG 0xFC60          // EEPROM Address (Hex) for PDET PA Gain Compensation Flag (UINT8)
#define EEPROM_ADDRESS_GUARD_BAND 0xFC62                              // EEPROM Address (Hex) for Guard Band (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_6B 0xFC63                // EEPROM Address (Hex) for MaxPWRCalParameter6B (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_7B 0xFC64                // EEPROM Address (Hex) for MaxPWRCalParameter7B (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_PARAMETER_8B 0xFC7C                // EEPROM Address (Hex) for MaxPWRCalParameter8B (UINT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_COEFF_A 0xFCAE                     // EEPROM Address (Hex) for MaxPWRCalCoeffA (INT8)
#define EEPROM_ADDRESS_MAX_PWR_CAL_COEFF_B 0xFCE0                     // EEPROM Address (Hex) for MaxPWRCalCoeffB (INT8)
#define EEPROM_ADDRESS_PLL_REF_DIVIDER 0xFCED                         // EEPROM Address (Hex) for PLL Ref Divider (UINT8)
#define EEPROM_ADDRESS_PLL_OUTPUT_DIVIDER 0xFCEE                      // EEPROM Address (Hex) for PLL Output Divider (UINT8)
#define EEPROM_ADDRESS_PLL_FEEDBACK_DIVIDER 0xFCEF                    // EEPROM Address (Hex) for PLL Feedback Divider (UINT8)
#define EEPROM_ADDRESS_LOWER_SEM_FREQ_B_MHZ 0xFCF0                    // EEPROM Address (Hex) for LowerSemFreqB_MHz (INT8)
#define EEPROM_ADDRESS_UPPER_SEM_FREQ_A_MHZ 0xFCF1                    // EEPROM Address (Hex) for UpperSemFreqA_MHz (INT8)
#define EEPROM_ADDRESS_UPPER_SEM_FREQ_B_MHZ 0xFCF2                    // EEPROM Address (Hex) for UpperSemFreqB_MHz (INT8)
#define EEPROM_ADDRESS_SEM_B_HIGH_THRESHOLD 0xFCF3                    // EEPROM Address (Hex) for SemB_HighThrsld (INT16)
#define EEPROM_ADDRESS_POWER_CHANGE_DETECTION_INTEGRATION_TIME 0xFCF5 // EEPROM Address (Hex) for Power Change Detection Integration Time (UINT16)
#define EEPROM_ADDRESS_CCDF_MODE 0xFD3B                               // EEPROM Address (Hex) for CCDF Mode (UINT8)
#define EEPROM_ADDRESS_LINEARIZER_OPERATION_MODE 0xFD5E               // EEPROM Address (Hex) for Linearizer Operation Mode (UINT8)
#define EEPROM_ADDRESS_LOWER_NOOB_WEIGHT_FACTOR 0xFD94                // EEPROM Address (Hex) for Lower NOOB Weight Factor (UINT8)
#define EEPROM_ADDRESS_UPPER_NOOB_WEIGHT_FACTOR 0xFD95                // EEPROM Address (Hex) for Upper NOOB Weight Factor (UINT8)
#define EEPROM_ADDRESS_POWER_CHANGE_DETECTION_DELTA 0xFD9F            // EEPROM Address (Hex) for Power Change Detection Delta (UINT16)
#define EEPROM_ADDRESS_DUTY_CYCLE_FSA_ENABLE_FLAG 0xFDA1              // EEPROM Address (Hex) for Duty Cycle FSA Enable Flag (UINT8)
#define EEPROM_ADDRESS_POWER_STEP_DOWN_ITERATION_COUNT 0xFDA4         // EEPROM Address (Hex) for Power Step Down Iteration Count (UINT16)
#define EEPROM_ADDRESS_POWER_STEP_UP_ITERATION_COUNT 0xFDA9           // EEPROM Address (Hex) for Power Step Up Iteration Count (UINT16)
#define EEPROM_ADDRESS_GAN_PA_MODE_ENABLE 0xFDAC                      // EEPROM Address (Hex) for GaN PA Mode enable (UINT8)
#define EEPROM_ADDRESS_ATE_CALIBRATION_OFFSET_ZONE_WRITTEN 0xFDB3     // EEPROM Address (Hex) for ATE Calibration Offset Zone Written (UINT8)
#define EEPROM_ADDRESS_CHECKSUM 0xFFFF                                // EEPROM Address (Hex) for Checksum (UINT8)

// External Clock Configuration EEPROM Parameters
#define EEPROM_ADDRESS_PLL_REF_DIVIDER 0xFCED      // EEPROM Address (Hex) for PLL Ref Divider (UINT8)
#define EEPROM_ADDRESS_PLL_OUTPUT_DIVIDER 0xFCEE   // EEPROM Address (Hex) for PLL Output Divider (UINT8)
#define EEPROM_ADDRESS_PLL_FEEDBACK_DIVIDER 0xFCEF // EEPROM Address (Hex) for PLL Feedback Divider (UINT8)

// Scratch center Frequency Parameters
#define SCRATCH_ADDRESS_UNSCLAED_CENTER_FREQUENCY 0x01A // Scratch Address (Hex) for Unscaled Center Frequency (16-bit R)
#define SCRATCH_ADDRESS_SCALED_CENTER_FREQUENCY 0xBA8   // Scratch Address (Hex) for Scaled Center Frequency (16-bit S)

// Wideband Performance EEPROM Parameters
#define EEPROM_ADDRESS_SEM_MEAS_BW_MHZ 0xFC10           // EEPROM Address (Hex) for SemMeasBW_MHz (UINT8)
#define EEPROM_ADDRESS_LOWER_SEM_FREQ_A_MHZ 0xFC11      // EEPROM Address (Hex) for LowerSemFreqA_MHz (INT8)
#define EEPROM_ADDRESS_GUARD_BAND 0xFC62                // EEPROM Address (Hex) for Guard Band (UINT8)
#define EEPROM_ADDRESS_LOWER_NOOB_WEIGHT_FACTOR 0xFD94  // EEPROM Address (Hex) for Lower NOOB Weight Factor (UINT8)
#define EEPROM_ADDRESS_UPPER_NOOB_WEIGHT_FACTOR 0xFD95  // EEPROM Address (Hex) for Upper NOOB Weight Factor (UINT8)
#define EEPROM_ADDRESS_LOWER_SEM_FREQ_B_MHZ 0xFCF0      // EEPROM Address (Hex) for LowerSemFreqB_MHz (INT8)
#define EEPROM_ADDRESS_UPPER_SEM_FREQ_A_MHZ 0xFCF1      // EEPROM Address (Hex) for UpperSemFreqA_MHz (INT8)
#define EEPROM_ADDRESS_UPPER_SEM_FREQ_B_MHZ 0xFCF2      // EEPROM Address (Hex) for UpperSemFreqB_MHz (INT8)
#define EEPROM_ADDRESS_LINEARIZER_OPERATION_MODE 0xFD5E // EEPROM Address (Hex) for Linearizer Operation Mode (UINT8)

#endif