/*
 * OverLayer.h
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */

#ifndef OVERLAYER_H_
#define OVERLAYER_H_

#include "cocos2d.h"
#include "MenuScene.h"
#include "PlayScene.h"

USING_NS_CC;

class OverLayer : public Layer {
public:
	virtual bool init();

	// Ham create layer duoc dinh nghia san
	CREATE_FUNC(OverLayer);

private:
	void changeToMenuScene(Ref* pSender);
	void changeToPlayScene(Ref* pSender);
	void setScore(int score);

	int _score;
	int _hightScore;
	Label* _scoreLabel;
	Label* _highScoreLabel;

};


#endif /* OVERLAYER_H_ */
