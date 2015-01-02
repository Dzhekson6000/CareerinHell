#include "HelloWorldScene.h"
#include "Controller/ReadLevel.h"
#include "Model\Weather\Snow.h"
#include "Tools\Scroller.h"

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	ReadLevel rl = ReadLevel();
	rl.readFile("map/home.xml");
	
	Scroller* scroll = Scroller::create();
	this->addChild(scroll);

	Level* level = rl._level;
	for(int i = 0; i < level->_cells->size(); i++)
	{
		scroll->addChild(level->_cells->get(level->_cells->size() -1 -i   )->getTexture() );
	}

	for(int i = 0; i < level->_characters->size(); i++)
	{
		scroll->addChild(level->_characters->get(level->_characters->size() -1 -i   )->getTexture() );
	}

	Snow * s = Snow::create();
	this->addChild(s);


    return true;
}


//нужно генерировать комнаты.