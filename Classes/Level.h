#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "cocos2d.h"
#include "GameStart.h"

using namespace cocos2d;

class LevelScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	Vec2 origin;
	Menu *menuLevel;
	MenuItemImage *closeItemLevel;
public:
	void upPage(Ref *pSender);
	void nextPage(Ref *pSender);
	void levelLoad(Ref *pSender);
	void returnMenu(Ref *pSender);
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LevelScene);
};

#endif // __LEVEL_H__