#ifndef __CLOUD_H__
#define __CLOUD_H__

#include "cocos2d.h"
USING_NS_CC;

class Cloud :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//设置大小
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(11);

		//设置物理属性
		initPhysicsBody();

		//设置图片
		auto block = Sprite::create("cloudBox1.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Cloud);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(12);
		setPhysicsBody(box);
	}


};
#endif // __CLOUD_H__