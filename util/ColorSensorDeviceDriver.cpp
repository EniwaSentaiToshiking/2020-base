#include "ColorSensorDeviceDriver.h"

ColorSensorDeviceDriver::ColorSensorDeviceDriver(): colorSensor(PORT_3)
{
}

void ColorSensorDeviceDriver::init()
{
    loggingFile = fopen("logging_file.csv", "a");
    if (loggingFile == NULL)
    {
        d.lcd_msg_debug("error: cannot open file", 2);
        exit(1);
    }
    fprintf(loggingFile, "Brightness,R,G,B,H,S,V,ColorNum\n");
}

void ColorSensorDeviceDriver::getRawColor() 
{
    colorSensor.getRawColor(rgb);
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
    int red = rgb.r;
    int green = rgb.g;
    int blue = rgb.b;
    // 六角錐モデル(HSV)
    int H = 0; // (0~359)
    int S = 0; // (0~255)
    int V = 0; // (0~255)
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

    //色相(Hue)を計算
    switch (max_rgb)
    {
    case COLOR_RED:
        H = ((60 * (green - blue) / (colorBrightnessMax - colorBrightnessMin)) + 360);
        H = H % 360; // scaling(0~359)
        break;
    case COLOR_GREEN:
        H = ((60 * (blue - red) / (colorBrightnessMax - colorBrightnessMin)) + 120);
        H = H % 360;
        break;
    case COLOR_BLUE:
        H = ((60 * (red - green) / (colorBrightnessMax - colorBrightnessMin)) + 240);
        H = H % 360;
        break;
    case COLOR_NONE:
        H = 0;
    default:
        break;
    }

    // 彩度(Saturation)の計算
    S = colorBrightnessMax - colorBrightnessMin;

    // 明度(Value)の計算
    V = colorBrightnessMax;

    // printf("H: %d, S: %d, max color id %d\n", H, S, max_rgb);
    snprintf(buffer, sizeof(buffer), "max, %d, min,%d,", colorBrightnessMax, colorBrightnessMin);
    d.lcd_msg_debug(buffer, 4);
    snprintf(buffer, sizeof(buffer), "H,%d, S,%d, V,%d, maxc,%d, ", H, S, V, max_rgb);
    d.lcd_msg_debug(buffer, 5);
    //閾値で色判定
    bool isRed = ((0 <= H && H < 30) || (270 <= H && H <= 359)) && (20 <= S);
    bool isYellow = (30 <= H && H < 90) && (50 <= S);
    bool isGreen = (90 <= H && H < 150) && (20 <= S);
    bool isBlue = (150 <= H && H < 270) && (20 <= S);
    bool isBlack = (V <= 100) && (S < 50);
    bool isWhite = (100 < V) && (S < 50);
    colorid_t colorId = COLOR_NONE;
    if (isRed)
    {
        colorId = COLOR_RED;
        // return COLOR_RED;
    }
    if (isBlue)
    {
        colorId = COLOR_BLUE;
        // return COLOR_BLUE;
    }
    if (isYellow)
    {
        colorId = COLOR_YELLOW;
        // return COLOR_YELLOW;
    }
    if (isGreen)
    {
        colorId = COLOR_GREEN;
        // return COLOR_GREEN;
    }
    if (isBlack)
    {
        colorId = COLOR_BLACK;
        // return COLOR_BLACK;
    }
    if (isWhite)
    {
        colorId = COLOR_WHITE;
        // return COLOR_WHITE;
    }

    fprintf(loggingFile, "%d,%d,%d,%d,%d,%d,%d,%d\n",getBrightness(),red,green,blue,H,S,V,colorId);
    return colorId;
}

void ColorSensorDeviceDriver::terminate()
{
    fclose(loggingFile);
}