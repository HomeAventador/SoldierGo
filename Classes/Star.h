#ifndef __STAR_H__
#define __STAR_H__

#include "cocos2d.h"
USING_NS_CC;

class Star :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//设置大小
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(50, 50);
		setColor(Color3B::RED);
		setTag(119);

		//设置物理属性
		initPhysicsBody();

		//设置图片
		auto block = Sprite::create("star1.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Star);
	//void initAnimationSet();
	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		setPhysicsBody(box);
	}


};
#endif // __STAR_H__