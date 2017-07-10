#ifndef _HP_H_
#define _HP_H_
#include "cocos2d.h"
USING_NS_CC;

class Hp : public Node
{
public:
	Hp();
	~Hp();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(Hp);
private:
	ProgressTimer* m_preal;
};

#endif