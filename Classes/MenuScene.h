/*
 * MenuScene.h
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */

#ifndef MENUSCENE_H_
#define MENUSCENE_H_

#include "cocos2d.h"
#include "PlayScene.h"

USING_NS_CC;

class MenuScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(MenuScene);

private:
	
	void changeToPlayScene(Ref* pSender);
};

#endif /* MENUSCENE_H_ */
