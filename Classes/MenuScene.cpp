#include "MenuScene.h"

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    
	Sprite *menuBackground = Sprite::create("MenuBackground.png");
	menuBackground->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(menuBackground);

	auto title = Sprite::create("Title.png");
	title->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + (visibleSize.height / 4) * 3));
	this->addChild(title);

	//Button
	auto playBtn = MenuItemImage::create("PlayBtn.png", "PlayBtn.png", CC_CALLBACK_0(MenuScene::gotoPlayScene, this));
	
	auto menu = Menu::create(playBtn, nullptr);
	menu->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - playBtn->getContentSize().height / 2));

	this->addChild(menu);
    
    return true;
}

void MenuScene::gotoPlayScene()
{
	auto playscene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playscene);
}
