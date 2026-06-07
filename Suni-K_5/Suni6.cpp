#include "Suni6.h"

// Display

Suni6::Suni6(Suni* Suni_main, string S_chuooix) : Suni(Suni_main, S_chuooix)
// Вызов конструктора класса Suni
{} // Конструктор класса Suni6

// Метод возврата номера класса
int Suni6::Lay_solop() {
	return 6;
}

void Suni6::chuyen_tin_hieu(string&) {}

void Suni6::nhan_tin_hieu(string tin_nhan) {
	cout << tin_nhan;
}

Suni6::~Suni6() {} // Деструктор класса Suni6
