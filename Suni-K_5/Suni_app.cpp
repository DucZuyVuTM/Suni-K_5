#include "Suni_app.h"
#include "Suni2.h"
#include "Suni3.h"
#include "Suni4.h"
#include "Suni5.h"
#include "Suni6.h"
#include "Suni7.h"

// Конструктор класса Suni_app
Suni_app::Suni_app(Suni* Suni_main) : Suni(Suni_main) {}

// Метод создания дерева иерархии
void Suni_app::Taoj_cay_phan_cap() {
	// Построение дерева иерархии объектов
	Suni* ptr_shl_ddeens2 = new Suni2(this, "Command Reader");
	Suni* ptr_shl_ddeens3 = new Suni3(this, "Control Panel");
	Suni* ptr_shl_ddeens4 = new Suni4(this, "Money Receiver");
	Suni* ptr_shl_ddeens5 = new Suni5(this, "Change Returner");
	Suni* ptr_shl_ddeens6 = new Suni6(this, "Display");
	Suni* ptr_shl_ddeens7 = new Suni7(this, "Coffee Dispenser");

	// Установка связей сигналов и обработчиков между объектами
	caidat_ketnoi(
		(TYPE_SIGNAL)&Suni2::chuyen_tin_hieu,
		ptr_shl_ddeens2,
		(TYPE_HANDLER)(&Suni2::nhan_tin_hieu)
	);

	ptr_shl_ddeens2->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
		ptr_shl_ddeens4,
		(TYPE_HANDLER)(&Suni4::nhan_tin_hieu)
	);

	ptr_shl_ddeens4->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni4::chuyen_tin_hieu),
		ptr_shl_ddeens6,
		(TYPE_HANDLER)(&Suni6::nhan_tin_hieu)
	);

	ptr_shl_ddeens2->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
		ptr_shl_ddeens6,
		(TYPE_HANDLER)(&Suni6::nhan_tin_hieu)
	);

	caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu1), 
		ptr_shl_ddeens6,
		(TYPE_HANDLER)(&Suni6::nhan_tin_hieu)
	);

	ptr_shl_ddeens2->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
		ptr_shl_ddeens5,
		(TYPE_HANDLER)(&Suni5::nhan_tin_hieu)
	);

	ptr_shl_ddeens5->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni5::chuyen_tin_hieu),
		ptr_shl_ddeens6,
		(TYPE_HANDLER)(&Suni6::nhan_tin_hieu)
	);

	ptr_shl_ddeens2->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
		ptr_shl_ddeens3,
		(TYPE_HANDLER)(&Suni3::nhan_tin_hieu)
	);

	ptr_shl_ddeens3->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni3::chuyen_tin_hieu),
		ptr_shl_ddeens6,
		(TYPE_HANDLER)(&Suni6::nhan_tin_hieu)
	);

	ptr_shl_ddeens3->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni3::chuyen_tin_hieu),
		ptr_shl_ddeens7,
		(TYPE_HANDLER)(&Suni7::nhan_tin_hieu)
	);

	ptr_shl_ddeens7->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni7::chuyen_tin_hieu),
		ptr_shl_ddeens6,
		(TYPE_HANDLER)(&Suni6::nhan_tin_hieu)
	);

	ptr_shl_ddeens2->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
		ptr_shl_ddeens5,
		(TYPE_HANDLER)(&Suni5::nhan_tin_hieu)
	);

	ptr_shl_ddeens7->caidat_ketnoi(
		(TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu),
		ptr_shl_ddeens5,
		(TYPE_HANDLER)(&Suni5::nhan_tin_hieu)
	);
}

// Метод запуска системы
int Suni_app::pearnet_tong() {
	// Приведение всех объектов в состояние готовности
	Virt_obj -> Active();

	string command;
	getline(cin, command, ' ');

	Virt_obj-> Timf_object_from_current("System")
			-> phat_tin_hieu((TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu1), command, Virt_obj
			-> Timf_object_from_current("Display"));

	do {
		cin >> command;
		Virt_obj-> Timf_object_from_current("System")
				-> phat_tin_hieu((TYPE_SIGNAL)(&Suni2::chuyen_tin_hieu), command, Virt_obj
				-> Timf_object_from_current("Command Reader"));
	} while (command != "Cancel" && command != "SHOWTREE");

	return(0);
}

Suni_app::~Suni_app() {}
