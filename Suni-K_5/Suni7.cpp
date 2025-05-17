#include "Suni2.h"
#include "Suni7.h"
#include "Suni_app.h"

Suni7::Suni7(string name, Suni* pt) :Suni(name, pt) {
	number = 7;
};
void Suni7::signal(string& now) {
	if (now != "\nReady to work")
		now = "\nTake the coffee " + now;
}
void Suni7::handler(string now) {
	if (now.find("/") == -1)
		this->get_sv((TYPE_SIGNAL)(&Suni7::signal), now, Virt_obj->GetVater("Print"));
	else {
		this->get_sv((TYPE_SIGNAL)
			(&Suni7::signal), now.substr(0, now.find("/")), Virt_obj->GetVater("Print"));
		this->get_sv((TYPE_SIGNAL)(&Suni2::signal), now.substr(now.find("/")
			+ 1), Virt_obj->GetVater("Get"));
	}
	this->get_sv((TYPE_SIGNAL)(&Suni7::signal), "\nReady to work", Virt_obj->GetVater("Print"));
}