#include "keymap.h"
#include <stdbool.h>
#include <stdint.h>
#include "action_layer.h"
#include "config.h"
#include "keycodes.h"
#include "progmem.h"
#include "rgb_matrix.h"

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "keymap_introspection.h"
#include <lib/lib8tion/lib8tion.h>

#include "utils.h"

// Layers and Maps

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_109(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  _______,  MC_4,     MC_5,     MC_6,     MC_7,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,
        _______,  RGB_M_CA, RGB_M_CX, RGB_M_CY, RGB_M_CO, RGB_M_CD, RGB_M_CP, RGB_M_CS, RGB_M_RC, RGB_M_RB, RGB_M_DB, _______,  _______,    _______,    RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,
        _______,  RGB_M_S,  RGB_M_BR, RGB_M_BS, RGB_M_RS, RGB_M_RM, RGB_M_RN, RGB_M_TH, RGB_M_SM, RGB_M_SS, _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            RGB_M_RF, RGB_M_FB, RGB_M_SD, RGB_M_JR, RGB_M_DR, RGB_M_PR, RGB_M_SP, _______,  _______,  _______,              _______,              RGB_SPI,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    RGB_RMOD, RGB_SPD,  RGB_MOD,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_SCRL,  KC_PAUS,  MC_0,     MC_1,     MC_2,     MC_3,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_APP,  MO(WIN_FN),  KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_109(
        _______,  KC_PWR,   KC_SLEP,  KC_BRID,  KC_BRIU,  KC_MYCM,  KC_HELP,  KC_WSCH,  KC_WHOM,  KC_MPLY,  KC_MSTP,  KC_MNXT,  KC_MPRV,    RGB_TOG,    _______,  _______,  _______,  MC_4,     MC_5,     MC_6,     MC_7,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,
        _______,  RGB_M_CA, RGB_M_CX, RGB_M_CY, RGB_M_CO, RGB_M_CD, RGB_M_CP, RGB_M_CS, RGB_M_RC, RGB_M_RB, RGB_M_DB, _______,  _______,    _______,    RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,
        _______,  RGB_M_S,  RGB_M_BR, RGB_M_BS, RGB_M_RS, RGB_M_RM, RGB_M_RN, RGB_M_TH, RGB_M_SM, RGB_M_SS, _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            RGB_M_RF, RGB_M_FB, RGB_M_SD, RGB_M_JR, RGB_M_DR, RGB_M_PR, RGB_M_SP, _______,  _______,  _______,              _______,              RGB_SPI,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    MO(STNGS),  RGB_RMOD, RGB_SPD,  RGB_MOD,  _______,            _______,  _______),
    [STNGS] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  MC_8,     MC_9,     MC_10,    MC_11,
        _______,  STN_RI_1, STN_RI_2, STN_RI_3, STN_RI_4, STN_RI_5, STN_RI_6, STN_RI_7, STN_RI_8, STN_RI_9, STN_RI_10,_______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  STN_RIP,  _______,  _______,  _______,  _______,  STN_BLM,  STN_RPK,  _______,  _______,    _______,    _______,  _______,  _______,  STN_GI_7, STN_GI_8, STN_GI_9,
        _______,  _______,  STN_SLI,  _______,  _______,  STN_GRD,  STN_SI,  _______,  _______,   STN_LM,   _______,  _______,              _______,                                  STN_GI_4, STN_GI_5, STN_GI_6, _______,
        _______,            _______,  _______,  STN_CLI,  _______,  _______,  STN_NLI,  _______,  _______,  _______,  _______,              _______,              STN_GD_U,           STN_GI_1, STN_GI_2, STN_GI_3,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    STN_GD_L, STN_GD_D, STN_GD_R, STN_GI_10,          _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
        [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
        [STNGS]    = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
    };
#endif

// clang-format on


// Local Variables

user_config_t user_config;

led_location PROGMEM led_locations[RGB_MATRIX_LED_COUNT];

uint32_t peeking_timer = 0;
uint32_t dirty_timer = 0;

// Process Overrides

void housekeeping_task_user(void) {
    housekeeping_task_keychron();

    if (peeking_timer && sync_timer_elapsed32(peeking_timer) >= 5000) {
        peeking_timer = 0;
    }

    if (dirty_timer && sync_timer_elapsed32(dirty_timer) >= 5000) {
        eeconfig_update_user(user_config.raw);
        dirty_timer = 0;
    }
}

void eeconfig_init_user(void) {
    user_config.raw = 0;

    #if defined(ENABLE_CAPS_LOCK_HIGHLIGHTING)
        user_config.caps_lock_indicator = 1;
    #else
        user_config.caps_lock_indicator = 0;
    #endif

    #if defined(ENABLE_NUM_LOCK_HIGHLIGHTING)
        user_config.num_lock_indicator = 1;
    #else
        user_config.num_lock_indicator = 0;
    #endif

    #if defined(ENABLE_SCROLL_LOCK_HIGHLIGHTING)
        user_config.scroll_lock_indicator = 1;
    #else
        user_config.scroll_lock_indicator = 0;
    #endif

    #if defined(ENABLE_SETTINGS_HIGHLIGHTING)
        user_config.setting_indicators = 1;
    #else
        user_config.setting_indicators = 0;
    #endif

    #if defined(ENABLE_LAYER_HIGHLIGHTING)
        user_config.layer_mask = 1;
    #else
        user_config.layer_mask = 0;
    #endif

    #if defined(ALWAYS_ON_LAYER_HIGHLIGHTING)
        user_config.bright_layer_mask = 1;
    #else
        user_config.bright_layer_mask = 0;
    #endif

    #if defined(ENABLE_GRADIENT_LIGHTING)
        user_config.gradient = 1;
    #else
        user_config.gradient = 0;
    #endif

    #if defined(DEFAULT_GRADIENT_INTENSITY)
        user_config.gradient_intensity = MAX(1, MIN(10, DEFAULT_GRADIENT_INTENSITY));
    #else
        user_config.gradient_intensity = 5;
    #endif

    #if defined(DEFAULT_GRADIENT_DIRECTION)
        user_config.gradient_direction = MAX(0, MIN(3, DEFAULT_GRADIENT_DIRECTION));
    #else
        user_config.gradient_direction = 0;
    #endif

    #if defined(ENABLE_REACTIVE_RIPPLES)
        user_config.ripples = 1;
    #else
        user_config.ripples = 0;
    #endif

    #if defined(DEFAULT_RIPPLE_INTENSITY)
        user_config.ripple_intensity = MAX(1, MIN(10, DEFAULT_RIPPLE_INTENSITY));
    #else
        user_config.ripple_intensity = 5;
    #endif

    #if defined(ENABLE_RGB_PEEK)
        user_config.rgb_peek = 1;
    #else
        user_config.rgb_peek = 0;
    #endif

    eeconfig_update_user(user_config.raw);
    reset_gradient_map(user_config.gradient_intensity, user_config.gradient_direction);
}

void keyboard_post_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            led_location location;
            location.row = row;
            location.col = col;
            uint8_t led_index;
            rgb_matrix_map_row_column_to_led(row, col, &led_index);
            led_locations[led_index] = location;
        }
    }

    user_config.raw = eeconfig_read_user();

    set_ripple_intensity(user_config.ripple_intensity);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    if (user_config.rgb_peek &&
        ((keycode >= RGB_MODE_FORWARD && keycode <= RGB_SPD) ||
        (keycode >= SETTING_RGB_GRADIENT_DIRECTION_UP && keycode <= RGB_MODE_STARLIGHT_DUAL_HUE))) {
        peeking_timer = sync_timer_read32();
    }

    switch (keycode) {
        // Setting Keycodes
        case SETTING_TOGGLE_CAPS_LOCK_INDICATOR:
            if (record->event.pressed) {
                user_config.caps_lock_indicator ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_TOGGLE_NUM_LOCK_INDICATOR:
            if (record->event.pressed) {
                user_config.num_lock_indicator ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_TOGGLE_SCROLL_LOCK_INDICATOR:
            if (record->event.pressed) {
                user_config.scroll_lock_indicator ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_TOGGLE_SETTING_INDICATORS:
            if (record->event.pressed) {
                user_config.setting_indicators ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_TOGGLE_LAYER_MASK:
            if (record->event.pressed) {
                user_config.layer_mask ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_TOGGLE_BRIGHT_LAYER_MASK:
            if (record->event.pressed) {
                user_config.bright_layer_mask ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_TOGGLE_RGB_GRADIENT:
            if (record->event.pressed) {
                user_config.gradient ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_RGB_GRADIENT_DIRECTION_UP ... SETTING_RGB_GRADIENT_DIRECTION_LEFT:
            if (record->event.pressed) {
                user_config.gradient_direction = keycode - SETTING_RGB_GRADIENT_DIRECTION_UP;
                dirty_timer = sync_timer_read32();
                reset_gradient_map(user_config.gradient_intensity, user_config.gradient_direction);
            }
            return false;
        case SETTING_RGB_GRADIENT_INTENSITY_1 ... SETTING_RGB_GRADIENT_INTENSITY_10:
            if (record->event.pressed) {
                user_config.gradient_intensity = keycode - SETTING_RGB_GRADIENT_INTENSITY_1 + 1;
                dirty_timer = sync_timer_read32();
                reset_gradient_map(user_config.gradient_intensity, user_config.gradient_direction);
            }
            return false;
        case SETTING_TOGGLE_REACTIVE_RIPPLES:
            if (record->event.pressed) {
                user_config.ripples ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;
        case SETTING_RGB_RIPPLE_INTENSITY_1 ... SETTING_RGB_RIPPLE_INTENSITY_10:
            if (record->event.pressed) {
                user_config.ripple_intensity = keycode - SETTING_RGB_RIPPLE_INTENSITY_1 + 1;
                dirty_timer = sync_timer_read32();
                set_ripple_intensity(user_config.ripple_intensity);
            }
            return false;
        case SETTING_TOGGLE_RGB_PEEK:
            if (record->event.pressed) {
                user_config.rgb_peek ^= 1;
                dirty_timer = sync_timer_read32();
            }
            return false;

        // RGB Mode Keycodes
        #ifdef RGB_MATRIX_ENABLE
            case RGB_MODE_SOLID:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                }
                return false;
        #endif // RGB_MATRIX_ENABLE
        #ifdef ENABLE_RGB_MATRIX_BREATHING
            case RGB_MODE_BREATHING:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_BREATHING);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_BREATHING
        #ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
            case RGB_MODE_BAND_SPIRAL_VAL:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_VAL);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_ALL
            case RGB_MODE_CYCLE_ALL:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_ALL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
            case RGB_MODE_CYCLE_LEFT_RIGHT:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
        #ifdef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
            case RGB_MODE_CYCLE_UP_DOWN:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
        #ifdef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
            case RGB_MODE_RAINBOW_MOVING_CHEVRON:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
        #ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
            case RGB_MODE_CYCLE_OUT_IN:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_OUT_IN
        #ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
            case RGB_MODE_CYCLE_OUT_IN_DUAL:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
            case RGB_MODE_CYCLE_PINWHEEL:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_PINWHEEL);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
            case RGB_MODE_CYCLE_SPIRAL:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_CYCLE_SPIRAL);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_CYCLE_SPIRAL
        #ifdef ENABLE_RGB_MATRIX_DUAL_BEACON
            case RGB_MODE_DUAL_BEACON:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_DUAL_BEACON
        #ifdef ENABLE_RGB_MATRIX_RAINBOW_BEACON
            case RGB_MODE_RAINBOW_BEACON:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_RAINBOW_BEACON);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_RAINBOW_BEACON
        #ifdef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
            case RGB_MODE_FLOWER_BLOOMING:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_FLOWER_BLOOMING);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_FLOWER_BLOOMING
        #ifdef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
            case RGB_MODE_JELLYBEAN_RAINDROPS:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
        #ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
            case RGB_MODE_PIXEL_RAIN:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_PIXEL_RAIN
        #ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
            case RGB_MODE_TYPING_HEATMAP:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_TYPING_HEATMAP
        #ifdef ENABLE_RGB_MATRIX_DIGITAL_RAIN
            case RGB_MODE_DIGITAL_RAIN:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_DIGITAL_RAIN);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_DIGITAL_RAIN
        #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
            case RGB_MODE_SOLID_REACTIVE_SIMPLE:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
        #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
            case RGB_MODE_SOLID_REACTIVE_MULTIWIDE:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
        #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
            case RGB_MODE_SOLID_REACTIVE_MULTINEXUS:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
        #ifdef ENABLE_RGB_MATRIX_SPLASH
            case RGB_MODE_SPLASH:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SPLASH);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_SPLASH
        #ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
            case RGB_MODE_SOLID_SPLASH:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SOLID_SPLASH);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_SOLID_SPLASH
        #ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
            case RGB_MODE_SOLID_MULTISPLASH:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
        #ifdef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
            case RGB_MODE_STARLIGHT_DUAL_HUE:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_STARLIGHT_DUAL_HUE);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
        #ifdef ENABLE_RGB_MATRIX_RIVERFLOW
            case RGB_MODE_RIVERFLOW:
                if (record->event.pressed) {
                    rgb_matrix_mode(RGB_MATRIX_RIVERFLOW);
                }
                return false;
        #endif // ENABLE_RGB_MATRIX_RIVERFLOW
            default:
                return true; // Process all other keycodes normally
    }

    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    if ((layer == MAC_FN || layer == WIN_FN || layer == STNGS)) {
        peeking_timer = sync_timer_read32();
    }
    return true;
}

