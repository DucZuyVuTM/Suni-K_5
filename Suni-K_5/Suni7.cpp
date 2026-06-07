#include "Suni2.h"
#include "Suni7.h"
#include "Suni_app.h"

// Coffee Dispenser

Suni7::Suni7(Suni* Suni_main, string S_chuooix) : Suni(Suni_main, S_chuooix)
// Вызов конструктора класса Suni
{} // Конструктор класса Suni7

// Метод возврата номера класса
int Suni7::Lay_solop() {
	return 7;
}

void Suni7::chuyen_tin_hieu(string& tin_nhan) {
	if (tin_nhan != "\nReady to work")
		tin_nhan = "\nTake the coffee " + tin_nhan;
}

void Suni7::nhan_tin_hieu(string tin_nhan) {
	if (tin_nhan.find("/") == -1)
		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni7::chuyen_tin_hieu), tin_nhan,
			Virt_obj -> Timf_object_from_current("Display")
		);
	else {
		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni7::chuyen_tin_hieu),
			tin_nhan.substr(0, tin_nhan.find("/")),
			Virt_obj -> Timf_object_from_current("Display")
		);

		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
			tin_nhan.substr(tin_nhan.find("/") + 1),
			Virt_obj -> Timf_object_from_current("Change Returner")
		);
	}

	this -> phat_tin_hieu(
		(TYPE_SIGNAL)(&Suni7::chuyen_tin_hieu), "\nReady to work",
		Virt_obj -> Timf_object_from_current("Display")
	);
}

Suni7::~Suni7() {} // Деструктор класса Suni7
