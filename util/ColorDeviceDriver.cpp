#include "ColorDeviceDriver.h"

ColorDeviceDriver::ColorDeviceDriver(): colorSensor(PORT_3)
{
}

void ColorDeviceDriver::getRawColor() 
{
    colorSensor.getRawColor(rgb);
}

int8_t ColorDeviceDriver::getBrightness()
{
    return colorSensor.getBrightness();
}

int8_t ColorDeviceDriver::getAmbient()
{
    return colorSensor.getAmbient();
}

colorid_t ColorDeviceDriver::getColorNumber()
{
    getRawColor();
    int red = rgb.r;
    int green = rgb.g;
    int blue = rgb.b;
    // 六角錐モデル(HSV)
    int H = 0; // H < 0が仮定されている
    int S = 0;
    // int V = 0;
    int colorBrightnessMax = 0; // (0~255)
    int colorBrightnessMin = 0; // (0~255)
    colorid_t max_rgb = COLOR_NONE;

    char buffer[30];
    snprintf(buffer, sizeof(buffer), "R %d, G %d, B %d", red, green, blue);
    d.lcd_msg_debug(buffer, 3);

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

    //色相を計算
    switch (max_rgb)
    {
    case COLOR_RED:
        H = ((int)(60 * ((green - blue) / (double)(colorBrightnessMax - colorBrightnessMin))) + 360);
        break;
    case COLOR_GREEN:
        H = ((int)(60 * ((blue - red) / (double)(colorBrightnessMax - colorBrightnessMin))) + 120);
        break;
    case COLOR_BLUE:
        H = ((int)(60 * ((red - green) / (double)(colorBrightnessMax - colorBrightnessMin))) + 240);
        break;
    case COLOR_NONE:
        H = 0;
    default:
        break;
    }

    // 彩度を計算
    S = colorBrightnessMax - colorBrightnessMin;
    // printf("H: %d, S: %d, max color id %d\n", H, S, max_rgb);
    snprintf(buffer, sizeof(buffer), "max, %d, min,%d,", colorBrightnessMax, colorBrightnessMin);
    d.lcd_msg_debug(buffer, 4);
    snprintf(buffer, sizeof(buffer), "H,%d, S,%d, maxc,%d, ", H, S, max_rgb);
    d.lcd_msg_debug(buffer, 5);
    //閾値で色判定
    if (S < 20)
    {
        return COLOR_BLACK;
    }
    if (H >= 10 && H < 30 && S >= 20)
    {
        return COLOR_RED;
    }
    if (H >= 40 && H < 60 && S >= 40)
    {
        return COLOR_YELLOW;
    }
    if (H >= 100 && H < 130 && S >= 20)
    {
        return COLOR_GREEN;
    }
    if (H >= 155 && H < 210 && S >= 20)
    {
        return COLOR_BLUE;
    }

    return COLOR_NONE;
}