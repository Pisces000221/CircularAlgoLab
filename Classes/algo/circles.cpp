#include "circles.h"

bool intersectPointCircle(float px, float py, float cx, float cy, float cr)
{
    return (px - cx)*(px - cx) + (py - cy)*(py - cy) <= cr * cr;
}
