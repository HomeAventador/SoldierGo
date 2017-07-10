#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Menu.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocostudio;

ComAudio *back;

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();
	
	auto layer = MenuScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto sound = CSLoader::createNode("Sound.csb");
	addChild(sound);
	back = (ComAudio*)sound->getChildByName("Audio_1")->getComponent("Audio_1");
	//back->playBackgroundMusic();

	auto rootNode = CSLoader::createNode("MainScene.csb");

	addChild(rootNode);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//add title
	auto title = Sprite::create("title.png");
	title->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+title->getContentSize().height/2));
	addChild(title, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("BackScene1.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	//add start button
	auto closeItemStart = MenuItemImage::create(
		"start1.png",
		"start2.png",
		CC_CALLBACK_1(MenuScene::start, this));

	closeItemStart->setPosition(Vec2(origin.x + visibleSize.width / 3, origin.y + visibleSize.height / 5 + 50));

	// create menu, it's an autorelease object
	auto menuStart = Menu::create(closeItemStart, NULL);
	menuStart->setPosition(Vec2::ZERO);
	this->addChild(menuStart, 1);

	//add level button
	auto closeItemLevel = MenuItemImage::create(
		"menu1.png",
		"menu2.png",
		CC_CALLBACK_1(MenuScene::level, this));

	closeItemLevel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 5 + 50));

	// create menu, it's an autorelease object
	auto menuLevel = Menu::create(closeItemLevel, NULL);
	menuLevel->setPosition(Vec2::ZERO);
	this->addChild(menuLevel, 1);

	//add sound button
	auto closeItemSound = MenuItemImage::create(
		"sound1.png",
		"sound2.png",
		CC_CALLBACK_1(MenuScene::sound, this));

	closeItemSound->setPosition(Vec2(origin.x + visibleSize.width*2/3, origin.y + visibleSize.height / 5 + 50));

	// create menu, it's an autorelease object
	auto menuSound = Menu::create(closeItemSound, NULL);
	menuSound->setPosition(Vec2::ZERO);
	this->addChild(menuSound, 1);

	//add exit button
	auto closeButton = MenuItemImage::create(
		"exit1.png",
		"exit2.png",
		CC_CALLBACK_1(MenuScene::endGame, this));

	closeButton->setPosition(Vec2(origin.x + visibleSize.width - closeButton->getContentSize().width / 2 - 50,
		origin.y + closeButton->getContentSize().height / 2 + 50));

	// create menu, it's an autorelease object
	auto menuClose = Menu::create(closeButton, NULL);
	menuClose->setPosition(Vec2::ZERO);
	this->addChild(menuClose, 1);

	return true;
}

void MenuScene::start(Ref *pSender){
	auto start = GameStart::createScene(1);
	Director::getInstance()->purgeCachedData();
	Director::getInstance()->pushScene(start);
	Director::getInstance()->replaceScene(start);
}

void MenuScene::level(Ref *pSender){
	auto s = LevelScene::createScene();
	Director::getInstance()->purgeCachedData();
	Director::getInstance()->pushScene(s);
	Director::getInstance()->replaceScene(TransitionSlideInR::create(1.5f, s));
}

void MenuScene::sound(Ref *pSender){
	if (back->isBackgroundMusicPlaying())
		back->stopBackgroundMusic();
	else
		back->playBackgroundMusic();
}

void MenuScene::endGame(Ref *pSender){
	Director::getInstance()->end();
}