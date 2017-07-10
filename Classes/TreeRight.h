#ifndef __TREERIGHT_H__
#define __TREERIGHT_H__

#include "cocos2d.h"
USING_NS_CC;

class TreeRight :public Node{
private:
	Size size;
	PhysicsBody *box;
public:
	virtual bool init(){


		//ÉèÖÃÍ¼Æ¬
		auto block = Sprite::create("grass6.png");
		this->addChild(block, 1);

		return true;
	}
	//virtual void update(float dt);

	CREATE_FUNC(TreeRight);
	//void initAnimationSet();

};
#endif // __TREERIGHT_H__