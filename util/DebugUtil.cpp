#include "DebugUtil.h"

DebugUtil::DebugUtil()
{
}

// 初期処理用
void DebugUtil::init(const char *str) 
{
  // フォントの設定と0行目の表示
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(str, 0, 0);
}

/**
 * EV3の液晶画面に行単位で引数の文字列を表示
 * @param str 表示する文字列
 * @param line 20ドットごとの行番号（1から5）
 */
void DebugUtil::lcd_msg_debug(const char *str, int32_t line)
{
  ev3_lcd_fill_rect(0, line * line_height, EV3_LCD_WIDTH, line_height, EV3_LCD_WHITE);
  ev3_lcd_draw_string(str, 0, line * line_height);
}

void DebugUtil::lcd_num_debug(float num, int32_t line)
{
  snprintf(lcd_buffer, sizeof(lcd_buffer), "%0.2f,", num);
  lcd_msg_debug(lcd_buffer, line);
}

void DebugUtil::led_debug(ledcolor_t ledColor)
{
  ev3_led_set_color(ledColor);
}