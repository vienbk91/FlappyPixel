/*
 * Pixel.h
 *
 *  Created on: 2 Jun 2015
 *      Author: chu
 */


//////////////////////////////////////////////////////////////////////
// Lop xay dung doi tuong pixel
//////////////////////////////////////////////////////////////////////

#ifndef PIXEL_H_
#define PIXEL_H_

#include "cocos2d.h"
#include "Define.h"

USING_NS_CC;


class Pixel : public Sprite {
public:
	static Pixel* createPixel();
	virtual bool init();



private:

	PhysicsBody* _pixelBody;

	Size _visibleSize;
	Vec2 _origin;

	/*
	bool isFalling;
	bool isDead;
	Vec2 velocity;
	float rotation;


	void update();
	void flap();
	void fall();
	*/
};


#endif /* PIXEL_H_ */
