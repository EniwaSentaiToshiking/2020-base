#pragma once

#include "ColorSensor.h"
#include "DebugUtil.h"
#include <stdlib.h>
using namespace ev3api;

class ColorSensorDeviceDriver
{
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
    rgb_raw_t rgb;
    ColorSensor colorSensor;
    DebugUtil d;
    FILE *loggingFile;
    // int calcHSV(int red, int green, int blue);
};