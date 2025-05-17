#include "Suni2.h"
#include "Suni3.h"
#include "Suni4.h"
#include "Suni5.h"
#include "Suni6.h"
#include "Suni7.h"
#include "Suni_app.h"

void Suni_app::Taoj_cay_phan_cap() {
	new Suni2("Read", this);
	new Suni3("Pult", this);
	new Suni4("Set", this);
	new Suni5("Get", this);
	new Suni6("Print", this);
	new Suni7("CoffeeGet", this);
	Virt_obj->GetVater("Sys")->set_sv((TYPE_SIGNAL)(&Suni2::signal), Virt_obj->GetVater("Read"), (TYPE_HANDEL)(&Suni2::handler));
	Virt_obj->GetVater("Read")->set_sv((TYPE_SIGNAL)(&Suni2::signal), Virt_obj->GetVater("Set"), (TYPE_HANDEL)(&Suni4::handler));
	Virt_obj->GetVater("Set")->set_sv((TYPE_SIGNAL)(&Suni4::signal), Virt_obj->GetVater("Print"), (TYPE_HANDEL)(&Suni6::handler));
	Virt_obj->GetVater("Read")->set_sv((TYPE_SIGNAL)(&Suni2::signal), Virt_obj->GetVater("Print"), (TYPE_HANDEL)(&Suni6::handler));
	Virt_obj->GetVater("Sys")->set_sv((TYPE_SIGNAL)(&Suni2::signal_go), Virt_obj->GetVater("Print"), (TYPE_HANDEL)(&Suni6::handler));
	Virt_obj->GetVater("Read")->set_sv((TYPE_SIGNAL)(&Suni2::signal), Virt_obj->GetVater("Get"), (TYPE_HANDEL)(&Suni5::handler));
	Virt_obj->GetVater("Get")->set_sv((TYPE_SIGNAL)(&Suni5::signal), Virt_obj->GetVater("Print"), (TYPE_HANDEL)(&Suni6::handler));
	Virt_obj->GetVater("Read")->set_sv((TYPE_SIGNAL)(&Suni2::signal), Virt_obj->GetVater("Pult"), (TYPE_HANDEL)(&Suni3::handler));
	Virt_obj->GetVater("Pult")->set_sv((TYPE_SIGNAL)(&Suni3::signal), Virt_obj->GetVater("Print"), (TYPE_HANDEL)(&Suni6::handler));
	Virt_obj->GetVater("Pult")->set_sv((TYPE_SIGNAL)(&Suni3::signal), Virt_obj->GetVater("CoffeeGet"), (TYPE_HANDEL)(&Suni7::handler));
	Virt_obj->GetVater("CoffeeGet")->set_sv((TYPE_SIGNAL)(&Suni7::signal), Virt_obj->GetVater("Print"), (TYPE_HANDEL)(&Suni6::handler));
	Virt_obj->GetVater("CoffeeGet")->set_sv((TYPE_SIGNAL)(&Suni2::signal), Virt_obj->GetVater("Get"), (TYPE_HANDEL)(&Suni5::handler));
}
void Suni_app::pearnet_tong() {
	Virt_obj->Set_status_all(1);
	string cmd;
	getline(cin, cmd, ' ');
	Virt_obj->GetVater("Sys")->get_sv((TYPE_SIGNAL)(&Suni2::signal_go), cmd, Virt_obj->GetVater("Print"));
	do {
		cin >> cmd;
		Virt_obj->GetVater("Sys")->get_sv((TYPE_SIGNAL)
			(&Suni2::signal), cmd, Virt_obj->GetVater("Read"));
	} while (cmd != "Cancel" and cmd != "SHOWTREE");
}
Suni_app::Suni_app() : Suni("Sys", Virt_obj) { number = 1; };
void Suni_app::signal(string& stroka) {
}

void Suni_app::handler(string stroka) {
};
Suni_app::Suni_app(string name, Suni* pt) : Suni(name, pt) { number = 1; }