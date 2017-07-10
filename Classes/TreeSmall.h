#ifndef __TREESMALL_H__
#define __TREESMALL_H__

#include "cocos2d.h"
USING_NS_CC;

class TreeSmall :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){


		//ÉèÖÃÍ¼Æ¬
		auto block = Sprite::create("tree6.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(TreeSmall);
	//void initAnimationSet();

};
#endif // __TREESMALL_H__