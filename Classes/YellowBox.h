#ifndef __YELLOWBOX_H__
#define __YELLOWBOX_H__

#include "cocos2d.h"
USING_NS_CC;

class YellowBox :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//���ô�С
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(103);

		//������������
		initPhysicsBody();

		//����ͼƬ
		auto block = Sprite::create("color1.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(YellowBox);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(102);
		setPhysicsBody(box);
	}


};
#endif // __YELLOWBOX_H__