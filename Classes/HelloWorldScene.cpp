#include "HelloWorldScene.h"
#include "RectCollisionTest.h"
#include "SectorCollisionTest.h"
#include "SectorCircleCollisionTest.h"

USING_NS_CC;

bool HelloWorld::init()
{
    if (!Layer::init()) return false;
    
    Size visSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Point(visSize.width/2 + origin.x, visSize.height/2 + origin.y));
    sprite->setScale(2);
    this->addChild(sprite);
    auto cover = LayerColor::create(Color4B(255, 255, 255, 100));
    //cover->setOpacity(100);
    this->addChild(cover);
    
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png", "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    closeItem->setAnchorPoint(Point(1, 0));
	closeItem->setPosition(Point(origin.x + visSize.width, origin.y));
    
    auto label = Label::createWithTTF(TTFConfig("fonts/Ubuntu-R.ttf", 36), "Sector Collision Test");
    label->setColor(Color3B(0, 0, 0));
    auto sectorCollisionTest = MenuItemLabel::create(
        label, [=](Object *sender) {
            auto newScene = SectorCollisionTest::createScene();
            Director::getInstance()->pushScene(newScene); });
    sectorCollisionTest->setPosition(Point(300, 400));
    
    label = Label::createWithTTF(TTFConfig("fonts/Ubuntu-R.ttf", 36), "Sector & Circle Collision Test");
    label->setColor(Color3B(0, 0, 0));
    auto sectorCircleCollisionTest = MenuItemLabel::create(
        label, [=](Object *sender) {
            auto newScene = SectorCircleCollisionTest::createScene();
            Director::getInstance()->pushScene(newScene); });
    sectorCircleCollisionTest->setPosition(Point(300, 440));
    
    label = Label::createWithTTF(TTFConfig("fonts/Ubuntu-R.ttf", 36), "Rectangle Collision Test");
    label->setColor(Color3B(0, 0, 0));
    auto rectCollisionTest = MenuItemLabel::create(
        label, [=](Object *sender) {
            auto newScene = RectCollisionTest::createScene();
            Director::getInstance()->pushScene(newScene); });
    rectCollisionTest->setPosition(Point(300, 480));

    auto menu = Menu::create(closeItem,
        sectorCollisionTest, sectorCircleCollisionTest, rectCollisionTest, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    label = Label::createWithTTF(
        TTFConfig("fonts/Ubuntu-B.ttf", 48),
        "TESTS FOR\nCIRCULAR COLLISION DETECTION", TextHAlignment::CENTER);
    label->setPosition(Point(
        origin.x, origin.y + visSize.height - label->getContentSize().height));
    label->setColor(Color3B(0, 0, 0));
    this->addChild(label, 1);
    
    return true;
}


void HelloWorld::menuCloseCallback(Object* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
