#ifndef __ALGO_SECTORS_H__
#define __ALGO_SECTORS_H__

#include <math.h>
#include "cocos2d.h"

bool intersectPointSector(float px, float py, float sx, float sy,
    float r, float startangle, float endangle);

bool intersectCircleSector(float cx, float cy, float cr,
    float sx, float sy, float sr, float startangle, float endangle);

#endif
