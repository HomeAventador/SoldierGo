#ifndef __GREENBOX_H__
#define __GREENBOX_H__

#include "cocos2d.h"
USING_NS_CC;

class GreenBox :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//���ô�С
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(101);

		//������������
		initPhysicsBody();

		//����ͼƬ
		auto block = Sprite::create("color2.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(GreenBox);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(102);
		setPhysicsBody(box);
	}


};
#endif // __GREEN_H__