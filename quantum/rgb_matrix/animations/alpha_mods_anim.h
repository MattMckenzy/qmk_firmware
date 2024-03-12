#ifdef ENABLE_RGB_MATRIX_ALPHAS_MODS
RGB_MATRIX_EFFECT(ALPHAS_MODS)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// alphas = color1, mods = color2
bool ALPHAS_MODS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    HSV hsv2 = NEW_HSV(rgb_matrix_config.speed, hsv.s, hsv.v);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_hsv(i, hsv2);
        } else {
            rgb_matrix_set_hsv(i, hsv);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_ALPHAS_MODS
