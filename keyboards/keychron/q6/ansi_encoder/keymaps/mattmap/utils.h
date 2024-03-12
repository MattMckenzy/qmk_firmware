#include "color.h"

typedef struct gradient_change {
    uint8_t value: 8;
    bool add: 1;
} PACKED gradient_change;

void set_indicator_hsv(HSV* hsv);

void hsv_brighter(HSV* hsv, uint8_t add);

void set_ripple_intensity(uint8_t intensity);
void ripple(uint8_t led_index, HSV* hsv);

void reset_gradient_map(uint8_t gradient_intensity, uint8_t gradient_direction);
void gradient(uint8_t led_row, uint8_t led_col, HSV* hsv);
