#include "Suni2.h"

void Suni2::signal(string& now) {
	if (now == "money") {
		int fife, ten;
		ten = (Virt_obj->GetVater("Sys")->summ) / 10;
		Virt_obj->GetVater("Sys")->summ -= ten * 10;
		fife = Virt_obj->GetVater("Sys")->summ / 5;
		Virt_obj->GetVater("Sys")->summ -= fife * 5;
		Virt_obj->GetVater("Sys")->fi -= fife;
		Virt_obj->GetVater("Sys")->te -= ten;
		now = to_string(ten) + "/" + to_string(fife);
	}
	if (now == "change") {
		int fife, ten;
		ten = (Virt_obj->GetVater("Sys")->summ) / 10;
		Virt_obj->GetVater("Sys")->summ -= ten * 10;
		fife = Virt_obj->GetVater("Sys")->summ / 5;
		Virt_obj->GetVater("Sys")->summ -= fife * 5;
		Virt_obj->GetVater("Sys")->fi -= fife;
		Virt_obj->GetVater("Sys")->te -= ten;
		now = to_string(ten) + "$" + to_string(fife);
	}
	if (now == "false")
		now = "\nTake the money back, no change";
}
void Suni2::handler(string now) {
	if (now == "Refund") {
		cin >> now;
		this->get_sv((TYPE_SIGNAL)(&Suni2::signal), now, Virt_obj->GetVater("Get"));
	}
	else if (now == "Coffee") {
		cin >> now;
		this->get_sv((TYPE_SIGNAL)(&Suni2::signal), now, Virt_obj->GetVater("Pult"));
	}
	else if (now == "Cancel") {
		this->get_sv((TYPE_SIGNAL)(&Suni2::signal), "\nTurned off", Virt_obj->GetVater("Print"));
	}
	else if (now == "SHOWTREE") {
		Virt_obj->GetVater("Sys")->print_status(0);
	}
	else {
		if (stoi(now.c_str()) == 50) {
			if ((Virt_obj->GetVater("Sys")->fi * 5) + (Virt_obj->GetVater("Sys")->te * 10) < 50)
				this->get_sv((TYPE_SIGNAL)(&Suni2::signal), "false", Virt_obj->GetVater("Print"));
			else
				this->get_sv((TYPE_SIGNAL)(&Suni2::signal), now, Virt_obj->GetVater("Set"));
		}
		else if (stoi(now.c_str()) == 100) {
			if ((Virt_obj->GetVater("Sys")->fi * 5) + (Virt_obj->GetVater("Sys")->te * 10) < 100)
				this->get_sv((TYPE_SIGNAL)(&Suni2::signal), "false", Virt_obj->GetVater("Print"));
			else
				this->get_sv((TYPE_SIGNAL)(&Suni2::signal), now, Virt_obj->GetVater("Set"));
		}
		else if (stoi(now.c_str()) == 5 || stoi(now.c_str()) == 10) {
			this->get_sv((TYPE_SIGNAL)(&Suni2::signal), now, Virt_obj->GetVater("Set"));
			if (now == "5")
				Virt_obj->GetVater("Sys")->fi += 1;
			if (now == "10")
				Virt_obj->GetVater("Sys")->te += 1;
		}
	}
}

void Suni2::signal_go(string& now) {
	int n, p;
	n = atoi(now.c_str());
	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		Virt_obj->GetVater("Sys")->ncoffe.push_back(name);
	}
	for (int i = 0; i < n; i++) {
		cin >> p;
		Virt_obj->GetVater("Sys")->pcoffe.push_back(p);
	}
	cin >> Virt_obj->GetVater("Sys")->fi;
	cin >> Virt_obj->GetVater("Sys")->te;
	now = "Ready to work";
}