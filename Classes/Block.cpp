#include "Block.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

bool Block::init(){


	setTag(127);
	Size s = Size(90, 140);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto box = PhysicsBody::createBox(s);
	box->setTag(128);
	box->setPositionOffset(Vec2(0, -30));
	setPhysicsBody(box);
	setColor(Color3B(0, 0, 0));
	setAnchorPoint(Point(0.5, 0.5));
	setContentSize(s);
	setPositionX(visibleSize.width);

	getPhysicsBody()->setDynamic(false);
	getPhysicsBody()->setContactTestBitmask(1);
	block = Sprite::create("monWalk_000.png");

	cache = AnimationCache::getInstance();
	initAnimationSet();

	block->setScale(0.75);
	this->addChild(block, 1);
	posX = getPositionX();
	dir = mon_left;
	key = 0;
	statenum = 1;
	auto animation = AnimationCache::getInstance()->animationByName("walkLeft");
	block->runAction(RepeatForever::create(Animate::create(animation)));
	scheduleUpdate();

	return true;
}
void Block::update(float dt){

	if (statenum == 1){
		//判断方向
		if (getPositionX() < posX - 100){
			dir = mon_right;
		}
		if (getPositionX() > posX + 100){
			dir = mon_left;
		}

		//进行移动
		if (dir == mon_left){
			this->setPositionX(getPositionX() - 3);
			if (key == 1){
				block->stopAllActions();
				auto animation = AnimationCache::getInstance()->animationByName("walkLeft");
				block->runAction(RepeatForever::create(Animate::create(animation)));
				key = 0;
			}

		}
		else if (dir == mon_right)
		{
			this->setPositionX(getPositionX() + 3);
			if (key == 0){
				block->stopAllActions();
				auto animation = AnimationCache::getInstance()->animationByName("walkRight");
				block->runAction(RepeatForever::create(Animate::create(animation)));
				key = 1;
			}
		}
	}
	else if (statenum == 2){

		block->stopAllActions();
		auto animation = AnimationCache::getInstance()->animationByName("attack");
		block->runAction(RepeatForever::create(Animate::create(animation)));
		log("2");

	}
	else if (statenum == 3){

		this->setPositionX(getPositionX() + 3);
		block->stopAllActions();
		auto animation = AnimationCache::getInstance()->animationByName("walkRight");
		block->runAction(RepeatForever::create(Animate::create(animation)));
		log("3");
	}
	

}

void Block::initAnimationSet(){


	Sprite* spTemp13;
	Vector<SpriteFrame*> animFrames13(12);
	spTemp13 = Sprite::create("monWalk_000.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_001.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_002.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_003.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_004.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_005.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_006.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_007.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_008.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_009.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_010.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("monWalk_011.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	auto walk_left_animation = Animation::createWithSpriteFrames(animFrames13, 0.125);
	cache->addAnimation(walk_left_animation, "walkLeft");

	Sprite* spTemp12;
	Vector<SpriteFrame*> animFrames12(12);
	spTemp12 = Sprite::create("monWalk_012.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_013.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_014.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_015.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_016.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_017.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_018.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_019.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_020.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_021.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_022.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("monWalk_023.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	auto walk_right_animation = Animation::createWithSpriteFrames(animFrames12, 0.125);
	cache->addAnimation(walk_right_animation, "walkRight");


	Sprite* spTemp11;
	Vector<SpriteFrame*> animFrames11(8);
	spTemp11 = Sprite::create("Attack-1_000.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_001.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_002.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_003.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_004.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_005.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_006.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("Attack-1_007.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	auto attack_animation = Animation::createWithSpriteFrames(animFrames11, 0.125);
	cache->addAnimation(attack_animation, "attack");

}



