#ifndef __GAMEOVERSCENE_H__
#define __GAMEOVERSCENE_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class PauseScene : public Layer
{
public:
	static cocos2d::Scene* createScene(RenderTexture* sqr);
	virtual bool init();
	CREATE_FUNC(PauseScene);
	void continueGame(Ref *pSender);
	void exitGame(Ref *pSender);
};
#endif // __GAMEOVERSCENE_H__