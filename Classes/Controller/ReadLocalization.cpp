#include "ReadLocalization.h"

ReadLocalization::ReadLocalization()
{
	_stringLocal = new StringLocal();
	_language = "eng";
}

void ReadLocalization::readLocalization()
{
	readLocalization(_language);
}

void ReadLocalization::readLocalization( std::string language )
{
	std::string fullPath = FileUtils::sharedFileUtils()->fullPathForFilename(PATH_STRING "localization.xml");

	TiXmlDocument *xmlFile = new TiXmlDocument();
	ssize_t fileSize = 0;
	unsigned char * fileContents = CCFileUtils::sharedFileUtils( ) -> getFileData( fullPath.c_str() , "r", &fileSize );
	xmlFile->Parse((const char*)fileContents, 0, TIXML_ENCODING_UTF8);

	TiXmlElement *xmlLocalization = 0;
	xmlLocalization = xmlFile->FirstChildElement("localization");
	if(xmlLocalization == NULL)
		CCLOG("[2]Error open \"localization\"");

	TiXmlElement *xmlElement = 0;
	xmlElement = xmlLocalization->FirstChildElement();
	if(xmlElement == NULL)
		CCLOG("[3]Error open child");

	while(xmlElement != NULL)
	{
		std::string local = xmlElement->Attribute("local");
		if(!strcmp(local.c_str(), language.c_str()) )
		{
			std::string name = xmlElement->Attribute("name");
			std::string value = xmlElement->FirstChild()->Value();
			_stringLocal->insertString(name, value);
		}

		xmlElement = xmlElement->NextSiblingElement();
	}

}

