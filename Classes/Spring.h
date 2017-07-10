#ifndef __SPRING_H__
#define __SPRING_H__

#include "cocos2d.h"
USING_NS_CC;

class Spring :public Node{
private:
	Size size;
	PhysicsBody *box;
	Sprite* spring;
	AnimationCache* cache;
public:
	virtual bool init(){

		//设置大小
		Size visibleSize = Director::getInstance()->getVisibleSize();
		size = Size(80, 80);
		setColor(Color3B::RED);
		setTag(103);

		//设置物理属性
		initPhysicsBody();


		//设置图片
		cache = AnimationCache::getInstance();
		Sprite* spTemp;
		Vector<SpriteFrame*> animFrames(5);
		spTemp = Sprite::create("spring1.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("spring2.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("spring3.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("spring4.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		spTemp = Sprite::create("spring5.png");
		animFrames.pushBack(spTemp->getSpriteFrame());
		auto run_animation = Animation::createWithSpriteFrames(animFrames, 0.25);
		cache->addAnimation(run_animation,"spring_action");
		spring = Sprite::create("spring1.png");
		this->addChild(spring, 1);
		auto animation = AnimationCache::getInstance()->animationByName("spring_action");
		spring->runAction(RepeatForever::create(Animate::create(animation)));
		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(Spring);
	//void initAnimationSet();

	void initPhysicsBody(){

		box = PhysicsBody::createBox(Size(60,20));
		box->setDynamic(false);
		box->setContactTestBitmask(1);
		box->setTag(104);
		box->setPositionOffset(Vec2(0,35));
		setPhysicsBody(box);



	}


};
#endif // __SPRING_H__