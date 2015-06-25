/*
 * OverLayer.cpp
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */


#include "OverLayer.h"


bool OverLayer::init(){
	if (!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	///////////////////////////////////////////////////////////
	// BACKGROUND
	///////////////////////////////////////////////////////////
	Sprite* overPanel = Sprite::create("Gameover.png");
	overPanel->setScale((float)((visibleSize.width * 3 / 4) / overPanel->getContentSize().width));
	overPanel->setPosition(Vec2(origin.x + visibleSize.width/2 , origin.y + visibleSize.height /2 ));
	this->addChild(overPanel);


	/////////////////////////////////////////////////////////////////////////////////////
	// Score
	/////////////////////////////////////////////////////////////////////////////////////
	int _scoreFontSize, _hightScoreFontSize;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	_scoreFontSize = 250;
	_hightScoreFontSize = 70;
#endif 

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	_scoreFontSize = 100;
	_hightScoreFontSize = 30;
#endif

	_scoreLabel = Label::createWithTTF("0", "fonts/Square.ttf", _scoreFontSize);
	_scoreLabel->setPosition(origin.x + overPanel->getPositionX(), overPanel->getPositionY() + overPanel->getContentSize().height * _scaleY / 4);

	this->addChild(_scoreLabel);

	_highScoreLabel = Label::createWithTTF("0", "fonts/Square.ttf", _hightScoreFontSize);
	_highScoreLabel->setPosition(origin.x + overPanel->getPositionX(), _scoreLabel->getPositionY() - _highScoreLabel->getContentSize().height - overPanel->getContentSize().height * _scaleY / 6);

	this->addChild(_highScoreLabel);

	/////////////////////////////////////////////////////////////////////////////////////
	// Button
	/////////////////////////////////////////////////////////////////////////////////////

	auto menuBtn = MenuItemImage::create("MenuBtn.png", "MenuBtn_Selected.png", CC_CALLBACK_1(OverLayer::changeToMenuScene, this));
	float _scaleBtn = (float)((overPanel->getContentSize().width * _scaleX / 2 * 2 / 3) / menuBtn->getContentSize().width);
	menuBtn->setScale(_scaleBtn);
	auto replayBtn = MenuItemImage::create("ReplayBtn.png", "ReplayBtn.png", CC_CALLBACK_1(OverLayer::changeToPlayScene, this));
	replayBtn->setScale(_scaleBtn);

	auto menu = Menu::create(menuBtn, replayBtn, nullptr);
	menu->alignItemsHorizontallyWithPadding(overPanel->getContentSize().width * _scaleX * 1 / 6);
	menu->setPosition(origin.x + visibleSize.width / 2, overPanel->getPositionY() - overPanel->getContentSize().height * _scaleY / 4 + menuBtn->getContentSize().height / 2);

	this->addChild(menu);

	return true;
}


void OverLayer::changeToMenuScene(Ref* pSender){
	auto menuScene = MenuScene::createScene();
	Director::getInstance()->replaceScene(menuScene);
}

void OverLayer::changeToPlayScene(Ref* pSender){
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}

void OverLayer::setScore(int score){
	_score = score;
	_scoreLabel->setString(String::createWithFormat("%d", _score)->getCString());

	auto userdefault = UserDefault::getInstance(); // Su dung UserDefault de luu tru db tam thoi voi dung luong thap
	auto highscore = userdefault->getIntegerForKey("HIGHSCORE", 0); // lay gia tri luu bang key

	if (_score > highscore)
	{
		highscore = _score;
		userdefault->setIntegerForKey("HIGHSCORE", highscore); // set gia tri luu bang key
	}

	userdefault->flush();
	_highScoreLabel->setString(String::createWithFormat("HIGH SCORE: %d", highscore)->getCString());

}