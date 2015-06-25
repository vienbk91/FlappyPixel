/*
 * IntroScene.cpp
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */

#include "IntroScene.h"

USING_NS_CC;

Scene* IntroScene::createScene(){
	auto scene = Scene::create();
	auto layer = IntroScene::create();

	scene->addChild(layer);

	return scene;
}

bool IntroScene::init(){
	if(!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	///////////////////////////////////////////////////////////
	// BACKGROUND
	///////////////////////////////////////////////////////////

	Sprite* introBG = Sprite::create("IntroBackground.png");
	float _scaleX = (float) (visibleSize.width / introBG->getContentSize().width);
	float _scaleY = (float) (visibleSize.height / introBG->getContentSize().height);

	introBG->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));
	this->addChild(introBG);


	// Scehdule chi thuc hien 1 lan sau thoi gian dt = 2s
	this->scheduleOnce(schedule_selector(IntroScene::changeToMenuScene ) , 2.0f);


	return true;
}

void IntroScene::changeToMenuScene(float dt){
	log("=======Change to MenuScene==========");
	auto menuScene = MenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionMoveInR::create(0.25f , menuScene));

}
