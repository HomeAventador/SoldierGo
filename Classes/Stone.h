#ifndef __STONE_H__
#define __STONE_H__

#include "cocos2d.h"
USING_NS_CC;

class Stone :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//设置大小
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(109);

		//设置物理属性
		initPhysicsBody();

		//设置图片
		auto block = Sprite::create("color3.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Stone);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(110);
		setPhysicsBody(box);
	}


};
#endif // __STONE_H__