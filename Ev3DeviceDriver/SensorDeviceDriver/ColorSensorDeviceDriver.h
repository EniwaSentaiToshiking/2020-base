#pragma once

#include "ColorSensor.h"
#include "DebugUtil.h"
#include <stdlib.h>
using namespace ev3api;

// 六角錐モデル(HSV)
typedef struct
{
    int16_t h; //　Hue 色相 (0~359)
    int16_t s; //  Saturation 彩度 (0~255)
    int16_t v; //  Value 明度(0~255)
} hsv_t;

class ColorSensorDeviceDriver
{
    rgb_raw_t rawrgb;
    hsv_t hsv;
    ColorSensor colorSensor;

public:
    ColorSensorDeviceDriver();
    void init();
    /**
     * カラーセンサーからRGBを取得する
     * 
     * @param -
     * @return rgb_raw_t rgb (0-255)
     */
    void getRawColor(void);
    
    /**
     * 反射光の強さを測定する
     * @param -
     * @return 反射光の強さ (0-100)
     */
    int8_t getBrightness(void);

    /**
     * 環境光の強さを測定する
     * @param -
     * @return 環境光の強さ（0〜100）
     */
    int8_t getAmbient(void);
    
    /**
     * 六角錐色判別器を使用した色取得　色の範囲(0~255)
     * @param -
     * @return 識別した色
     */
    colorid_t getColorNumber(void);
    void terminate();

private:
    colorid_t colorId = COLOR_NONE;
    hsv_t calcHSV(rgb_raw_t rgb);

    /* debug */
    DebugUtil d;
    FILE *loggingFile;
};