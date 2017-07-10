#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Level.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace std;

static int level = 1;

Scene* LevelScene::createScene()
{
	auto scene = Scene::create();

	auto layer = LevelScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool LevelScene::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("BackScene.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	//add nextPage button
	auto closeItemNext = MenuItemImage::create(
		"next1.png",
		"next2.png",
		CC_CALLBACK_1(LevelScene::nextPage, this));

	closeItemNext->setPosition(Vec2(origin.x + visibleSize.width - closeItemNext->getContentSize().width, origin.y + visibleSize.height / 2));

	// create menu, it's an autorelease object
	auto menuNext = Menu::create(closeItemNext, NULL);
	menuNext->setPosition(Vec2::ZERO);
	this->addChild(menuNext, 1);

	//add upPage button
	auto closeItemUp = MenuItemImage::create(
		"up1.png",
		"up2.png",
		CC_CALLBACK_1(LevelScene::upPage, this));

	closeItemUp->setPosition(Vec2(origin.x + closeItemUp->getContentSize().width, origin.y + visibleSize.height / 2));

	// create menu, it's an autorelease object
	auto menuUp = Menu::create(closeItemUp, NULL);
	menuUp->setPosition(Vec2::ZERO);
	this->addChild(menuUp, 1);

	//add leve button
	closeItemLevel = MenuItemImage::create(
		"level01.png",
		"level01.png",
		CC_CALLBACK_1(LevelScene::levelLoad, this));

	closeItemLevel->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// create menu, it's an autorelease object
	menuLevel = Menu::create(closeItemLevel, NULL);
	menuLevel->setPosition(Vec2::ZERO);
	this->addChild(menuLevel, 1);

	//add return button
	auto closeItemReturn = MenuItemImage::create(
		"return1.png",
		"return2.png",
		CC_CALLBACK_1(LevelScene::returnMenu, this));

	closeItemReturn->setPosition(Vec2(origin.x + visibleSize.width - closeItemReturn->getContentSize().width, origin.y + closeItemReturn->getContentSize().height));

	// create menu, it's an autorelease object
	auto menuReturn = Menu::create(closeItemReturn, NULL);
	menuReturn->setPosition(Vec2::ZERO);
	this->addChild(menuReturn, 1);

	return true;
}

void LevelScene::upPage(Ref *pSender){
	if (level > 1){
		menuLevel->removeFromParent();
		level--;
		string pic = "level0" + to_string(level) + ".png";
		closeItemLevel = MenuItemImage::create(
			pic,
			pic,
			CC_CALLBACK_1(LevelScene::levelLoad, this));

		closeItemLevel->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// create menu, it's an autorelease object
		menuLevel = Menu::create(closeItemLevel, NULL);
		menuLevel->setPosition(Vec2::ZERO);
		this->addChild(menuLevel, 1);
	}
}

void LevelScene::nextPage(Ref *pSender){
	if (level < 3){
		menuLevel->removeFromParent();
		level++;
		string pic = "level0" + to_string(level) + ".png";
		closeItemLevel = MenuItemImage::create(
			pic,
			pic,
			CC_CALLBACK_1(LevelScene::levelLoad, this));

		closeItemLevel->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// create menu, it's an autorelease object
		menuLevel = Menu::create(closeItemLevel, NULL);
		menuLevel->setPosition(Vec2::ZERO);
		this->addChild(menuLevel, 1);
	}
}

void LevelScene::levelLoad(Ref *pSender){
	auto start = GameStart::createScene(level);
	Director::getInstance()->purgeCachedData();
	Director::getInstance()->pushScene(start);
	Director::getInstance()->replaceScene(start);
}

void LevelScene::returnMenu(Ref *pSender){
	Director::getInstance()->popScene();
}