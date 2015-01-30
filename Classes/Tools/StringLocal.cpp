#include "StringLocal.h"

StringLocal::StringLocal()
{

}


std::string StringLocal::getString(std::string key )
{
	return _strings[key];
}

void StringLocal::clear()
{
	_strings.clear();
}

void StringLocal::deleteString( std::string key )
{
	_strings.erase(key);
}

bool StringLocal::emptyString( std::string key )
{
	return _strings.empty();
}

int StringLocal::getSize()
{
	return _strings.size();
}

void StringLocal::insertString( std::string key, std::string value )
{
	_strings[key] = value;
}
