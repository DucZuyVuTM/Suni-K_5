#include "Suni3.h"

// Control Panel

Suni3::Suni3(Suni* Suni_main, string S_chuooix) : Suni(Suni_main, S_chuooix)
// Вызов конструктора класса Suni
{} // Конструктор класса Suni3

// Метод возврата номера класса
int Suni3::Lay_solop() {
	return 3;
}

void Suni3::chuyen_tin_hieu(string& tin_nhan) {
	if (tin_nhan == "false")
		tin_nhan = "\nThere is not enough money";
}

void Suni3::nhan_tin_hieu(string tin_nhan) {
	bool check = true;
	for (int i = 0;
			i < Virt_obj -> Timf_object_from_current("System") -> Ncoffee.size();
			i++) {

		if ((tin_nhan == Virt_obj -> Timf_object_from_current("System") -> Ncoffee[i])
			&& (Virt_obj -> Timf_object_from_current("System") -> Pcoffee[i] <=
				Virt_obj -> Timf_object_from_current("System") -> sum)) {

			Virt_obj-> Timf_object_from_current("System")
					-> sum
			-=
			Virt_obj-> Timf_object_from_current("System")
					-> Pcoffee[i];

			check = false;

			if (Virt_obj -> Timf_object_from_current("System") -> sum == 0)
				this -> phat_tin_hieu(
					(TYPE_SIGNAL)(&Suni3::chuyen_tin_hieu), tin_nhan,
					Virt_obj -> Timf_object_from_current("Coffee Dispenser")
				);
			else
				this -> phat_tin_hieu(
					(TYPE_SIGNAL)(&Suni3::chuyen_tin_hieu), tin_nhan + "/change",
					Virt_obj -> Timf_object_from_current("Coffee Dispenser")
				);
		}
	}
	if (check)
		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni3::chuyen_tin_hieu), "false",
			Virt_obj -> Timf_object_from_current("Display")
		);
}

Suni3::~Suni3() {} // Деструктор класса Suni3
