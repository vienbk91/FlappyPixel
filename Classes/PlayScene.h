/*
 * PlayScene.h
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */

#ifndef PLAYSCENE_H_
#define PLAYSCENE_H_

#include "cocos2d.h"
#include "PipeManager.h"
#include "Pixel.h"
#include "Pipe.h"


USING_NS_CC;

class PlayScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(PlayScene);

	void createPipe(float dt);
	void update(float dt);

private:

	Pixel *_pixel;
	int _score;
	Label *_scoreLabel;

	Pipe* _topPipe;
	Pipe* _bottomPipe;

	std::vector<PipeManager*> _listPipes;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	bool onContactBegin(PhysicsContact &contact);
};


#endif /* PLAYSCENE_H_ */
