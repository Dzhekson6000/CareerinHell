#include "ReadLevel.h"

ReadLevel::ReadLevel(){
	_level = new Level();
}

void ReadLevel::readFile(std:: string fileName){
	List<Cell*>* cells = new List<Cell*>();

	std::string fullPath = FileUtils::sharedFileUtils()->fullPathForFilename("map/map1.xml");

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
				cells->append(new Wall(new PPoint(x*50, y*50), tip, rotate, show) );
			} else {
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				int x2 = atoi(xmlElement->Attribute("x2"));
				int y2 = atoi(xmlElement->Attribute("y2"));

				for(int i = x; i <= x2; i++) for(int j = y; j <= y2; j++)
					cells->append(new Wall(new PPoint(i*50, j*50), tip, rotate, show) );
			}
			
			//cells->append();




		}else
		if(!strcmp(nameElement, "Flooring") )
		{
			std::string tip = xmlElement->Attribute("tip");

			if(xmlElement->Attribute("x2") == NULL && xmlElement->Attribute("y2") == NULL)
			{
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				cells->append(new Flooring(new PPoint(x*50, y*50), tip) );
			} else {
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				int x2 = atoi(xmlElement->Attribute("x2"));
				int y2 = atoi(xmlElement->Attribute("y2"));

				for(int i = x; i <= x2; i++) for(int j = y; j <= y2; j++)
					cells->append(new Flooring(new PPoint(i*50, j*50), tip) );
			}
		}

		xmlElement = xmlElement->NextSiblingElement();
	} 

	_level->_cells = cells;
}