#include <Arduino.h>
#include <Thing.h>
#include <WebThingAdapter.h>

void init_webthing(int brightness);
int get_oled_brightness();
void set_oled_brightness(int brightness);
void update_webthing(int lx, float tempC, float temp, float hum, int adc);
