#include "utils.h"

#include <lib/lib8tion/lib8tion.h>
#include <stdint.h>
#include "color.h"
#include "rgb_matrix.h"

uint8_t dipEffect, peakEffect, dip2Effect, hsvEffect, hsvQuarterEffect;

gradient_change PROGMEM gradient_map[MATRIX_ROWS][MATRIX_COLS];

uint8_t middle_row = MATRIX_ROWS / 2;
uint8_t middle_col = MATRIX_COLS / 2;

void set_indicator_hsv(HSV* hsv) {
    hsv->h = add8(hsv->h, 127);
    hsv->s = 255;
    hsv->v = 255;
}

void hsv_brighter(HSV* hsv, uint8_t add) {
    uint8_t v_rem = qsub8(255, hsv->v);
    if (v_rem >= add) {
        hsv->v = qadd8(hsv->v, add);
    } else {
        hsv->v = 255;
        uint8_t rem = qsub8(add, v_rem);
        hsv->s = qsub8(hsv->s, rem);
    }
}

void set_ripple_intensity(uint8_t intensity) {
    dipEffect = intensity;
    peakEffect = dipEffect + (intensity * 2);
    dip2Effect = peakEffect + intensity;
    hsvEffect = intensity * 25;
    hsvQuarterEffect = hsvEffect / 4;
}

void ripple(uint8_t led_index, HSV* hsv) {
    uint8_t count = g_last_hit_tracker.count;

    for (uint8_t j = 0; j < count; j++) {
        int16_t  dx   = g_led_config.point[led_index].x - g_last_hit_tracker.x[j];
        int16_t  dy   = g_led_config.point[led_index].y - g_last_hit_tracker.y[j];
        uint8_t  dist = sqrt16(dx * dx + dy * dy);
        uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
        uint16_t effect = tick - dist;
        if (effect >= 0 && effect < dipEffect) {
            hsv->v = qsub8(hsv->v, hsvQuarterEffect);
        }
        else if (effect >= dipEffect && effect < peakEffect) {
            hsv_brighter(hsv, hsvEffect);
        }
        else if (effect >= peakEffect && effect < dip2Effect) {
            hsv->v = qsub8(hsv->v, hsvQuarterEffect);
        }
    }
}

void reset_gradient_map(uint8_t gradient_intensity, uint8_t gradient_direction) {
    uint8_t row_intensity = (gradient_intensity * 36) / MATRIX_ROWS;
    uint8_t col_intensity = (gradient_intensity * 36) / MATRIX_COLS;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            gradient_change gradient_change;
            switch (gradient_direction) {
                case 0:
                    gradient_change.add = row < middle_row ? 1 : 0;
                    gradient_change.value = (row < middle_row ? middle_row - row : row - middle_row) * row_intensity;
                    break;
                case 1:
                    gradient_change.add = col < middle_col ? 0 : 1;
                    gradient_change.value = (col < middle_col ? middle_col - col : col - middle_col) * col_intensity;
                    break;
                case 2:
                    gradient_change.add = row < middle_row ? 0 : 1;
                    gradient_change.value = (row < middle_row ? middle_row - row : row - middle_row) * row_intensity;
                    break;
                case 3:
                    gradient_change.add = col < middle_col ? 1 : 0;
                    gradient_change.value = (col < middle_col ? middle_col - col : col - middle_col) * col_intensity;
                    break;
            }
            gradient_map[row][col] = gradient_change;
        }
    }
}

void gradient(uint8_t led_row, uint8_t led_col, HSV* hsv) {
    gradient_change gradient_change = gradient_map[led_row][led_col];
    if (gradient_change.add)
        hsv_brighter(hsv, gradient_change.value);
    else
        hsv->v = qsub8(hsv->v, gradient_change.value);
}
