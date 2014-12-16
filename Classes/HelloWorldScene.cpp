#include "HelloWorldScene.h"
#include "Controller/ReadLevel.h"

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
	rl.readFile("map/map1.txt");
	
	Level* level = rl._level;
	for(int i = 0; i < level->_cells->size(); i++)
	{
		this->addChild(level->_cells->get(level->_cells->size() -1 -i   )->getTexture() );
	}


    return true;
}


//нужно генерировать комнаты.