#include "Suni4.h"



void Suni4::signal(string& now) {
	now = "\nThe amount: " + now;
}
void Suni4::handler(string now) {
	Virt_obj->GetVater("Sys")->summ += stoi(now.c_str());
	get_sv((TYPE_SIGNAL)(&Suni4::signal), to_string(Virt_obj->GetVater("Sys")->summ), Virt_obj->GetVater("Print"));
}