bool rgb_matrix_modifiers_advanced_user(uint8_t led_index, HSV* hsv) {

    uint8_t layer = get_highest_layer(layer_state);
    led_location led_location = led_locations[led_index];
    uint16_t keycode = keycode_at_keymap_location(layer, led_location.row, led_location.col);
    bool upper_layer = (layer == MAC_FN || layer == WIN_FN || layer == STNGS);

    if (!peeking_timer && user_config.layer_mask && upper_layer) {
        if (keycode <= KC_TRANSPARENT) {
            hsv->v = 0;
        }
        else if (user_config.bright_layer_mask) {
            hsv->v = 255;
        }
    }

    switch (keycode) {

        // Lock Keycodes
        case KC_CAPS_LOCK: RGB_INDICATE(user_config.caps_lock_indicator && host_keyboard_led_state().caps_lock)
        case KC_NUM_LOCK: RGB_INDICATE(user_config.num_lock_indicator && host_keyboard_led_state().num_lock)
        case KC_SCROLL_LOCK: RGB_INDICATE(user_config.scroll_lock_indicator && host_keyboard_led_state().scroll_lock)

        // Setting Keycodes
        case SETTING_TOGGLE_CAPS_LOCK_INDICATOR: RGB_INDICATE(user_config.setting_indicators && user_config.caps_lock_indicator)
        case SETTING_TOGGLE_NUM_LOCK_INDICATOR: RGB_INDICATE(user_config.setting_indicators && user_config.num_lock_indicator)
        case SETTING_TOGGLE_SCROLL_LOCK_INDICATOR: RGB_INDICATE(user_config.setting_indicators && user_config.scroll_lock_indicator)
        case SETTING_TOGGLE_SETTING_INDICATORS: RGB_INDICATE(user_config.setting_indicators)
        case SETTING_TOGGLE_LAYER_MASK: RGB_INDICATE(user_config.setting_indicators && user_config.layer_mask)
        case SETTING_TOGGLE_BRIGHT_LAYER_MASK: RGB_INDICATE(user_config.setting_indicators && user_config.bright_layer_mask)
        case SETTING_TOGGLE_RGB_GRADIENT: RGB_INDICATE(user_config.setting_indicators && user_config.gradient)
        case SETTING_RGB_GRADIENT_DIRECTION_UP ... SETTING_RGB_GRADIENT_DIRECTION_LEFT: RGB_INDICATE(user_config.gradient_direction == (keycode - SETTING_RGB_GRADIENT_DIRECTION_UP))
        case SETTING_RGB_GRADIENT_INTENSITY_1 ... SETTING_RGB_GRADIENT_INTENSITY_10: RGB_INDICATE(user_config.gradient_intensity == (keycode - SETTING_RGB_GRADIENT_INTENSITY_1 + 1))
        case SETTING_TOGGLE_REACTIVE_RIPPLES: RGB_INDICATE(user_config.setting_indicators && user_config.ripples)
        case SETTING_RGB_RIPPLE_INTENSITY_1 ... SETTING_RGB_RIPPLE_INTENSITY_10: RGB_INDICATE(user_config.ripple_intensity == (keycode - SETTING_RGB_RIPPLE_INTENSITY_1 + 1))
        case SETTING_TOGGLE_RGB_PEEK: RGB_INDICATE(user_config.setting_indicators && user_config.rgb_peek)

        // RGB Setting Kecodes
        case RGB_SAI: RGB_INDICATE(rgb_matrix_config.hsv.s == 255)
        case RGB_SAD: RGB_INDICATE(rgb_matrix_config.hsv.s == 0)
        case RGB_VAI: RGB_INDICATE(rgb_matrix_config.hsv.v == 255)
        case RGB_VAD: RGB_INDICATE(rgb_matrix_config.hsv.v == 0)
        case RGB_SPI: RGB_INDICATE(rgb_matrix_config.speed == 255)
        case RGB_SPD: RGB_INDICATE(rgb_matrix_config.speed == 0)

        // RGB Mode Keycodes
        #ifdef RGB_MATRIX_ENABLE
            case RGB_MODE_SOLID: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SOLID_COLOR)
        #endif // RGB_MATRIX_ENABLE
        #ifdef ENABLE_RGB_MATRIX_BREATHING
            case RGB_MODE_BREATHING: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_BREATHING)
        #endif // ENABLE_RGB_MATRIX_BREATHING
        #ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
            case RGB_MODE_BAND_SPIRAL_VAL: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_BAND_SPIRAL_VAL)
        #endif // ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_ALL
            case RGB_MODE_CYCLE_ALL: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_ALL)
        #endif // ENABLE_RGB_MATRIX_CYCLE_ALL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
            case RGB_MODE_CYCLE_LEFT_RIGHT: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_LEFT_RIGHT)
        #endif // ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
        #ifdef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
            case RGB_MODE_CYCLE_UP_DOWN: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_UP_DOWN)
        #endif // ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
        #ifdef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
            case RGB_MODE_RAINBOW_MOVING_CHEVRON: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_RAINBOW_MOVING_CHEVRON)
        #endif // ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
        #ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
            case RGB_MODE_CYCLE_OUT_IN: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_OUT_IN)
        #endif // ENABLE_RGB_MATRIX_CYCLE_OUT_IN
        #ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
            case RGB_MODE_CYCLE_OUT_IN_DUAL: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_OUT_IN_DUAL)
        #endif // ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
            case RGB_MODE_CYCLE_PINWHEEL: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_PINWHEEL)
        #endif // ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
        #ifdef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
            case RGB_MODE_CYCLE_SPIRAL: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_CYCLE_SPIRAL)
        #endif // ENABLE_RGB_MATRIX_CYCLE_SPIRAL
        #ifdef ENABLE_RGB_MATRIX_DUAL_BEACON
            case RGB_MODE_DUAL_BEACON: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_DUAL_BEACON)
        #endif // ENABLE_RGB_MATRIX_DUAL_BEACON
        #ifdef ENABLE_RGB_MATRIX_RAINBOW_BEACON
            case RGB_MODE_RAINBOW_BEACON: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_RAINBOW_BEACON)
        #endif // ENABLE_RGB_MATRIX_RAINBOW_BEACON
        #ifdef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
            case RGB_MODE_FLOWER_BLOOMING: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_FLOWER_BLOOMING)
        #endif // ENABLE_RGB_MATRIX_FLOWER_BLOOMING
        #ifdef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
            case RGB_MODE_JELLYBEAN_RAINDROPS: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_JELLYBEAN_RAINDROPS)
        #endif // ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
        #ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
            case RGB_MODE_PIXEL_RAIN: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_PIXEL_RAIN)
        #endif // ENABLE_RGB_MATRIX_PIXEL_RAIN
        #ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
            case RGB_MODE_TYPING_HEATMAP: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_TYPING_HEATMAP)
        #endif // ENABLE_RGB_MATRIX_TYPING_HEATMAP
        #ifdef ENABLE_RGB_MATRIX_DIGITAL_RAIN
            case RGB_MODE_DIGITAL_RAIN: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_DIGITAL_RAIN)
        #endif // ENABLE_RGB_MATRIX_DIGITAL_RAIN
        #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
            case RGB_MODE_SOLID_REACTIVE_SIMPLE: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SOLID_REACTIVE_SIMPLE)
        #endif // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
        #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
            case RGB_MODE_SOLID_REACTIVE_MULTIWIDE: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE)
        #endif // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
        #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
            case RGB_MODE_SOLID_REACTIVE_MULTINEXUS: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS)
        #endif // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
        #ifdef ENABLE_RGB_MATRIX_SPLASH
            case RGB_MODE_SPLASH: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SPLASH)
        #endif // ENABLE_RGB_MATRIX_SPLASH
        #ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
            case RGB_MODE_SOLID_SPLASH: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SOLID_SPLASH)
        #endif // ENABLE_RGB_MATRIX_SOLID_SPLASH
        #ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
            case RGB_MODE_SOLID_MULTISPLASH: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_SOLID_MULTISPLASH)
        #endif // ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
        #ifdef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
            case RGB_MODE_STARLIGHT_DUAL_HUE: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_STARLIGHT_DUAL_HUE)
        #endif // ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
        #ifdef ENABLE_RGB_MATRIX_RIVERFLOW
            case RGB_MODE_RIVERFLOW: RGB_INDICATE(rgb_matrix_config.mode == RGB_MATRIX_RIVERFLOW)
        #endif // ENABLE_RGB_MATRIX_RIVERFLOW
    }

    if (user_config.gradient) {
        gradient(led_location.row, led_location.col, hsv);
    }

    if (user_config.ripples && !upper_layer) {
        ripple(led_index, hsv);
    }

    return false;
}

