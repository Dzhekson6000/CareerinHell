#include "ReadLevel.h"

ReadLevel::ReadLevel(Settings* settings){
	_level = new Level();
	_settings = settings;
}

ReadLevel::ReadLevel(Settings* settings, std:: string fileName )
{
	_level = new Level();
	_settings = settings;
	readFile(fileName);
}

void ReadLevel::readFile(std::string fileName){
	std::vector<TileCell*> cells;
	std::vector<Character*> charactersAI;
	Questions question = Questions();
	int xPortalCell = 0;
	int yPortalCell = 0;

	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(fileName);

	TiXmlDocument *xmlFile = new TiXmlDocument();
	ssize_t fileSize = 0;
	Data data =  CCFileUtils::getInstance()->getDataFromFile(fullPath);
	unsigned char * fileContents = data.getBytes() ;
	xmlFile->Parse((const char*)fileContents, 0, TIXML_ENCODING_UTF8);

	TiXmlElement *xmlLevel = 0;
	xmlLevel = xmlFile->FirstChildElement("level");
	if(xmlLevel == NULL)
		CCLOG("[2]Error open \"level\"");

	TiXmlElement *xmlElement = 0;
	xmlElement = xmlLevel->FirstChildElement();
	if(xmlElement == NULL)
		CCLOG("[3]Error open child");

	
	while(xmlElement != NULL)
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
				cells.push_back(new Wall(PPoint(x, y), tip, rotate, show) );
			} else {
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				int x2 = atoi(xmlElement->Attribute("x2"));
				int y2 = atoi(xmlElement->Attribute("y2"));

				for(int i = x; i <= x2; i++) for(int j = y; j <= y2; j++)
					cells.push_back(new Wall(PPoint(i, j), tip, rotate, show) );
			}
		}else
		if(!strcmp(nameElement, "Flooring") )
		{
			std::string tip = xmlElement->Attribute("tip");

			if(xmlElement->Attribute("x2") == NULL && xmlElement->Attribute("y2") == NULL)
			{
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				cells.push_back(new Flooring(PPoint(x, y), tip) );
			} else {
				int x = atoi(xmlElement->Attribute("x"));
				int y = atoi(xmlElement->Attribute("y"));
				int x2 = atoi(xmlElement->Attribute("x2"));
				int y2 = atoi(xmlElement->Attribute("y2"));

				for(int i = x; i <= x2; i++) for(int j = y; j <= y2; j++)
					cells.push_back(new Flooring(PPoint(i, j), tip) );
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

			cells.push_back(new AngleWall(PPoint(x, y), tip, tipAngle, show) );
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

			cells.push_back(new IntersectionWall(PPoint(x, y), tip, tipIntersection, show) );
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

			cells.push_back(new EndWall(PPoint(x, y), tip, tipEnd, show) );
		}else
		if(!strcmp(nameElement, "Portal") )
		{
			bool rotate=false;
			
			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(xmlElement->Attribute("rotate"), "l") ) rotate = true;
			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));
			xPortalCell = x;
			yPortalCell = y;
			cells.push_back(new CellPortal(PPoint(x, y), tip, rotate) );
		}else
		if(!strcmp(nameElement, "Character") )
		{
			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));
			std::string tip = xmlElement->Attribute("tip");

			if(!strcmp(tip.c_str(), "boat") ) charactersAI.push_back(new Boat(1, _level, PPoint(x, y), tip, false));
		}else
		if(!strcmp(nameElement, "Bed") )
		{
			bool rotate=false;

			if(!strcmp(xmlElement->Attribute("rotate"), "l") ) rotate = true;
			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));

			cells.push_back(new Bed(PPoint(x, y), rotate) );
		}else
		if(!strcmp(nameElement, "Altar") )
		{
			bool rotate=false;

			if(!strcmp(xmlElement->Attribute("rotate"), "l") ) rotate = true;
			int x = atoi(xmlElement->Attribute("x"));
			int y = atoi(xmlElement->Attribute("y"));

			cells.push_back(new Altar(PPoint(x, y), rotate) );
		}else
		if(!strcmp(nameElement, "Questions") )
		{
			TiXmlElement *xmlQuestionsElement = xmlQuestionsElement = xmlElement->FirstChildElement();
			if(xmlQuestionsElement == NULL)
			{
				xmlElement = xmlElement->NextSiblingElement();
				continue;
			}
			while(xmlQuestionsElement != NULL)
			{
				const char * nameQuestionsElement = xmlQuestionsElement->Value();
				if(!strcmp(nameQuestionsElement, "Kill") )
				{
					int id = atoi(xmlQuestionsElement->Attribute("id"));
					question.addQuestion(new KillQuestion(_settings, id));
				}
				
				xmlQuestionsElement = xmlQuestionsElement->NextSiblingElement();
			}
		}

		xmlElement = xmlElement->NextSiblingElement();
	}

	_level->setQuestions(question);
	_level->setXPortalCell(xPortalCell);
	_level->setYPortalCell(yPortalCell);
	_level->setTileCells(cells);
	_level->setCharactersAI(charactersAI);
}