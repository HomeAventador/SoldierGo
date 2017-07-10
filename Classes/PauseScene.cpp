#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PauseScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocostudio;

bool PauseScene::init(){

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//add continue button
	auto conButton = MenuItemImage::create(
		"continue1.png",
		"continue2.png",
		CC_CALLBACK_1(PauseScene::continueGame, this));

	conButton->setPosition(Vec2(visibleSize.width / 2 + conButton->getContentSize().width, visibleSize.height / 2));

	// create menu, it's an autorelease object
	auto menuCon = Menu::create(conButton, NULL);
	menuCon->setPosition(Vec2::ZERO);
	this->addChild(menuCon, 1);

	//add exit button
	auto exitButton = MenuItemImage::create(
		"exit3.png",
		"exit4.png",
		CC_CALLBACK_1(PauseScene::exitGame, this));

	exitButton->setPosition(Vec2(visibleSize.width / 2 - exitButton->getContentSize().width, visibleSize.height / 2));

	// create menu, it's an autorelease object
	auto menuExit = Menu::create(exitButton, NULL);
	menuExit->setPosition(Vec2::ZERO);
	this->addChild(menuExit, 1);
	return true;
}

Scene* PauseScene::createScene(RenderTexture* sqr){
	Scene *scene = Scene::create();
	PauseScene *layer = PauseScene::create();
	scene->addChild(layer, 1);
	//增加部分：使用Game界面中截图的sqr纹理图片创建Sprite  
	//并将Sprite添加到GamePause场景层中  
	//得到窗口的大小  
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2)); //放置位置,这个相对于中心位置。  
	back_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同  
	back_spr->setColor(Color3B(192,192,192)); //图片颜色变灰色  
	scene->addChild(back_spr);
	return scene;
}

void PauseScene::continueGame(Ref *pSender){
	Director::getInstance()->popScene();
}

void PauseScene::exitGame(Ref *pSender){
	Director::getInstance()->popScene();
	Director::getInstance()->popScene();
}