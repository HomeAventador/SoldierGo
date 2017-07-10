
#ifndef __BOX_H__
#define __BOX_H__

#include "cocos2d.h"
USING_NS_CC;

class Box :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init();
	//virtual void update(float dt);

	CREATE_FUNC(Box);
	//void initAnimationSet();

	void initPhysicsBody();

};
#endif // __GAME_SCENE_H__