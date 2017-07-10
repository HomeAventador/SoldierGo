#include "Trap.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace CocosDenshion;


bool Trap::init(){

	//���ô�С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	size = Size(80, 80);
	setColor(Color3B::RED);
	setTag(11);

	//������������
	initPhysicsBody();

	//����ͼƬ
	auto block = Sprite::create("dirt4.png");
	this->addChild(block, 1);

	scheduleUpdate();

	return true;
}



void Trap::initPhysicsBody(){
	box = PhysicsBody::createBox(size);
	box->setDynamic(false);
	box->setContactTestBitmask(1);
	box->setTag(12);
	setPhysicsBody(box);
}

void Trap::update(float dt){

}
