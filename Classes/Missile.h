
#ifndef __MISSILE_H__
#define __MISSILE_H__

#include "cocos2d.h"
USING_NS_CC;

class Missile :public Node{


public:
	virtual bool init();
	CREATE_FUNC(Missile);

	void left();
	void right();
};
#endif // __GAME_SCENE_H__