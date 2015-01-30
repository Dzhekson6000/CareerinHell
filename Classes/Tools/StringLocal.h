#ifndef STRINGLOCAL_H_
#define STRINGLOCAL_H_
#include <unordered_map>
#include <string>

class StringLocal
{
private:
	std::unordered_map<std::string, std::string> _strings;
public:
	StringLocal();
	void insertString(std::string key, std::string value);
	std::string getString(std::string key);
	int getSize();
	bool emptyString(std::string key);
	void deleteString(std::string key);
	void clear();
};


#endif /* STRINGLOCAL_H_ */