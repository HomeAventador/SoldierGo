#ifndef __TRAP_H__
#define __TRAP_H__

#include "cocos2d.h"
#include "Hero.h"
USING_NS_CC;

class Trap :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//���ô�С
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(50, 80);
		setColor(Color3B::RED);
		setTag(105);

		//������������
		initPhysicsBody();

		//����ͼƬ
		auto block = Sprite::create("trap4.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Trap);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(size);
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(106);
		setPhysicsBody(box);
	}




};
#endif // __TRAP_H__