bool via_custom_value_command_user(uint8_t *data, uint8_t length) {
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            return via_user_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            return via_user_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            return via_user_set_save();
            break;
        }
    }

    return false;
}

bool via_user_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_caps_lock_indicator:
            *value_data = user_config.caps_lock_indicator;
            return true;
        case id_num_lock_indicator:
            *value_data = user_config.num_lock_indicator;
            return true;
        case id_scroll_lock_indicator:
            *value_data = user_config.scroll_lock_indicator;
            return true;
        case id_setting_indicators:
            *value_data = user_config.setting_indicators;
            return true;
        case id_layer_mask:
            *value_data = user_config.layer_mask;
            return true;
        case id_bright_layer_mask:
            *value_data = user_config.bright_layer_mask;
            return true;
        case id_gradient:
            *value_data = user_config.gradient;
            return true;
        case id_gradient_intensity:
            *value_data = user_config.gradient_intensity;
            return true;
        case id_gradient_direction:
            *value_data = user_config.gradient_direction;
            return true;
        case id_ripples:
            *value_data = user_config.ripples;
            return true;
        case id_ripple_intensity:
            *value_data = user_config.ripple_intensity;
            return true;
        case id_rgb_peek:
            *value_data = user_config.rgb_peek;
            return true;
    }

    return false;
}

