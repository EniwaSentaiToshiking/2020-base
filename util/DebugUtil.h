#pragma once

#include "ev3api.h"

class DebugUtil
{
public:
    DebugUtil();
    void init(const char *str);
    void lcd_msg_debug(const char *str, int32_t line);
    void lcd_num_debug(float num, int32_t line);
    void led_debug(ledcolor_t ledColor);

private:
    static const int8_t line_height = 20;
    char lcd_buffer[30];
};
