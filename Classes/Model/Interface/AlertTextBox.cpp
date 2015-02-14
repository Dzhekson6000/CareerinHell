#include "AlertTextBox.h"

AlertTextBox::AlertTextBox(Settings* settings, std::string text )
{
	AlertBox::init(settings);
	createText(text, "fonts/rupster.ttf");
}
