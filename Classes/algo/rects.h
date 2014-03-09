#ifndef __ALGO_RECTS_H__
#define __ALGO_RECTS_H__

float lineBwithK(float x, float y, float k);
float lineYforX(float k, float b, float x);
float lineDeltaY(float k1, float b1, float k2, float b2);

bool intersectPointRect(float px, float py, float rx, float ry,
    float w, float h, float theta);

#endif
