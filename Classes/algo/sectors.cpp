#include "sectors.h"
#include "rects.h"
#include "circles.h"
#include "angles.h"
#include <math.h>
//#include "cocos2d.h"

#define RAD(theta) (theta * M_PI / 180.0)
#define DEG(theta) (theta * 180.0 / M_PI)
#define SIGN(x) (x > 0)
#define CONV_ANGLE(a) (90.0 - a)

bool intersectPointSector(float px, float py, float sx, float sy,
    float r, float startangle, float endangle)
{
    float theta = CONV_ANGLE(DEG(atan2f(py - sy, px - sx)));
    //CCLOG("DEBUG 0001: %f %f %f", theta, startangle, endangle);
    float distsq = (sy - py)*(sy - py) + (sx - px)*(sx - px);
    return (distsq <= r * r) && intersectRayAngle(theta, startangle, endangle);
}

bool intersectCircleSector(float cx, float cy, float cr,
    float sx, float sy, float sr, float startangle, float endangle)
{
    float sa2 = uniformAngle(CONV_ANGLE(startangle));
    float ea2 = uniformAngle(CONV_ANGLE(endangle));
    float ea3 = ea2 - 90;
    //CCLOG("DEBUG 0002: %f %f", sa2, ea2);
    return
        intersectPointSector(cx, cy, sx, sy, sr + cr, startangle, endangle)
        || intersectPointRect(cx, cy, sx, sy, sr, cr, sa2)
        || intersectPointRect(cx, cy, sx, sy, cr, sr, ea3)
        || intersectPointCircle(cx, cy, sx + sr*cos(RAD(sa2)), sy + sr*sin(RAD(sa2)), cr)
        || intersectPointCircle(cx, cy, sx + sr*cos(RAD(ea2)), sy + sr*sin(RAD(ea2)), cr)
        || intersectPointCircle(cx, cy, sx, sy, cr);
        //intersectPointRect(cx, cy, sx, sy, cr, sr, ea2);
}
