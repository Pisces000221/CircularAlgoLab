#include "angles.h"

float uniformAngle(float angle)
{
    while (angle < 0) angle += 360;
    while (angle > 360) angle -= 360;
    return angle;
}

bool intersectRayAngle(float rayangle, float startangle, float endangle)
{
    rayangle = uniformAngle(rayangle);
    startangle = uniformAngle(startangle);
    endangle = uniformAngle(endangle);
    if (startangle > endangle) {
        if (rayangle < endangle) rayangle += 360;
        endangle += 360;
    }
    return rayangle >= startangle && rayangle <= endangle;
}
