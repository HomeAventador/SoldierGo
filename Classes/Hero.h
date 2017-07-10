#ifndef __HERO_H__
#define __HERO_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio;
using namespace cocos2d::ui;
using namespace cocostudio::timeline;

enum runnerState{
	running,
	jumpingUp,
	jumpingDown,
	attacking,
	standing,
	hearting
};//��������״̬

enum direction{
	left,
	right
};

class Hero : public Node{
private:
	Sprite* runner;
	AnimationCache* cache;
	bool delay_action_open;//1s���Ƿ�ֹͣ�ı�־
	int jumpTime;
	runnerState m_state;
	direction m_direction;

public:
	virtual bool init();
	CREATE_FUNC(Hero);
	void initPhysicsBody();
	void doAction(const char* actionName);
	
	void heart();
	void die();
	void stand();
	void run();
	void jumpUp();
	void jumpDown();
	void attack();
	void initActionSet();
	void update(float dt);
	void delay_action(float delta);//1s��ֹͣ�ļ�ʱ���ķ��� 
	void setRight();
	void setLeft();
	int getDirection();
};

#endif // __GAME_SCENE_H__