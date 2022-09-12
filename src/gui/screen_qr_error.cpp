#include "screen_qr_error.hpp"
#include "config.h"
#include <stdlib.h>
#include "ScreenHandler.hpp"
#include "display.h"
#include "errors.h"
#include "sound.hpp"
#include "dump.h"
#include "sys.h"
#include "eeprom.h"
#include "support_utils.h"
#include "version.h"

static const constexpr Rect16 title_rect = Rect16(13, 44, 200, 20);
static const constexpr Rect16 hand_rect = Rect16(20, 165, 64, 82);
static const constexpr Rect16 descr_rect = Rect16(10, 41, display::GetW() - 20, 220);
static const constexpr Rect16 info_text_rect = Rect16(10, 295, 64, 10);
static const constexpr Rect16 QR_rect = Rect16(90, 130, 140, 140);
static const constexpr Rect16 link_rect = Rect16(10, 295, 64, display::GetH() - 255);
static const constexpr Rect16 qr_code_rect = Rect16(98, 295, 64, 10);
static const constexpr Rect16 fw_version_rect = Rect16(6, 295, 80, 10);
static const constexpr Rect16 signature_rect = Rect16(160, 295, 40, 10);
static const constexpr Rect16 appendix_rect = Rect16(185, 295, 40, 10);

static constexpr const char *const header_label = N_("ERROR");
static constexpr const char *const help_text = N_("More detail at");

screen_qr_error_data_t::screen_qr_error_data_t()
    : AddSuperWindow<screen_reset_error_data_t>()
    , header(this)
    , footer(this)
    , hand_icon(this, hand_rect, IDR_PNG_hand_qr)
    , err_title(this, title_rect, is_multiline::no)
    , err_description(this, descr_rect, is_multiline::yes)
    , help_txt(this, info_text_rect, is_multiline::no)
    , help_link(this, link_rect, is_multiline::no)
    , qr_code_txt(this, qr_code_rect, is_multiline::no)
    , fw_version_txt(this, fw_version_rect, is_multiline::no)
    , signature_txt(this, signature_rect, is_multiline::no)
    , appendix_txt(this, appendix_rect, is_multiline::no)
    , qr(this, QR_rect, 1) // error code is passed in the constructor
    , sound_started(false) {

    SetRedLayout();
    header.SetIcon(IDR_PNG_error_16px);
    header.SetText(_(header_label));

    qr_code_txt.font = resource_font(IDR_FNT_SMALL);
    fw_version_txt.font = resource_font(IDR_FNT_SMALL);
    signature_txt.font = resource_font(IDR_FNT_SMALL);
    appendix_txt.font = resource_font(IDR_FNT_SMALL);

    uint16_t error_code_short = dump_in_xflash_get_code();
    uint16_t error_code = ERR_PRINTER_CODE * 1000 + error_code_short;
    uint32_t i = 0;
    uint32_t count = sizeof(error_list) / sizeof(err_t);

    while (i < count && error_code_short != error_list[i].err_num) {
        ++i;
    }
    if (i == count) {
        /// no text found => leave blank screen
        err_title.Hide();
        err_description.Hide();
        help_txt.Hide();
        help_link.Hide();
    } else {
        qr.SetQRHeader(error_code);
        err_title.SetText(_(error_list[i].err_title));
        err_description.SetText(_(error_list[i].err_text));

        /// draw short URL
        const char *qr_text = qr.GetQRShortText();
        help_txt.SetText(_(help_text));
        help_link.SetText(_(qr_text));
    }

    /// draw footer information
    /// fw version, hash, [fw signed], [appendix]
    static char fw_version[14]; // intentionally limited to the number of practically printable characters without overwriting the nearby hash text
                                // snprintf will clamp the text if the input is too long
    snprintf(fw_version, sizeof(fw_version), "%s%s", project_version, project_version_suffix_short);
    fw_version_txt.SetText(_(fw_version));

    if (eeprom_get_bool(EEVAR_DEVHASH_IN_QR)) {
        static char p_code[PRINTER_CODE_SIZE + 1];
        printerCode(p_code);
        qr_code_txt.SetText(string_view_utf8::MakeRAM((const uint8_t *)p_code));
    } else {
        qr_code_txt.Hide();
    }

    if (signature_exist()) {
        static const char signed_fw_str[] = "[S]";
        signature_txt.SetText(_(signed_fw_str));
    } else {
        static const char signed_fw_str[] = "[S]";
        signature_txt.SetText(_(signed_fw_str));
        //signature_txt.Hide();
    }

    if (appendix_exist()) {
        static const char appendix_str[] = "[A]";
        appendix_txt.SetText(_(appendix_str));
    } else {
        static const char appendix_str[] = "[A]";
        appendix_txt.SetText(_(appendix_str));
        //appendix_txt.Hide();
    }
}

void screen_qr_error_data_t::unconditionalDraw() {
    super::unconditionalDraw();
    display::DrawLine(
        point_ui16(10, 33),
        point_ui16(229, 33),
        COLOR_WHITE);
}

void screen_qr_error_data_t::windowEvent(EventLock /*has private ctor*/, window_t *sender, GUI_event_t event, void *param) {
    if ((event == GUI_event_t::CLICK) || (event == GUI_event_t::BTN_DN)) {
        sys_reset();
        return;
    }
}
