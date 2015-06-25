/*
 * PipeManager.cpp
 *
 *  Created on: 3 Jun 2015
 *      Author: chu
 */


#include "PipeManager.h"

USING_NS_CC;


PipeManager::PipeManager(Layer* layer){
	_origin = Director::getInstance()->getVisibleOrigin();
	_visibleSize = Director::getInstance()->getVisibleSize();

	velocity = 120;

	//////////////////////////////////////////////////////////////
	// Create bottom pipe
	//////////////////////////////////////////////////////////////

	_bottomPipe = Sprite::create("Pipe.png");
	float randomY = RandomHelper::random_int(-(int)(_bottomPipe->getContentSize().height / 4), (int)(_bottomPipe->getContentSize().height /3));
	_bottomPipe->setPosition(Vec2(_origin.x + _visibleSize.width/2 + _bottomPipe->getContentSize().width /2 , randomY));
	layer->addChild(_bottomPipe);

	auto bottomPipeBody = PhysicsBody::createBox(_bottomPipe->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
	bottomPipeBody->setDynamic(false); // Khong chiu tac dong vat ly
	bottomPipeBody->setCategoryBitmask(eObjectBitmask::PIPE);
	bottomPipeBody->setContactTestBitmask(eObjectBitmask::PIXEL);
	bottomPipeBody->setCollisionBitmask(0x00);

	_bottomPipe->setPhysicsBody(bottomPipeBody);

	//////////////////////////////////////////////////////////////
	// Create top pipe
	//////////////////////////////////////////////////////////////

	_topPipe = Sprite::create("Pipe.png");
	_topPipe->setPosition(Vec2(_bottomPipe->getPositionX(), _bottomPipe->getPositionY() + _topPipe->getContentSize().height + 220));
	layer->addChild(_topPipe);

	auto topPipeBody = PhysicsBody::createBox(_topPipe->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
	topPipeBody->setDynamic(false);
	topPipeBody->setCategoryBitmask(eObjectBitmask::PIPE);
	topPipeBody->setCollisionBitmask(0x00);
	topPipeBody->setContactTestBitmask(eObjectBitmask::PIXEL);

	_topPipe->setPhysicsBody(topPipeBody);

	

	//////////////////////////////////////////////////////////////
	// Create score node(hien thi sau khi pixel di qua no)
	//////////////////////////////////////////////////////////////

	auto scoreline = Node::create();
	scoreline->setPosition(Point(_bottomPipe->getContentSize().width, _bottomPipe->getContentSize().height + 110));
	auto linebody = PhysicsBody::createBox(Size(1, 300), PhysicsMaterial(0, 0, 0));
	linebody->setDynamic(false);

	linebody->setCategoryBitmask(eObjectBitmask::LINE);
	linebody->setCollisionBitmask(0);
	linebody->setContactTestBitmask(eObjectBitmask::PIXEL);

	scoreline->setPhysicsBody(linebody);
	_bottomPipe->addChild(scoreline);


	//////////////////////////////////////////////////////////////
	// Move
	//////////////////////////////////////////////////////////////

	endPositionX = _origin.x - _bottomPipe->getContentSize().width / 2;
	_isMoveFinished = false;

	_bottomPipe->runAction(Sequence::createWithTwoActions(MoveTo::create(_visibleSize.width / velocity, Point(endPositionX, _bottomPipe->getPositionY())), CallFunc::create(CC_CALLBACK_0(PipeManager::autoRemoveIfFinished, this))));
	_topPipe->runAction(Sequence::createWithTwoActions(MoveTo::create(_visibleSize.width / velocity, Point(endPositionX, _topPipe->getPositionY())), CallFunc::create(CC_CALLBACK_0(PipeManager::autoRemoveIfFinished, this))));


}


void PipeManager::autoRemoveIfFinished(){
	_bottomPipe->removeFromParentAndCleanup(true);
	_topPipe->removeFromParentAndCleanup(true);

	_isMoveFinished = true;
}

