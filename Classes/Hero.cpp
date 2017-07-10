#include "Hero.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace CocosDenshion;



bool Hero::init(){
	//初始化精灵
	runner = Sprite::create("hero_Idle__000.png");
	addChild(runner);

	//初始化物理属
	initPhysicsBody();
	setTag(1);
	
	cache = AnimationCache::getInstance();
	initActionSet();
	run();

	m_direction = right;
	delay_action_open = false;
	return true;
}

void Hero::initPhysicsBody(){
	auto *box = PhysicsBody::createBox(Size(40 ,60), PhysicsMaterial(1, 0, 0));
	box->setRotationEnable(false);
	box->setVelocityLimit(2000);
	box->setPositionOffset(Vec2(0, -15));
	box->setTag(2);
	setPhysicsBody(box);
	getPhysicsBody()->setContactTestBitmask(1);
}


void Hero::initActionSet(){

	//runRight
	Sprite* spTemp;
	Vector<SpriteFrame*> animFrames(8);
	spTemp = Sprite::create("hero_Run_000.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_001.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_002.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_003.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_004.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_005.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_006.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	spTemp = Sprite::create("hero_Run_007.png");
	animFrames.pushBack(spTemp->getSpriteFrame());
	auto run_animation = Animation::createWithSpriteFrames(animFrames, 0.125);
	cache->addAnimation(run_animation, "runningRight");


	//runLeft
	Sprite* spTemp5;
	Vector<SpriteFrame*> animFrames5(8);
	spTemp5 = Sprite::create("hero_Run_008.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_009.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_010.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_011.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_012.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_013.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_014.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	spTemp5 = Sprite::create("hero_Run_015.png");
	animFrames5.pushBack(spTemp5->getSpriteFrame());
	auto run_animation1 = Animation::createWithSpriteFrames(animFrames5, 0.125);
	cache->addAnimation(run_animation1, "runningLeft");


	Sprite* spTemp1;
	Vector<SpriteFrame*> animFrames1(4);
	spTemp1 = Sprite::create("hero_Jump_000.png");
	animFrames1.pushBack(spTemp1->getSpriteFrame());
	spTemp1 = Sprite::create("hero_Jump_001.png");
	animFrames1.pushBack(spTemp1->getSpriteFrame());
	spTemp1 = Sprite::create("hero_Jump_002.png");
	animFrames1.pushBack(spTemp1->getSpriteFrame());
	spTemp1 = Sprite::create("hero_Jump_003.png");
	animFrames1.pushBack(spTemp1->getSpriteFrame());
	auto jumpup_animation = Animation::createWithSpriteFrames(animFrames1, 0.125);
	cache->addAnimation(jumpup_animation, "jumpUpRight");

	//JumpUpRight
	Sprite* spTemp7;
	Vector<SpriteFrame*> animFrames7(4);
	spTemp7 = Sprite::create("hero_Jump_004.png");
	animFrames7.pushBack(spTemp7->getSpriteFrame());
	spTemp7 = Sprite::create("hero_Jump_005.png");
	animFrames7.pushBack(spTemp7->getSpriteFrame());
	spTemp7 = Sprite::create("hero_Jump_006.png");
	animFrames7.pushBack(spTemp7->getSpriteFrame());
	spTemp7 = Sprite::create("hero_Jump_007.png");
	animFrames7.pushBack(spTemp7->getSpriteFrame());
	auto jumpup_animation1 = Animation::createWithSpriteFrames(animFrames7, 0.125);
	cache->addAnimation(jumpup_animation1, "jumpUpLeft");

	//jumpdown
	Sprite* spTemp2;
	Vector<SpriteFrame*> animFrames2(3);
	spTemp2 = Sprite::create("hero_Down_000.png");
	animFrames2.pushBack(spTemp2->getSpriteFrame());
	auto jumpdown_animation = Animation::createWithSpriteFrames(animFrames2, 0.125);
	cache->addAnimation(jumpdown_animation, "jumpDownRight");

	Sprite* spTemp8;
	Vector<SpriteFrame*> animFrames8(3);
	spTemp8 = Sprite::create("hero_Down_001.png");
	animFrames8.pushBack(spTemp8->getSpriteFrame());
	auto jumpdown_animation1 = Animation::createWithSpriteFrames(animFrames8, 0.125);
	cache->addAnimation(jumpdown_animation1, "jumpDownLeft");


	//attackRight
	Sprite* spTemp3;
	Vector<SpriteFrame*> animFrames3(5);
	spTemp3 = Sprite::create("hero_Attack_000.png");
	animFrames3.pushBack(spTemp3->getSpriteFrame());
	spTemp3 = Sprite::create("hero_Attack_001.png");
	animFrames3.pushBack(spTemp3->getSpriteFrame());
	spTemp3 = Sprite::create("hero_Attack_002.png");
	animFrames3.pushBack(spTemp3->getSpriteFrame());
	spTemp3 = Sprite::create("hero_Attack_003.png");
	animFrames3.pushBack(spTemp3->getSpriteFrame());
	spTemp3 = Sprite::create("hero_Attack_004.png");
	animFrames3.pushBack(spTemp3->getSpriteFrame());
	auto attcack_animation = Animation::createWithSpriteFrames(animFrames3, 0.125);
	cache->addAnimation(attcack_animation, "attackRight");

	//attackLeft
	Sprite* spTemp6;
	Vector<SpriteFrame*> animFrames6(5);
	spTemp6 = Sprite::create("hero_Attack_005.png");
	animFrames6.pushBack(spTemp6->getSpriteFrame());
	spTemp6 = Sprite::create("hero_Attack_006.png");
	animFrames6.pushBack(spTemp6->getSpriteFrame());
	spTemp6 = Sprite::create("hero_Attack_007.png");
	animFrames6.pushBack(spTemp6->getSpriteFrame());
	spTemp6 = Sprite::create("hero_Attack_008.png");
	animFrames6.pushBack(spTemp6->getSpriteFrame());
	spTemp6 = Sprite::create("hero_Attack_009.png");
	animFrames6.pushBack(spTemp6->getSpriteFrame());
	auto attcack_animation1 = Animation::createWithSpriteFrames(animFrames6, 0.125);
	cache->addAnimation(attcack_animation1, "attackLeft");

	//stand
	Sprite* spTemp10;
	Vector<SpriteFrame*> animFrames10(10);
	spTemp10 = Sprite::create("hero_Idle__000.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__001.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__002.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__003.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__004.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__005.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__006.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__007.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__008.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	spTemp10 = Sprite::create("hero_Idle__009.png");
	animFrames10.pushBack(spTemp10->getSpriteFrame());
	auto stand_animation = Animation::createWithSpriteFrames(animFrames10, 0.125);
	cache->addAnimation(stand_animation, "standRight");

	Sprite* spTemp11;
	Vector<SpriteFrame*> animFrames11(10);
	spTemp11 = Sprite::create("hero_Idle__010.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__011.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__012.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__013.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__014.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__015.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__016.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__017.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__018.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	spTemp11 = Sprite::create("hero_Idle__019.png");
	animFrames11.pushBack(spTemp11->getSpriteFrame());
	auto stand_animation1 = Animation::createWithSpriteFrames(animFrames11, 0.125);
	cache->addAnimation(stand_animation1, "standLeft");

	Sprite* spTemp12;
	Vector<SpriteFrame*> animFrames12(2);
	spTemp12 = Sprite::create("Drop_blood1.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	spTemp12 = Sprite::create("Drop_blood1.png");
	animFrames12.pushBack(spTemp12->getSpriteFrame());
	auto heart_animation= Animation::createWithSpriteFrames(animFrames12, 0.125);
	cache->addAnimation(heart_animation, "heartLeft");

	Sprite* spTemp13;
	Vector<SpriteFrame*> animFrames13(2);
	spTemp13 = Sprite::create("Drop_blood.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	spTemp13 = Sprite::create("Drop_blood.png");
	animFrames13.pushBack(spTemp13->getSpriteFrame());
	auto heart_animation1 = Animation::createWithSpriteFrames(animFrames13, 0.125);
	cache->addAnimation(heart_animation1, "heartRight");

	Sprite* spTemp14;
	Vector<SpriteFrame*> animFrames14(12);
	spTemp14 = Sprite::create("Die_000.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_001.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_002.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_003.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_004.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_005.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_006.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_007.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_008.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_009.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_010.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	spTemp14 = Sprite::create("Die_011.png");
	animFrames14.pushBack(spTemp14->getSpriteFrame());
	auto die_animation1 = Animation::createWithSpriteFrames(animFrames14, 0.125);
	cache->addAnimation(die_animation1, "die");

}


void Hero::doAction(const char* actionName){
	auto animation = AnimationCache::getInstance()->animationByName(actionName);
	auto action = Animate::create(animation);
	runner->runAction(action);
}

void Hero::run(){

	jumpTime = 0;
	m_state = running;
	if (m_direction == right){
		runner->stopAllActions();
		auto animation = AnimationCache::getInstance()->animationByName("runningRight");
		runner->runAction(RepeatForever::create(Animate::create(animation)));
		

	}
	else if (m_direction == left){
		runner->stopAllActions();
		auto animation = AnimationCache::getInstance()->animationByName("runningLeft");
		runner->runAction(RepeatForever::create(Animate::create(animation)));

	}

	
}

void Hero::jumpUp(){
	auto vel = getPhysicsBody()->getVelocity();

	if (m_state == standing){

		jumpTime++;
		getPhysicsBody()->setVelocity(Vec2(vel.x, 700));
		m_state = jumpingUp;
		runner->stopAllActions();

		if (m_direction == right){
			auto animation = cache->animationByName("jumpUpRight");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}
		else if (m_direction == left){
			auto animation = cache->animationByName("jumpUpLeft");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}
	}
	else if (m_state == running){

		jumpTime++;
		getPhysicsBody()->setVelocity(Vec2(vel.x, 700));
		m_state = jumpingUp;
		runner->stopAllActions();

		if (m_direction == right){
			auto animation = cache->animationByName("jumpUpRight");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}
		else if (m_direction == left){
			auto animation = cache->animationByName("jumpUpLeft");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}
	}else if (m_state == jumpingUp && jumpTime < 2){

		jumpTime++;
		getPhysicsBody()->setVelocity(Vec2(vel.x, 700));
		m_state = jumpingUp;
		runner->stopAllActions();

		if (m_direction == right){
			auto animation = cache->animationByName("jumpUpRight");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}
		else if (m_direction == left){
			auto animation = cache->animationByName("jumpUpLeft");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}

	}
	else if (m_state == jumpingDown && jumpTime < 2){

		jumpTime++;
		getPhysicsBody()->setVelocity(Vec2(vel.x, 700));
		m_state = jumpingUp;
		runner->stopAllActions();

		if (m_direction == right){
			auto animation = cache->animationByName("jumpUpRight");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}
		else if (m_direction == left){
			auto animation = cache->animationByName("jumpUpLeft");
			auto action = Animate::create(animation);
			runner->runAction(action);
		}

	}

}

void Hero::jumpDown(){

	m_state = jumpingDown;

	if (m_direction == right){
		auto animation = cache->animationByName("jumpDownRight");
		auto action = Animate::create(animation);
		runner->runAction(action);
	}
	else if (m_direction == left){
		auto animation = cache->animationByName("jumpDownLeft");
		auto action = Animate::create(animation);
		runner->runAction(action);
	}

}

void Hero::stand(){
	jumpTime = 0;
	m_state = standing;
	runner->stopAllActions();
	if (m_direction == right){
		auto animation = cache->animationByName("standRight");

		runner->runAction(RepeatForever::create(Animate::create(animation)));
	}
	else if (m_direction == left){
		auto animation = cache->animationByName("standLeft");
		runner->runAction(RepeatForever::create(Animate::create(animation)));
	}

}

void Hero::attack(){

	m_state = attacking;
	runner->stopAllActions();

	if (m_direction == right){
		auto animation = cache->animationByName("attackRight");
		auto action = Animate::create(animation);
		runner->runAction(action);
	}
	else if (m_direction == left){
		auto animation = cache->animationByName("attackLeft");
		auto action = Animate::create(animation);
		runner->runAction(action);
	}

	delay_action_open = true;

}

void Hero::heart(){

	m_state = hearting;
	runner->stopAllActions();

	if (m_direction == right){
		auto animation = cache->animationByName("heartRight");
		auto action = Animate::create(animation);
		runner->runAction(action);
	}
	else if (m_direction == left){
		auto animation = cache->animationByName("heartLeft");
		auto action = Animate::create(animation);
		runner->runAction(action);
	}

	delay_action_open = true;

}

void Hero::die(){

	auto animation = cache->animationByName("die");
	auto action = Animate::create(animation);
	runner->runAction(action);

}

void Hero::update(float dt){

	auto vel = getPhysicsBody()->getVelocity();

	if (m_state == jumpingUp){
		if (vel.y < 0.1){

			runner->stopAllActions();;
			jumpDown();
		}
	}

	if (m_state == jumpingDown){

		if (vel.y >= 0){
			runner->stopAllActions();
			stand();
		}
	}


	if (delay_action_open){
		//则开启一个一次的定时器  
		this->scheduleOnce(schedule_selector(Hero::delay_action), 0.5f);
		delay_action_open = false;
	}


}
void Hero::delay_action(float delta){
	stand();
}

void Hero::setRight(){
	m_direction = right;
}

void Hero::setLeft(){
	m_direction = left;
}

int Hero::getDirection(){
	if (m_direction == left){
		return 1;
	}
	else{
		return 2;
	}
}