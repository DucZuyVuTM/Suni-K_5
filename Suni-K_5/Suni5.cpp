#include "Suni5.h"

// Change Returner

Suni5::Suni5(Suni* Suni_main, string S_chuooix) : Suni(Suni_main, S_chuooix)
// Вызов конструктора класса Suni
{} // Конструктор класса Suni5

// Метод возврата номера класса
int Suni5::Lay_solop() {
	return 5;
}

void Suni5::chuyen_tin_hieu(string& tin_nhan) {
	if (tin_nhan.find("/") == -1)
		tin_nhan = "\nTake the change: 10 * "
			+ tin_nhan.substr(0, tin_nhan.find("$")) + " rub.,  5 * "
			+ tin_nhan.substr(tin_nhan.find("$") + 1) + " rub.";
	else
		tin_nhan = "\nTake the money: 10 * "
			+ tin_nhan.substr(0, tin_nhan.find("/")) + " rub.,  5 * "
			+ tin_nhan.substr(tin_nhan.find("/") + 1) + " rub.\nReady to work";
}

void Suni5::nhan_tin_hieu(string tin_nhan) {
	this -> phat_tin_hieu(
		(TYPE_SIGNAL)(&Suni5::chuyen_tin_hieu), tin_nhan,
		Virt_obj -> Timf_object_from_current("Display")
	);
}

Suni5::~Suni5() {} // Деструктор класса Suni5
