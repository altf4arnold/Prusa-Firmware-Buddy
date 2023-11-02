/**
 * @file selftest_state_names.hpp
 * @brief names attached to selftest states
 */

#pragma once

#include "client_response.hpp"

constexpr const char *get_selftest_state_name(PhasesSelftest state) {

    switch (state) {
    case PhasesSelftest::_none:
        return "_none";
    case PhasesSelftest::WizardPrologue_ask_run:
        return "WizardPrologue_ask_run";
    case PhasesSelftest::WizardPrologue_ask_run_dev:
        return "WizardPrologue_ask_run_dev";
    case PhasesSelftest::WizardPrologue_info:
        return "WizardPrologue_info";
    case PhasesSelftest::WizardPrologue_info_detailed:
        return "WizardPrologue_info_detailed";
    case PhasesSelftest::Fans:
        return "Fans";
    case PhasesSelftest::Loadcell_prepare:
        return "Loadcell_prepare";
    case PhasesSelftest::Loadcell_move_away:
        return "Loadcell_move_away";
    case PhasesSelftest::Loadcell_tool_select:
        return "Loadcell_tool_select";
    case PhasesSelftest::Loadcell_cooldown:
        return "Loadcell_cooldown";
    case PhasesSelftest::Loadcell_user_tap_ask_abort:
        return "Loadcell_user_tap_ask_abort";
    case PhasesSelftest::Loadcell_user_tap_countdown:
        return "Loadcell_user_tap_countdown";
    case PhasesSelftest::Loadcell_user_tap_check:
        return "Loadcell_user_tap_check";
    case PhasesSelftest::Loadcell_user_tap_ok:
        return "Loadcell_user_tap_ok";
    case PhasesSelftest::Loadcell_fail:
        return "Loadcell_fail";
    case PhasesSelftest::FSensor_wait_tool_pick:
        return "FSensor_wait_tool_pick";
    case PhasesSelftest::FSensor_ask_unload:
        return "FSensor_ask_unload";
    case PhasesSelftest::FSensor_unload_confirm:
        return "FSensor_unload_confirm";
    case PhasesSelftest::FSensor_calibrate:
        return "FSensor_calibrate";
    case PhasesSelftest::FSensor_insertion_wait:
        return "FSensor_insertion_wait";
    case PhasesSelftest::FSensor_insertion_ok:
        return "FSensor_insertion_ok";
    case PhasesSelftest::FSensor_insertion_calibrate:
        return "FSensor_insertion_calibrate";
    case PhasesSelftest::Fsensor_enforce_remove:
        return "Fsensor_enforce_remove";
    case PhasesSelftest::FSensor_fail:
        return "FSensor_fail";
    case PhasesSelftest::FSensor_done:
        return "FSensor_done";
    case PhasesSelftest::GearsCalib_filament_check:
        return "GearsCalib_filament_check";
    case PhasesSelftest::GearsCalib_filament_loaded_ask_unload:
        return "GearsCalib_filament_loaded_ask_unload";
    case PhasesSelftest::GearsCalib_filament_unknown_ask_unload:
        return "GearsCalib_filament_loaded_ask_unload";
    case PhasesSelftest::GearsCalib_release_screws:
        return "GearsCalib_release_screws";
    case PhasesSelftest::GearsCalib_alignment:
        return "GearsCalib_alignment";
    case PhasesSelftest::GearsCalib_tighten:
        return "GearsCalib_tighten";
    case PhasesSelftest::GearsCalib_done:
        return "GearsCalib_done";
    case PhasesSelftest::CalibZ:
        return "CalibZ";
    case PhasesSelftest::Axis:
        return "Axis";
    case PhasesSelftest::Heaters:
        return "Heaters";
    case PhasesSelftest::HeatersDisabledDialog:
        return "HeatersDisabledDialog";
    case PhasesSelftest::SpecifyHotEnd:
        return "SpecifyHotEnd";
    case PhasesSelftest::SpecifyHotEnd_sock:
        return "SpecifyHotEnd_sock";
    case PhasesSelftest::SpecifyHotEnd_nozzle_type:
        return "SpecifyHotEnd_nozzle_type";
    case PhasesSelftest::SpecifyHotEnd_retry:
        return "SpecifyHotEnd_retry";
    case PhasesSelftest::FirstLayer_mbl:
        return "FirstLayer_mbl";
    case PhasesSelftest::FirstLayer_print:
        return "FirstLayer_print";
    case PhasesSelftest::FirstLayer_filament_known_and_not_unsensed:
        return "FirstLayer_filament_known_and_not_unsensed";
    case PhasesSelftest::FirstLayer_filament_not_known_or_unsensed:
        return "FirstLayer_filament_not_known_or_unsensed";
    case PhasesSelftest::FirstLayer_calib:
        return "FirstLayer_calib";
    case PhasesSelftest::FirstLayer_use_val:
        return "FirstLayer_use_val";
    case PhasesSelftest::FirstLayer_start_print:
        return "FirstLayer_start_print";
    case PhasesSelftest::FirstLayer_reprint:
        return "FirstLayer_reprint";
    case PhasesSelftest::FirstLayer_clean_sheet:
        return "FirstLayer_clean_sheet";
    case PhasesSelftest::FirstLayer_failed:
        return "FirstLayer_failed";
    case PhasesSelftest::Result:
        return "Result";
    case PhasesSelftest::WizardEpilogue_ok:
        return "WizardEpilogue_ok";
    case PhasesSelftest::WizardEpilogue_nok:
        return "WizardEpilogue_nok";
    case PhasesSelftest::Dock_move_away:
        return "Dock_move_away";
    case PhasesSelftest::Dock_wait_user_park1:
        return "DockCalibration_wait_park1";
    case PhasesSelftest::Dock_wait_user_park2:
        return "DockCalibration_wait_park2";
    case PhasesSelftest::Dock_wait_user_park3:
        return "DockCalibration_wait_park3";
    case PhasesSelftest::Dock_wait_user_remove_pins:
        return "DockCalibration_wait_user_remove_pins";
    case PhasesSelftest::Dock_wait_user_loosen_pillar:
        return "DockCalibration_wait_user_loosen_pillar";
    case PhasesSelftest::Dock_wait_user_lock_tool:
        return "DockCalibration_wait_user_lock_tool";
    case PhasesSelftest::Dock_wait_user_install_pins:
        return "DockCalibration_wait_user_install_pins";
    case PhasesSelftest::Dock_needs_calibration:
        return "Dock_needs_calibration";
    case PhasesSelftest::Dock_measure:
        return "DockCalibration_measure";
    case PhasesSelftest::Dock_wait_user_tighten_bottom_screw:
        return "DockCalibration_wait_user_tighten_bottom_screw";
    case PhasesSelftest::Dock_selftest_park_test:
        return "DockCalibration_selftest_park_test";
    case PhasesSelftest::Dock_selftest_failed:
        return "Dock_selftest_failed";
    case PhasesSelftest::Dock_calibration_success:
        return "Dock_calibration_success";
    case PhasesSelftest::Dock_wait_user_tighten_top_screw:
        return "DockCalibration_wait_user_tighten_pilar";
    case PhasesSelftest::ToolOffsets_wait_stable_temp:
        return "ToolOffsets_wait_stable_temp";
    case PhasesSelftest::ToolOffsets_wait_calibrate:
        return "ToolOffsets_wait_calibrate";
    case PhasesSelftest::ToolOffsets_pin_install_prepare:
        return "ToolOffsets_pin_install_prepare";
    case PhasesSelftest::ToolOffsets_wait_user_install_pin:
        return "ToolOffsets_wait_user_install_pin";
    case PhasesSelftest::ToolOffsets_wait_user_confirm_start:
        return "ToolOffsets_wait_user_confirm_start";
    case PhasesSelftest::ToolOffsets_wait_user_clean_nozzle_cold:
        return "ToolOffsets_wait_user_clean_nozzle_cold";
    case PhasesSelftest::ToolOffsets_wait_user_clean_nozzle_hot:
        return "ToolOffsets_wait_user_clean_nozzle_hot";
    case PhasesSelftest::ToolOffsets_wait_user_install_sheet:
        return "ToolOffsets_wait_user_install_sheet";
    case PhasesSelftest::ToolOffsets_wait_move_away:
        return "ToolOffsets_wait_move_away";
    case PhasesSelftest::ToolOffsets_wait_user_remove_pin:
        return "ToolOffsets_wait_user_remove_pin";
    }
    return "ERROR_not_a_selftest_state";
}
