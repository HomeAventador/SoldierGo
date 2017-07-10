
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"
USING_NS_CC;

enum mon_direction{
	mon_left,
	mon_right
};

class Block :public Node{
private:
	AnimationCache* cache;
	int posX;
	mon_direction dir;
	Sprite* block;
	int key;




public:

	virtual bool init();
	int statenum;
	CREATE_FUNC(Block);
	virtual void update(float dt);
	void initAnimationSet();

	
};
#endif // __GAME_SCENE_H__