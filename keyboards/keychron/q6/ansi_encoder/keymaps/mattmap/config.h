#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Define these to enable key highlighting to indicate active lock or setting.

#define ENABLE_CAPS_LOCK_HIGHLIGHTING
#define ENABLE_NUM_LOCK_HIGHLIGHTING
#define ENABLE_SCROLL_LOCK_HIGHLIGHTING
#define ENABLE_SETTINGS_HIGHLIGHTING


// Define these to configure RGB modifiers

#define ENABLE_LAYER_HIGHLIGHTING
#define ALWAYS_ON_LAYER_HIGHLIGHTING // Define this to make sure layer highlighted keys are at max brightness.

#define ENABLE_GRADIENT_LIGHTING
#define DEFAULT_GRADIENT_INTENSITY 5 // Between 1-10
#define DEFAULT_GRADIENT_DIRECTION 0 // Brightest direction: 0 for up, 1 for right, 2 for down, 3 for left.

#define ENABLE_REACTIVE_RIPPLES
#define DEFAULT_RIPPLE_INTENSITY 5 // Between 1-10

#define ENABLE_RGB_PEEK // Enables the RGB peek feature to make sure all keys are visible while changing RGB settings. I.e. disables layer highlighting, and lock key indicators.


// Define a nice default RGB effect

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 125
#define RGB_MATRIX_DEFAULT_SAT 127
#define RGB_MATRIX_DEFAULT_VAL 150
#define RGB_MATRIX_DEFAULT_SPD 50


// Adding some extra RGB effects.

#define ENABLE_RGB_MATRIX_RIVERFLOW
#define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
