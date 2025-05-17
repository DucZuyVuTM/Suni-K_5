#include "Suni3.h"

void Suni3::signal(string& now) {
	if (now == "false") {
		now = "\nThere is not enough money";
	}
}
void Suni3::handler(string now) {
	bool flag = true;
	for (int i = 0; i < Virt_obj->GetVater("Sys")->ncoffe.size(); i++) {
		if ((now == Virt_obj->GetVater("Sys")->ncoffe[i]) and ((Virt_obj->GetVater("Sys")->pcoffe[i]) <= (Virt_obj->GetVater("Sys")->summ))) {
			Virt_obj->GetVater("Sys")->summ -= Virt_obj->GetVater("Sys")->pcoffe[i];
			flag = false;
			if (Virt_obj->GetVater("Sys")->summ == 0) {
				this->get_sv((TYPE_SIGNAL)(&Suni3::signal), now, Virt_obj->GetVater("CoffeeGet"));
			}
			else
				this->get_sv((TYPE_SIGNAL)
					(&Suni3::signal), now + "/" + "change", Virt_obj->GetVater("CoffeeGet"));
		}
	}
	if (flag)
		this->get_sv((TYPE_SIGNAL)(&Suni3::signal), "false", Virt_obj->GetVater("Print"));
}