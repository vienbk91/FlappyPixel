/*
 * PipeManager.h
 *
 *  Created on: 3 Jun 2015
 *      Author: chu
 */

#ifndef PIPEMANAGER_H_
#define PIPEMANAGER_H_

#include "cocos2d.h"
#include "Define.h"

USING_NS_CC;

class PipeManager {
public:
	PipeManager(Layer* layer);
	void autoRemoveIfFinished();
	bool _isMoveFinished;

private:

	Sprite *_topPipe , *_bottomPipe;
	Size _visibleSize;
	Vec2 _origin;

	float velocity;
	float endPositionX;
};


#endif /* PIPEMANAGER_H_ */
