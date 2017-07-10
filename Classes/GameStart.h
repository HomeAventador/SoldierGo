#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Hero.h"
#include "Box.h"
#include "YellowBox.h"
#include "GreenBox.h"
#include "Ice.h"
#include "Trap.h"
#include "Spring.h"
#include "Grass.h"
#include "Cloud.h"
#include "Stone.h"
#include "TreeSmall.h"
#include "TreeRight.h"
#include "StartPoint.h"
#include "EndPoint.h"
#include "Delivers.h"
#include "Delivere.h"
#include "Delivert.h"
#include "Delivern.h"
#include "Lucency.h"
#include "Star.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "GameEndScene.h"
#include "HP.h"
#include "Edge.h"
#include "Level.h"
#include "Missile.h"
#include "Block.h"

USING_NS_CC;

using namespace cocostudio::timeline;

class GameStart : public cocos2d::Layer
{
private:
	Label *score;
	Sprite *head;
	Sprite *_star;
	Hero *hero;
	Box *box;
	YellowBox *yellow;
	GreenBox *green;
	Ice *ice;
	Trap *trap;
	Spring *spring;
	Grass *grass;
	Cloud *cl;
	Stone *st;
	TreeSmall *ts;
	TreeRight *tr;
	StartPoint *sp;
	EndPoint *ep;
	Delivers *ds;
	Delivere *de;
	Delivert *det;
	Delivern *dn;
	Lucency *lu;
	Block *monster;
	Star *st1;
	Star *st2;
	Star *st3;
	Star *st4;
	Star *st5;
	Sprite *cloud1;
	Sprite *cloud2;
	Sprite* HeroHp;
	ProgressTimer *m_preal;
	Point monsterPoint;
	bool delay_action_open;

public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene(int _level);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameStart);

	void initCloud();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	void loadingBox(int map[27][48]);
	void update(float dt);
	void addListener();
	void delay_action(float delta);
};

#endif // __GAMESTART_H__