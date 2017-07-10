#include "Edge.h"

USING_NS_CC;
bool Edge::init(){
	
	Node::init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size size = Size(3840, 2160);
	setPhysicsBody(PhysicsBody::createEdgeBox(size));
	setContentSize(size);
	setPosition(visibleSize / 2);

	return true;
}