#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class GameOver : public cocos2d::LayerColor
{
private:
	Size visibleSize;
public:
	virtual bool init(){
		LayerColor::initWithColor(Color4B::WHITE);

		visibleSize = Director::getInstance()->getVisibleSize();

		//add title
		auto title = Sprite::create("BackScene1.png");
		title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 ));
		addChild(title, 1);

		//add title
		auto title1 = Sprite::create("title2.png");
		title1->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2  + title1->getContentSize().height / 2));
		addChild(title1, 1);

		auto closeItem = MenuItemImage::create(
			"return4.png",
			"return3.png",
			CC_CALLBACK_1(GameOver::menuCloseCallback, this));

		closeItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - closeItem->getContentSize().height));

		auto menu = Menu::create(closeItem, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 1);
		return true;
	}
	CREATE_FUNC(GameOver);
	static cocos2d::Scene *createScene(){
		auto s = Scene::create();
		auto l = GameOver::create();
		s->addChild(l);
		return s;
	}
	void menuCloseCallback(Ref *pSender){
		Director::getInstance()->popScene();
	}
};
#endif // __GAME_OVER_SCENE_H__