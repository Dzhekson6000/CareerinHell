#include "ReadLevel.h"

ReadLevel::ReadLevel(){
	_level = new Level();
}

void ReadLevel::readFile(std:: string fileName){
	std::vector<Cell*>* cells = new std::vector<Cell*>;

	std::string fullPath = FileUtils::sharedFileUtils()->fullPathForFilename(fileName);

	TiXmlDocument *xmlFile = new TiXmlDocument(fullPath.c_str());
	if(!xmlFile->LoadFile()) //файл не открылся
		CCLOG("[1]Error load file xml: %s", fullPath.c_str());

	TiXmlElement *xmlLevel = 0;
	xmlLevel = xmlFile->FirstChildElement("level");
	if(xmlLevel == NULL)//не был найден корневой элемент
		CCLOG("[2]Error open \"level\"");

	TiXmlElement *xmlElement = 0;
	xmlElement = xmlLevel->FirstChildElement();
	if(xmlElement == NULL)
		CCLOG("[3]Error open child");

	
	while(xmlElement != NULL)//перебираем элементы
	{
		const char * nameElement = xmlElement->Value();
		if(!strcmp(nameElement, "Wall") )
		{
			bool rotate=false;
			bool show = true;


			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(xmlElement->Attribute("rotate"), "l") ) rotate = true;
			if(!strcmp(xmlElement->Attribute("show"), "false") ) show = false;

			if(xmlElement->Attribute("x2") == NULL && xmlElement->Attribute("y2") == NULL)
			{
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				cells->push_back(new Wall(new PPoint(x*50, y*50), tip, rotate, show) );
			} else {
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				int x2 = atoi(xmlElement->Attribute("x2"));
				int y2 = atoi(xmlElement->Attribute("y2"));

				for(int i = x; i <= x2; i++) for(int j = y; j <= y2; j++)
					cells->push_back(new Wall(new PPoint(i*50, j*50), tip, rotate, show) );
			}
		}else
		if(!strcmp(nameElement, "Flooring") )
		{
			std::string tip = xmlElement->Attribute("tip");

			if(xmlElement->Attribute("x2") == NULL && xmlElement->Attribute("y2") == NULL)
			{
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				cells->push_back(new Flooring(new PPoint(x*50, y*50), tip) );
			} else {
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				int x2 = atoi(xmlElement->Attribute("x2"));
				int y2 = atoi(xmlElement->Attribute("y2"));

				for(int i = x; i <= x2; i++) for(int j = y; j <= y2; j++)
					cells->push_back(new Flooring(new PPoint(i*50, j*50), tip) );
			}
		}else
		if(!strcmp(nameElement, "AngleWall") )
		{
			int tipAngle = 1;
			bool show = true;

			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(xmlElement->Attribute("show"), "false") ) show = false;
			tipAngle = atoi(xmlElement->Attribute("tipAngle"));

			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));

			cells->push_back(new AngleWall(new PPoint(x*50, y*50), tip, tipAngle, show) );
		}else
		if(!strcmp(nameElement, "IntersectionWall") )
		{
			int tipIntersection = 0;
			bool show = true;

			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(xmlElement->Attribute("show"), "false") ) show = false;
			tipIntersection = atoi(xmlElement->Attribute("tipIntersection"));

			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));

			cells->push_back(new IntersectionWall(new PPoint(x*50, y*50), tip, tipIntersection, show) );
		}else
		if(!strcmp(nameElement, "EndWall") )
		{
			int tipEnd = 0;
			bool show = true;

			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(xmlElement->Attribute("show"), "false") ) show = false;
			tipEnd = atoi(xmlElement->Attribute("tipEnd"));

			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));

			cells->push_back(new EndWall(new PPoint(x*50, y*50), tip, tipEnd, show) );
		}else
		if(!strcmp(nameElement, "Portal") )
		{
			bool rotate=false;
			
			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(xmlElement->Attribute("rotate"), "l") ) rotate = true;
			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));

			cells->push_back(new CellPortal(new PPoint(x*50, y*50), tip, rotate) );
		}

		xmlElement = xmlElement->NextSiblingElement();
	}

	
	std::vector<Character*>* characters = new std::vector<Character*>;
	characters->push_back(new Boat(1, new PPoint(5*50, 50*5), "boat", true ) );

	_level->setCells(cells);
	_level->setCharacters(characters);
}