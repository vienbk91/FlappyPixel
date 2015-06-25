/*
 * Pipe.cpp
 *
 *  Created on: 3 Jun 2015
 *      Author: chu
 */


#include "Pipe.h"


USING_NS_CC;


Pipe* Pipe::createPipe(){
	auto pipe = new Pipe();
	if(pipe && pipe->init()){
		pipe->autorelease();
		return pipe;
	}
	CC_SAFE_DELETE(pipe);
	return nullptr;
}

bool Pipe::init(){
	if(!Sprite::init()){
		return false;
	}

	this->setTexture("Pipe.png");

	return true;
}

