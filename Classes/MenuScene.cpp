/*
 * MenuScene.cpp
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */


#include "MenuScene.h"

USING_NS_CC;

Scene* MenuScene::createScene(){
	auto scene = Scene::create();
	auto layer = MenuScene::create(); // Goi den CREATE_FUNC

	scene->addChild(layer);

	return scene;
}


bool MenuScene::init(){
	if(!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	///////////////////////////////////////////////////////////
	// BACKGROUND
	///////////////////////////////////////////////////////////

	Sprite* menuBG = Sprite::create("MenuBackground.png");
	float _scaleX = (float)(visibleSize.width / menuBG->getContentSize().width);
	float _scaleY = (float)(visibleSize.height / menuBG->getContentSize().height);
	menuBG->setScale(_scaleX , _scaleY);
	menuBG->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(menuBG);

	Sprite* title = Sprite::create("Title.png");
	title->setScale((float)((visibleSize.width * 2/3) / title->getContentSize().width));
	title->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + (visibleSize.height / 4) * 3));
	this->addChild(title);

	//Button
	MenuItemImage* playBtn = MenuItemImage::create("PlayBtn.png", "PlayBtn.png", CC_CALLBACK_1(MenuScene::changeToPlayScene, this));
	playBtn->setScale((float)((visibleSize.width /2) / playBtn->getContentSize().width));
	Menu* menu = Menu::create(playBtn, nullptr);
	menu->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - playBtn->getContentSize().height / 2));

	this->addChild(menu);

	return true;
}

void MenuScene::changeToPlayScene(Ref* pSender){
	log("==========Chang To PlayScene==========");
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}
