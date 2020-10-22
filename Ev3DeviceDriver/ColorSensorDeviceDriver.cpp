#include "ColorSensorDeviceDriver.h"

ColorSensorDeviceDriver::ColorSensorDeviceDriver(): colorSensor(PORT_3)
{
    // loggingFile = fopen("logging_file_yellow_stop.csv", "rw");
    // if (loggingFile == NULL)
    // {
    //     d.lcd_msg_debug("error: cannot open file", 2);
    //     exit(1);
    // }
    // fprintf(loggingFile, "Brightness,R,G,B,H,S,V,ColorNum\n");
}

void ColorSensorDeviceDriver::init()
{
    d.init("ColorSensorDeviceDriver");
}

void ColorSensorDeviceDriver::getRawColor() 
{
    colorSensor.getRawColor(rawrgb);
}

int8_t ColorSensorDeviceDriver::getBrightness()
{
    return colorSensor.getBrightness();
}

int8_t ColorSensorDeviceDriver::getAmbient()
{
    return colorSensor.getAmbient();
}

colorid_t ColorSensorDeviceDriver::getColorNumber()
{
    getRawColor();
    hsv = calcHSV(rawrgb);
    bool isRed = ((0 <= hsv.h && hsv.h < 30) || (270 <= hsv.h && hsv.h <= 359)) && (20 <= hsv.s);
    bool isYellow = (30 <= hsv.h && hsv.h < 90) && (50 <= hsv.s);
    bool isGreen = (90 <= hsv.h && hsv.h < 150) && (20 <= hsv.s);
    bool isBlue = (150 <= hsv.h && hsv.h < 270) && (20 <= hsv.s);
    bool isBlack = (hsv.v <= 100) && (hsv.s < 50);
    bool isWhite = (100 < hsv.v) && (hsv.s < 50);
    if (isRed)
    {
        colorId = COLOR_RED;
    }
    if (isBlue)
    {
        colorId = COLOR_BLUE;
    }
    if (isYellow)
    {
        colorId = COLOR_YELLOW;
    }
    if (isGreen)
    {
        colorId = COLOR_GREEN;
    }
    if (isBlack)
    {
        colorId = COLOR_BLACK;
    }
    if (isWhite)
    {
        colorId = COLOR_WHITE;
    }

    return colorId;
}

hsv_t ColorSensorDeviceDriver::calcHSV(rgb_raw_t rgb)
{
    int red = rgb.r;
    int green = rgb.g;
    int blue = rgb.b;
    int colorBrightnessMax = 0; // (0~255)
    int colorBrightnessMin = 0; // (0~255)
    colorid_t max_rgb = COLOR_NONE;

    //rgbの最小値計算
    if (red <= green && red <= blue)
    {
        colorBrightnessMin = red;
    }

    if (green <= red && green <= blue)
    {
        colorBrightnessMin = green;
    }

    if (blue <= red && blue <= green)
    {
        colorBrightnessMin = blue;
    }

    //rgbの最大値計算
    if (red >= green && red >= blue)
    {
        colorBrightnessMax = red;
        max_rgb = COLOR_RED;
    }

    if (green >= red && green >= blue)
    {
        colorBrightnessMax = green;
        max_rgb = COLOR_GREEN;
    }

    if (blue >= green && blue >= red)
    {
        colorBrightnessMax = blue;
        max_rgb = COLOR_BLUE;
    }

    if (red == green && green == blue)
    {
        max_rgb = COLOR_NONE;
    }

    //色相(Hue)を計算
    switch (max_rgb)
    {
    case COLOR_RED:
        hsv.h = ((60 * (green - blue) / (colorBrightnessMax - colorBrightnessMin)) + 360);
        hsv.h = hsv.h % 360; // scaling(0~359)
        break;
    case COLOR_GREEN:
        hsv.h = ((60 * (blue - red) / (colorBrightnessMax - colorBrightnessMin)) + 120);
        hsv.h = hsv.h % 360;
        break;
    case COLOR_BLUE:
        hsv.h = ((60 * (red - green) / (colorBrightnessMax - colorBrightnessMin)) + 240);
        hsv.h = hsv.h % 360;
        break;
    case COLOR_NONE:
        hsv.h = 0;
    default:
        break;
    }

    // 彩度(Saturation)の計算
    hsv.s = colorBrightnessMax - colorBrightnessMin;

    // 明度(Value)の計算
    hsv.v = colorBrightnessMax;

    return hsv;
}

void ColorSensorDeviceDriver::terminate()
{
    // fclose(loggingFile);
}