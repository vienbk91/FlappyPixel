/*
 * PlayScene.cpp
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */


#include "PlayScene.h"

Scene* PlayScene::createScene(){
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));


	auto layer = PlayScene::create();

	scene->addChild(layer);

	return scene;
}

bool PlayScene::init(){
	if(!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	///////////////////////////////////////////////////////////
	// BACKGROUND
	///////////////////////////////////////////////////////////

	Sprite* playBG = Sprite::create("PlayBackground.png");
	float _scaleX = (float)(visibleSize.width / playBG->getContentSize().width);
	float _scaleY = (float)(visibleSize.height / playBG->getContentSize().height);
	playBG->setScale(_scaleX , _scaleY);
	playBG->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(playBG);

	///////////////////////////////////////////////////////////
	// PIXEL
	///////////////////////////////////////////////////////////

	_pixel = Pixel::createPixel();
	this->addChild(_pixel , 5);

	///////////////////////////////////////////////////////////
	// PIPE
	///////////////////////////////////////////////////////////

	this->schedule(schedule_selector(PlayScene::createPipe , this) , 0.1f);
	_listPipes.push_back(new PipeManager(this));

	///////////////////////////////////////////////////////////
	//Update
	///////////////////////////////////////////////////////////

	this->scheduleUpdate();

	///////////////////////////////////////////////////////////
	// TOUCH MANAGER
	///////////////////////////////////////////////////////////

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlayScene::onTouchEnded, this);

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	///////////////////////////////////////////////////////////
	// TOUCH MANAGER
	///////////////////////////////////////////////////////////
	
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PlayScene::onContactBegin, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


	return true;
}


void PlayScene::createPipe(float dt){
	_listPipes.push_back(new PipeManager(this));
}


bool PlayScene::onTouchBegan(Touch* touch, Event* event){
	return true;
}

void PlayScene::onTouchMoved(Touch* touch, Event* event){

}

void PlayScene::onTouchEnded(Touch* touch, Event* event){

}

bool PlayScene::onContactBegin(PhysicsContact &contact){
	return true;
}