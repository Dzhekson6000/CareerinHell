#ifndef ALERTTEXTBOX_H__
#define ALERTTEXTBOX_H__

#include "Tools/AlertBox.h"

class AlertTextBox:public AlertBox
{
private:

public:
	AlertTextBox(Settings* settings, std::string text);
};
#endif // ALERTTEXTBOX_H__