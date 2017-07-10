#include "Box.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

bool Box::init(){

	//���ô�С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	size = Size(60, 60);
	setColor(Color3B::RED);
	setTag(11);

	//������������
	initPhysicsBody();

	//����ͼƬ
	auto block = Sprite::create("dirt1.png");
	this->addChild(block, 1);

	return true;
}

void Box::initPhysicsBody(){

	box = PhysicsBody::createBox(size);
	box->setDynamic(false);
	box->setContactTestBitmask(1);
	box->setTag(12);
	setPhysicsBody(box);
}

