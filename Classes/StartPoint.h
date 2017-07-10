#ifndef __STARTPOINT_H__
#define __STARTPOINT_H__

#include "cocos2d.h"
USING_NS_CC;

class StartPoint :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//���ô�С
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(11);

		//������������
		initPhysicsBody();

		//����ͼƬ
		auto block = Sprite::create("tree2.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(StartPoint);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(12);
		setPhysicsBody(box);
	}


};
#endif // __STARTPOINT_H__