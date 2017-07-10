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

		//设置大小
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(129);

		//设置图片
		auto block = Sprite::create("color1.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Lucency);
	//void initAnimationSet();


};
#endif // __LUCENCY_H__