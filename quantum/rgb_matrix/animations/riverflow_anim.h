#ifdef ENABLE_RGB_MATRIX_RIVERFLOW
RGB_MATRIX_EFFECT(RIVERFLOW)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// inspired by @PleasureTek's Massdrop Alt LED animation

bool RIVERFLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV      hsv  = rgb_matrix_config.hsv;
        uint16_t time = scale16by8(g_rgb_timer + (i * 315), rgb_matrix_config.speed / 8);
        hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);

        rgb_matrix_set_hsv(i, hsv);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_RIVERFLOW