bool via_user_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_caps_lock_indicator:
            user_config.caps_lock_indicator = *value_data;
            return true;
        case id_num_lock_indicator:
            user_config.num_lock_indicator = *value_data;
            return true;
        case id_scroll_lock_indicator:
            user_config.scroll_lock_indicator = *value_data;
            return true;
        case id_setting_indicators:
            user_config.setting_indicators = *value_data;
            return true;
        case id_layer_mask:
            user_config.layer_mask = *value_data;
            return true;
        case id_bright_layer_mask:
            user_config.bright_layer_mask = *value_data;
            return true;
        case id_gradient:
            user_config.gradient = *value_data;
            return true;
        case id_gradient_intensity:
            user_config.gradient_intensity = *value_data;
            reset_gradient_map(user_config.gradient_intensity, user_config.gradient_direction);
            if (user_config.rgb_peek) { peeking_timer = sync_timer_read32(); }
            return true;
        case id_gradient_direction:
            user_config.gradient_direction = *value_data;
            reset_gradient_map(user_config.gradient_intensity, user_config.gradient_direction);
            if (user_config.rgb_peek) { peeking_timer = sync_timer_read32(); }
            return true;
        case id_ripples:
            user_config.ripples = *value_data;
            return true;
        case id_ripple_intensity:
            user_config.ripple_intensity = *value_data;
            set_ripple_intensity(user_config.ripple_intensity);
            if (user_config.rgb_peek) { peeking_timer = sync_timer_read32(); }
            return true;
        case id_rgb_peek:
            user_config.rgb_peek = *value_data;
            return true;
    }
    return false;
}

bool via_user_set_save(void) {
    eeconfig_update_user(user_config.raw);
    return true;
}
