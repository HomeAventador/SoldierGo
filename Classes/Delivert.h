#ifndef __DELIVERT_H__
#define __DELIVERT_H__

#include "cocos2d.h"
USING_NS_CC;

class Delivert :public Node{
private:
	Size size;
	PhysicsBody *box;
	Sprite* del;
	AnimationCache* cache;
public:
	virtual bool init(){

		//设置大小
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(75, 75);
		setColor(Color3B::RED);
		setTag(115);

		//设置物理属性
		initPhysicsBody();


		//设置图片
		cache = AnimationCache::getInstance();
		Sprite* spTemp;
		Vector<SpriteFrame*> animFrames(5);
		spTemp = Sprite::create("deliver1.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("deliver2.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("deliver3.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("deliver4.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("deliver5.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		auto run_animation = Animation::createWithSpriteFrames(animFrames, 0.25);
		cache->addAnimation(run_animation, "action");
		del = Sprite::create("deliver1.png");
		this->addChild(del, 1);
		auto animation = AnimationCache::getInstance()->animationByName("action");
		del->runAction(RepeatForever::create(Animate::create(animation)));
		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Delivert);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(Size(80, 80));
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(116);
		//box->setPositionOffset(Vec2(0, 35));
		setPhysicsBody(box);
	}
};
#endif // __DELIVERT_H__