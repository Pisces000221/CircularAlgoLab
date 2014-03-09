#ifndef __ALGOLAB_RECT_COLLISION_H__
#define __ALGOLAB_RECT_COLLISION_H__

#include "AppMacros.h"
#include "cocos2d.h"
using namespace cocos2d;

class RectCollisionTest : public cocos2d::Layer
{
public:
    virtual bool init();  
    
    void goBack(Object* sender);
    
    CREATE_FUNC(RectCollisionTest);
    SCENE_FUNC(RectCollisionTest);
};

#endif
