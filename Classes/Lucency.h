#ifndef __LUCENCY_H__
#define __LUCENCY_H__

#include "cocos2d.h"
USING_NS_CC;

class Lucency :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){

		//���ô�С
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(129);

		//����ͼƬ
		auto block = Sprite::create("color1.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Lucency);
	//void initAnimationSet();


};
#endif // __LUCENCY_H__