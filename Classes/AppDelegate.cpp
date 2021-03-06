#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // director and window initialisation
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
