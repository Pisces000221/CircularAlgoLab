#ifndef __ALGOLAB_SECTOR_CIRCLE_COLLISION_H__
#define __ALGOLAB_SECTOR_CIRCLE_COLLISION_H__

#include "AppMacros.h"
#include "cocos2d.h"
using namespace cocos2d;

class SectorCircleCollisionTest : public cocos2d::Layer
{
public:
    virtual bool init();  
    
    void goBack(Object* sender);
    
    CREATE_FUNC(SectorCircleCollisionTest);
    SCENE_FUNC(SectorCircleCollisionTest);
};

#endif
