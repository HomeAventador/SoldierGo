#include "Missile.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

bool Missile::init(){


	setTag(50);
	Size s = Size(50, 50);
	auto box = PhysicsBody::createBox(s);
	box->setTag(51);
	setPhysicsBody(box);
	setColor(Color3B(0, 0, 0));
	setAnchorPoint(Point(0.5, 0.5));
	getPhysicsBody()->setContactTestBitmask(1);
	
	auto block = Sprite::create("missile.png");
	block->setScale(0.75);
	this->addChild(block, 1);

	return true;
}
void Missile::left(){
	getPhysicsBody()->setVelocity(Vec2(-500, 0));
}

void Missile::right(){
	getPhysicsBody()->setVelocity(Vec2(500, 0));
}