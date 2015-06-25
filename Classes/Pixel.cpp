/*
 * Pixel.cpp
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */

#include "Pixel.h"

USING_NS_CC;

Pixel* Pixel::createPixel(){
	auto pixel = new Pixel();
	if(pixel && pixel->init()){
		pixel->autorelease();

		return pixel;
	}
	CC_SAFE_DELETE(pixel);
	return nullptr;
}

bool Pixel::init(){
	if(!Sprite::init()){
		return false;
	}

	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();


	//////////////////////////////////////////////////////////////
	// Create Texture
	//////////////////////////////////////////////////////////////

	this->setTexture("Pixel.png");
	this->setPosition(Vec2(_origin.x + _visibleSize.width/2 , _origin.y + _visibleSize.height/2 ));

	/*
	_pixelBody = PhysicsBody::createBox(this->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
	_pixelBody->setCategoryBitmask(eObjectBitmask::PIXEL);
	_pixelBody->setContactTestBitmask(eObjectBitmask::PIPE | eObjectBitmask::LINE);
	this->setPhysicsBody(_pixelBody);

	isFalling = true;
	velocity = Vec2(0, 0);
	rotation = 0.0f;


	isDead = false;
	*/

	return true;
}

/*
void Pixel::update(){
	if (isFalling){
		if (this->getPositionY() > _visibleSize.height / 2){
			velocity.y += -1;
			rotation += 3;
		} 
		else {
			velocity.y = 0;
			rotation = 0;

			this->setPositionY(_visibleSize.height / 2);
		}
	} 
	else {

		if (this->getPositionY() < _visibleSize.height / 2){
			velocity.y += 10;
			rotation += -10;
		}
		else {
			velocity.y = 0;
			rotation = 0;
		}
	}

	this->setPosition(Vec2(this->getPositionX(), this->getPositionY() + velocity.y));
	this->setRotation(rotation);

}



void Pixel::flap(){
	isFalling = false;
}

void Pixel::fall(){
	isFalling = true;
}

*/
