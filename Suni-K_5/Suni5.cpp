#include "Suni5.h"

void Suni5::signal(string& now) {
	if (now.find("/") == -1)
		now = "\nTake the change: 10 * " + now.substr(0, now.find("$")) + " rub., 5 * " + now.substr(now.find("$") + 1) + " rub.";
	else
		now = "\nTake the money: 10 * " + now.substr(0, now.find("/")) + " rub., 5 * " + now.substr(now.find("/") + 1) + " rub.\nReady to work";
}
void Suni5::handler(string now) {
	this->get_sv((TYPE_SIGNAL)(&Suni5::signal), now, Virt_obj->GetVater("Print"));
}