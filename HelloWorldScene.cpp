#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
	typedef Sprite*		SpritePtr;
	//SpritePtr	*sp = new SpritePtr[10];	
	SpritePtr sp[5][5][2];
	for (int i = 0; i < 5; ++i)
	{
		sp[i][0][0] = Sprite::create("white.png");
		sp[i][0][1] = Sprite::create("white1.png");
		sp[i][1][0] = Sprite::create("blue.png");
		sp[i][1][1] = Sprite::create("blue1.png");
		sp[i][2][0] = Sprite::create("yellow.png");
		sp[i][2][1] = Sprite::create("yellow1.png");
		sp[i][3][0] = Sprite::create("green.png");
		sp[i][3][1] = Sprite::create("green1.png");
		sp[i][4][0] = Sprite::create("red.png");
		sp[i][4][1] = Sprite::create("red1.png");
	}
	typedef MenuItemSprite*		MenuItemSpritePtr;
	MenuItemSpritePtr te[5][5];
	for (int i = 0; i < 5; ++i)
	{
		te[i][0] = MenuItemSprite::create(
			sp[i][0][0],
			sp[i][0][1],
			CC_CALLBACK_1(HelloWorld::menuReturnCallback, this));
		te[i][1] = MenuItemSprite::create(
			sp[i][1][0],
			sp[i][1][1],
			CC_CALLBACK_1(HelloWorld::menuReturnCallback, this));
		te[i][2] = MenuItemSprite::create(
			sp[i][2][0],
			sp[i][2][1],
			CC_CALLBACK_1(HelloWorld::menuReturnCallback, this));
		te[i][3] = MenuItemSprite::create(
			sp[i][3][0],
			sp[i][3][1],
			CC_CALLBACK_1(HelloWorld::menuReturnCallback, this));
		te[i][4] = MenuItemSprite::create(
			sp[i][4][0],
			sp[i][4][1],
			CC_CALLBACK_1(HelloWorld::menuReturnCallback, this));
	}
	int num[5];
	//int output[5];
	int endnum = 5;
	for (int i = 0; i < 5; ++i)
	{
		num[i] = i;
	}
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; ++i)
	{
		for (int  k = 0; k < 5; ++k)
		{
			int p = rand()%endnum;
			int t = num[k];
			num[k] = num[p];
			num[p] = t;
		}
		for (int j = 0; j < 5; ++j)
		{
			te[i][num[j]]->setPosition(20 + 45 * i, 15 + 35 * j);
		}
	}	

	auto menu = Menu::create(NULL);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			menu->addChild(te[i][j]);
		}
	}
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 0);
    return true;
	//delete []sp;
	//delete []te;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
void HelloWorld::menuReturnCallback(cocos2d::Ref* pSender)
{
	auto label = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
		 Director::getInstance()->getVisibleSize().height - label->getContentSize().height));
	this->addChild(label, 1);
}