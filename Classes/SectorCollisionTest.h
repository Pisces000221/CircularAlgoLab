#ifndef __ALGOLAB_SECTOR_COLLISION_H__
#define __ALGOLAB_SECTOR_COLLISION_H__

#include "AppMacros.h"
#include "cocos2d.h"
using namespace cocos2d;

class SectorCollisionTest : public cocos2d::Layer
{
public:
    virtual bool init();  
    
    void goBack(Object* sender);
    
    CREATE_FUNC(SectorCollisionTest);
    SCENE_FUNC(SectorCollisionTest);
};

#endif
