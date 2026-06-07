#include "Suni2.h"

// Command Reader

Suni2::Suni2(Suni* Suni_main, string S_chuooix) : Suni(Suni_main, S_chuooix)
// Вызов конструктора класса Suni
{} // Конструктор класса Suni2

// Метод возврата номера класса
int Suni2::Lay_solop() {
	return 2;
}

void Suni2::chuyen_tin_hieu(string& tin_nhan) {
	if (tin_nhan == "money" || tin_nhan == "change") {
		int cx5, cx10;

		cx10 = Virt_obj -> Timf_object_from_current("System") -> sum / 10;
		Virt_obj -> Timf_object_from_current("System") -> sum -= cx10 * 10;

		cx5 = Virt_obj -> Timf_object_from_current("System") -> sum / 5;
		Virt_obj -> Timf_object_from_current("System") -> sum -= cx5 * 5;

		Virt_obj -> Timf_object_from_current("System") -> c5 -= cx5;
		Virt_obj -> Timf_object_from_current("System") -> c10 -= cx10;

		if (tin_nhan == "money")
			tin_nhan = to_string(cx10) + "/" + to_string(cx5);
		if (tin_nhan == "change")
			tin_nhan = to_string(cx10) + "$" + to_string(cx5);
	}

	if (tin_nhan == "false")
		tin_nhan = "\nTake the money back, no change";
}

void Suni2::nhan_tin_hieu(string tin_nhan) {
	if (tin_nhan == "Refund") {
		cin >> tin_nhan;

		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), tin_nhan,
			Virt_obj -> Timf_object_from_current("Change Returner")
		);
	}
	else if (tin_nhan == "Coffee") {
		cin >> tin_nhan;

		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), tin_nhan,
			Virt_obj -> Timf_object_from_current("Control Panel")
		);
	}
	else if (tin_nhan == "Cancel") {
		this -> phat_tin_hieu(
			(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), "\nTurned off",
			Virt_obj -> Timf_object_from_current("Display")
		);
	}
	else if (tin_nhan == "SHOWTREE") {
		cout << endl;

		// Вывод дерева иерархии объектов системы с отметкой о готовности
		Virt_obj -> Timf_object_from_current("System") -> pearnet1();
	}
	else {
		if (stoi(tin_nhan) == 50 || stoi(tin_nhan) == 100) {
			if ((Virt_obj -> Timf_object_from_current("System") -> c5 * 5) +
				(Virt_obj -> Timf_object_from_current("System") -> c10 * 10)
				< stoi(tin_nhan))

				this -> phat_tin_hieu(
					(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), "false",
					Virt_obj -> Timf_object_from_current("Display")
				);
			else
				this -> phat_tin_hieu(
					(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), tin_nhan,
					Virt_obj -> Timf_object_from_current("Money Receiver")
				);
		}
		else if (stoi(tin_nhan) == 5 || stoi(tin_nhan) == 10) {
			this -> phat_tin_hieu(
				(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), tin_nhan,
				Virt_obj -> Timf_object_from_current("Money Receiver")
			);

			if (tin_nhan == "5")
				Virt_obj -> Timf_object_from_current("System") -> c5 += 1;
			if (tin_nhan == "10")
				Virt_obj -> Timf_object_from_current("System") -> c10 += 1;
		}
	}
}

void Suni2::chuyen_tin_hieu1(string& tin_nhan) {
	int n, p;
	n = stoi(tin_nhan);
	string Cname;

	for (int i = 0; i < n; i++) {
		cin >> Cname;
		Virt_obj -> Timf_object_from_current("System") -> Ncoffee.push_back(Cname);
	}

	for (int i = 0; i < n; i++) {
		cin >> p;
		Virt_obj -> Timf_object_from_current("System") -> Pcoffee.push_back(p);
	}

	cin >> Virt_obj -> Timf_object_from_current("System") -> c5;
	cin >> Virt_obj -> Timf_object_from_current("System") -> c10;

	tin_nhan = "Ready to work";
}

Suni2::~Suni2() {} // Деструктор класса Suni2
