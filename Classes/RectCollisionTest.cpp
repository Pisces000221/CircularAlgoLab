#include "RectCollisionTest.h"
#include "cocos2d.h"
#include "MLogging.h"
#include "algo/rects.h"

using namespace cocos2d;

#define RECT_TAG 637
#define RECT_X 340
#define RECT_Y 260
#define RECT_WIDTH 200
#define RECT_HEIGHT 80
#define RECT_THETA 30

bool RectCollisionTest::init()
{
    if (!Layer::init()) return false;
    STD_TEST_INIT(RectCollisionTest);
    
    auto touchPointer = Sprite::create("circle.png");
    touchPointer->setColor(Color3B(255, 0, 0));
    touchPointer->setScale(10.0 / touchPointer->getContentSize().width);
    touchPointer->setVisible(false);
    this->addChild(touchPointer);
    // enable touching
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [=](Touch *touch, Event *event) {
        Point p = touch->getLocation();
        touchPointer->setPosition(p);
        if (intersectPointRect(p.x, p.y, RECT_X, RECT_Y,
            RECT_WIDTH, RECT_HEIGHT, RECT_THETA))
            REDRAW_RECT(RECT_TAG, Point(RECT_X, RECT_Y),
                RECT_WIDTH, RECT_HEIGHT, Color4F(1, 0.6, 1, 0.6));
        else
            REDRAW_RECT(RECT_TAG, Point(RECT_X, RECT_Y),
                RECT_WIDTH, RECT_HEIGHT, Color4F(1, 0, 1, 0.6));
        touchPointer->setVisible(true);
        return true;
    };
    listener->onTouchMoved = [=](Touch *touch, Event *event) {
        Point p = touch->getLocation();
        touchPointer->setPosition(p);
        if (intersectPointRect(p.x, p.y, RECT_X, RECT_Y,
            RECT_WIDTH, RECT_HEIGHT, RECT_THETA))
            REDRAW_RECT(RECT_TAG, Point(RECT_X, RECT_Y),
                RECT_WIDTH, RECT_HEIGHT, Color4F(1, 0.6, 1, 0.6));
        else
            REDRAW_RECT(RECT_TAG, Point(RECT_X, RECT_Y),
                RECT_WIDTH, RECT_HEIGHT, Color4F(1, 0, 1, 0.6));
    };
    listener->onTouchEnded = [=](Touch *touch, Event *event) {
        touchPointer->setVisible(false);
        REDRAW_RECT(RECT_TAG, Point(RECT_X, RECT_Y),
            RECT_WIDTH, RECT_HEIGHT, Color4F(1, 0, 1, 0.6));
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    DRAW_RECT(Point(RECT_X, RECT_Y), RECT_WIDTH, RECT_HEIGHT,
        Color4F(1, 0, 1, 0.6), RECT_THETA, RECT_TAG);
    
    return true;
}
