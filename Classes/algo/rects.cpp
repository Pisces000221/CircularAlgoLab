#include "rects.h"
#include <math.h>
//#include "cocos2d.h"

float lineBwithK(float x, float y, float k) { return y - k * x; }
float lineYforX(float k, float b, float x) { return k * x + b; }
float lineDeltaY(float k1, float b1, float k2, float b2) { return fabs(b1 - b2); }

#define feq(a, b) (fabs(a-b)<=1e-4)
////http://wenku.baidu.com/link?url=4CG8LWV-ZXU4yvunYSaOpbgbZf_Ze9MsoBLLxBuoYe2OC0JIoEnbOc4p2CJgTNODX-wycbdYpd7aev7VBq1AnJ_VZjiYOtcdyXSjYAOzC-3
#define RAD(theta) (theta * M_PI / 180.0)

bool intersectPointRect(float px, float py, float rx, float ry,
    float w, float h, float theta)
{
    theta = RAD(theta);
    float cos_theta = cos(theta), sin_theta = sin(theta);
    float x2 = rx + w*cos_theta - h*sin_theta;
    float y2 = ry + h*cos_theta + w*sin_theta;
    float k1 = sin_theta / cos_theta;       // tan(theta)
    float b1 = lineBwithK(rx, ry, k1);
    float k2 = k1;
    float b2 = lineBwithK(x2, y2, k2);
    float k3 = -1.0 / k1;
    float b3 = lineBwithK(rx, ry, k3);
    float k4 = k3;
    float b4 = lineBwithK(x2, y2, k4);
    //CCLOG("theta = %f", theta);
    //CCLOG("cos_theta = %f, sin_theta = %f", cos_theta, sin_theta);
    //CCLOG("p: (%f, %f)", px, py);
    //CCLOG("r: (%f, %f)", rx, ry);
    /*CCLOG("r\': (%f, %f)", x2, y2);
    CCLOG("l1: y = %f x + %f", k1, b1);
    CCLOG("l2: y = %f x + %f", k2, b2);
    CCLOG("l3: y = %f x + %f", k3, b3);
    CCLOG("l4: y = %f x + %f", k4, b4);*/
    return// true;
        feq(fabs(lineYforX(k3, b3, px) - py) + fabs(lineYforX(k4, b4, px) - py), lineDeltaY(k3, b3, k4, b4))
        && feq(fabs(lineYforX(k1, b1, px) - py) + fabs(lineYforX(k2, b2, px) - py), lineDeltaY(k1, b1, k2, b2));
}
