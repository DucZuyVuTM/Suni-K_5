#include "Suni4.h"

// Money Receiver

Suni4::Suni4(Suni* Suni_main, string S_chuooix) : Suni(Suni_main, S_chuooix)
// Вызов конструктора класса Suni
{} // Конструктор класса Suni4

// Метод возврата номера класса
int Suni4::Lay_solop() {
	return 4;
}

void Suni4::chuyen_tin_hieu(string& tin_nhan) {
	tin_nhan = "\nThe amount: " + tin_nhan;
}

void Suni4::nhan_tin_hieu(string tin_nhan) {
	Virt_obj -> Timf_object_from_current("System") -> sum += stoi(tin_nhan);

	phat_tin_hieu(
		(TYPE_SIGNAL)(&Suni4::chuyen_tin_hieu),
		to_string(Virt_obj -> Timf_object_from_current("System") -> sum),
		Virt_obj -> Timf_object_from_current("Display")
	);
}

Suni4::~Suni4() {} // Деструктор класса Suni4
