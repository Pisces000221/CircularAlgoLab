#include "SectorCircleCollisionTest.h"
#include "cocos2d.h"
#include "MLogging.h"
#include "algo/sectors.h"

using namespace cocos2d;

#define SECTOR_TAG 637
#define SECTOR_X 240
#define SECTOR_Y 230
#define SECTOR_R 180
#define SECTOR_SA 10
#define SECTOR_EA 160
#define CIRCLE_R 30.0F

bool SectorCircleCollisionTest::init()
{
    if (!Layer::init()) return false;
    STD_TEST_INIT(SectorCircleCollisionTest);
    
    auto touchPointer = Sprite::create("circle.png");
    touchPointer->setColor(Color3B(255, 0, 0));
    touchPointer->setScale((CIRCLE_R * 2.0) / touchPointer->getContentSize().width);
    touchPointer->setVisible(false);
    this->addChild(touchPointer);
    // enable touching
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [=](Touch *touch, Event *event) {
        Point p = touch->getLocation();
        touchPointer->setPosition(p);
        if (intersectCircleSector(p.x, p.y, CIRCLE_R, SECTOR_X, SECTOR_Y,
            SECTOR_R, SECTOR_SA, SECTOR_EA))
            SET_NODE_C4F(this->getChildByTag(SECTOR_TAG), Color4F(0.6, 0.6, 1, 0.6));
        else
            SET_NODE_C4F(this->getChildByTag(SECTOR_TAG), Color4F(0, 0, 1, 0.6));
        touchPointer->setVisible(true);
        return true;
    };
    listener->onTouchMoved = [=](Touch *touch, Event *event) {
        Point p = touch->getLocation();
        touchPointer->setPosition(p);
        if (intersectCircleSector(p.x, p.y, CIRCLE_R, SECTOR_X, SECTOR_Y,
            SECTOR_R, SECTOR_SA, SECTOR_EA))
            SET_NODE_C4F(this->getChildByTag(SECTOR_TAG), Color4F(0.6, 0.6, 1, 0.6));
        else
            SET_NODE_C4F(this->getChildByTag(SECTOR_TAG), Color4F(0, 0, 1, 0.6));
    };
    listener->onTouchEnded = [=](Touch *touch, Event *event) {
        touchPointer->setVisible(false);
        SET_NODE_C4F(this->getChildByTag(SECTOR_TAG), Color4F(0, 0, 1, 0.6));
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    DRAW_SECTOR(Point(SECTOR_X, SECTOR_Y), SECTOR_R,
        Color4F(0, 0, 1, 0.6), SECTOR_SA, SECTOR_EA, SECTOR_TAG);
    
    return true;
}
