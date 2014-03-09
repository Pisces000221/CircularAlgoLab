#ifndef __ALGOLAB_APP_MACROS_H__
#define __ALGOLAB_APP_MACROS_H__

#include "MLogging.h"

#define SCENE_FUNC(type) \
static cocos2d::Scene* createScene() \
{ \
    auto scene = cocos2d::Scene::create(); \
    auto layer = type::create(); \
    scene->addChild(layer); \
    return scene; \
}

#define STD_TEST_INIT(type) do { \
    Size visSize = Director::getInstance()->getVisibleSize(); \
    auto backItem = MenuItemImage::create( \
        "CloseNormal.png", "CloseSelected.png", \
        [=](Object* sender) { Director::getInstance()->popScene(); }); \
    backItem->setAnchorPoint(Point::ANCHOR_TOP_LEFT); \
    backItem->setPosition(Point(0, visSize.height)); \
    auto menu = Menu::create(backItem, NULL); \
    menu->setPosition(Point::ZERO); \
    this->addChild(menu); \
    auto label = Label::createWithTTF( \
        TTFConfig("fonts/Ubuntu-B.ttf", 36), #type); \
    label->setAnchorPoint(Point::ANCHOR_TOP_LEFT); \
    label->setPosition(Point( \
        backItem->getContentSize().width, visSize.height)); \
    this->addChild(label); } while (0)

#define SET_NODE_C4F(node, colour) do { \
    node->setColor(Color3B(colour.r * 255.0, colour.g * 255.0, colour.b * 255.0)); \
    node->setOpacity(colour.a * 255.0); } while (0)

#define DRAW_SECTOR(centre, radius, colour, beginangle, endangle, tag) do { \
    auto pt = ProgressTimer::create(Sprite::create("circle.png")); \
    pt->setType(ProgressTimer::Type::RADIAL); \
    pt->setPosition(centre); \
    pt->setTag(tag); \
    SET_NODE_C4F(pt, colour); \
    pt->setScale((float)(radius + radius) / pt->getContentSize().width); \
    pt->setRotation(beginangle); \
    pt->setPercentage(((float)endangle - (float)beginangle) / 3.6); \
    this->addChild(pt); } while (0)

#define DRAW_RECT(pos, width, height, colour, angle, tag) do { \
    auto dn = DrawNode::create(); \
    dn->setPosition(pos); \
    dn->setTag(tag); \
    dn->setContentSize(Size(width, height)); \
    dn->setRotation(-angle); \
    Point verts[4] = { Point(0, 0), Point(0, height), Point(width, height), Point(width, 0) }; \
    dn->drawPolygon(verts, 4, colour, 0, Color4F(0, 0, 0, 0)); \
    this->addChild(dn); } while (0)

#define REDRAW_RECT(tag, pos, width, height, colour) do { \
    auto node = (DrawNode *)(this->getChildByTag(tag)); \
    node->clear(); \
    Point verts[4] = { Point(0, 0), Point(0, height), Point(width, height), Point(width, 0) }; \
    node->drawPolygon(verts, 4, colour, 0, Color4F(0, 0, 0, 0)); } while (0)

#endif
