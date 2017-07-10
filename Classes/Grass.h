#ifndef __GRASS_H__
#define __GRASS_H__

#include "cocos2d.h"
USING_NS_CC;

class Grass :public Node{
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
		auto block = Sprite::create("grassBox.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Grass);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(12);
		setPhysicsBody(box);
	}


};
#endif // __GRASS_H__