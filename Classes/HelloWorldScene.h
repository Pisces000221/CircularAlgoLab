#ifndef __ALGOLAB_HELLOWORLD_SCENE_H__
#define __ALGOLAB_HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"

class HelloWorld : public cocos2d::Layer
{
public:
    virtual bool init();  
    
    void menuCloseCallback(Object* sender);
    
    CREATE_FUNC(HelloWorld);
    SCENE_FUNC(HelloWorld);
};

#endif
