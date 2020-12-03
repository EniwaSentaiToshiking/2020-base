#include "ColorDetector.h"

ColorDetector::ColorDetector(int threshold)
{
    courseMonitor = new CourseMonitor();
    this->threshold = threshold;
}

ColorDetector::~ColorDetector()
{
    delete courseMonitor;
}

void ColorDetector::init()
{
}

bool ColorDetector::detect()
{
    int currentColor = courseMonitor->getColorNumber();

    color_buffer[color_buffer_num] = currentColor;

    if (color_buffer_num == color_buffer_max - 1)
    {
        color_buffer_num = 0;
    }
    else
    {
        color_buffer_num++;
    }

    color_count++;

    if (color_count > color_buffer_max)
    {
        int count = 0;

        for (int i = 0; i < color_buffer_max; i++)
        {
            if (threshold == 8)
            {
                if (currentColor >= 2 && currentColor <= 5)
                    count++;
            }
            else
            {
                if (currentColor == threshold)
                    count++;
            }
        }

        if (count == color_buffer_max)
        {
            return true;
        }
    }

    return false;
}
