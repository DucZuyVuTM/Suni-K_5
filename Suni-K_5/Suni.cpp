#include "Suni.h"

// Конструктор класса Suni по умолчанию
Suni::Suni() {}

// Конструктор класса Suni с параметрами
Suni::Suni(Suni* Suni_main, string S_chuooix) {
	(*this).S_chuooix = S_chuooix;
	this -> Suni_main = Suni_main;

	if (this -> Suni_main)
		Suni_main -> Suni_luutru.push_back(this);
	else
		Virt_obj -> Suni_luutru.push_back(this);
}

Suni* Suni::Virt_obj = new Suni();

// Метод переименования имени объекта
bool Suni::GanGiaTri(string S_thamsomoi) {
	if (this -> Suni_main)
		for (int i = 0; i < Suni_main -> Suni_luutru.size(); i++)
			if (Suni_main -> Suni_luutru[i] -> S_lay_ten() == S_thamsomoi)
				return false;

	S_chuooix = S_thamsomoi;
	return true;
}

// Mетод возврата адреса подчинённого объекта по имени
Suni* Suni::Doi_tuong_duoi(string S_thamsomoi2) {
	for (int j = 0; j < Suni_luutru.size(); j++)
		if (Suni_luutru[j] -> S_lay_ten() == S_thamsomoi2)
			return Suni_luutru[j];

	return nullptr;
}

// Mетод возврата указателя головного объекта
Suni* Suni::Doi_tuong_boss() {
	return Suni_main;
}

// Mетод вывода дерева иерархии
void Suni::pearnet() {
	if (Doi_tuong_boss())
		cout << endl;

	int tabulia = 0;
	Suni* current = this;

	while (current -> Doi_tuong_boss()) {
		current = current -> Doi_tuong_boss();
		tabulia++;
	}

	for (int i = 0; i < tabulia; i++)
		cout << "    ";

	cout << S_lay_ten();

	for (auto Suni_capduoi : Suni_luutru)
		Suni_capduoi -> pearnet();
}

// Mетод возврата значения свойства S_chuooix
string Suni::S_lay_ten() {
	return S_chuooix;
}

// Метод поиска объекта по имени в поддереве
// если уникальность объекта имеется, иначе возврат nullptr
Suni* Suni::Timf_object_from_current(string S_thamso) {
	queue <Suni*> danhsach;
	Suni* Suni_tim = nullptr;

	danhsach.push(this);

	while (!danhsach.empty()) {
		if (danhsach.front() -> S_lay_ten() == S_thamso) {
			if (!Suni_tim)
				Suni_tim = danhsach.front();
			else
				return nullptr;
		}

		for (auto Suni_capduoi : danhsach.front() -> Suni_luutru)
			danhsach.push(Suni_capduoi);

		danhsach.pop();
	}

	return Suni_tim;
}

// Метод получения указателя на любой объект
// в составе дерева иерархии объектов согласно пути
Suni* Suni::Timf_object_by_coord(string S_diachi) {
	string S_ten;
	int slash_index;
	Suni* Suni_doituong = nullptr;

	if (S_diachi.empty())
		return nullptr;

	if (S_diachi == "/") {
		Suni* quet = this;

		while (quet -> Doi_tuong_boss())
			quet = quet -> Doi_tuong_boss();

		return quet;
	}

	if (S_diachi == ".")
		return this;

	if (S_diachi[0] == '/' && S_diachi[1] == '/') {
		S_ten = S_diachi.substr(2);
		return this -> Timf_object_from_root(S_ten);
	}

	if (S_diachi[0] == '.') {
		S_ten = S_diachi.substr(1);
		return this -> Timf_object_from_current(S_ten);
	}

	slash_index = S_diachi.find("/", 1);

	if (S_diachi[0] == '/') {
		if (slash_index != -1) {
			S_ten = S_diachi.substr(1, slash_index - 1);
			Suni_doituong = this -> Timf_object_from_root(S_ten);

			if (Suni_doituong)
				return Suni_doituong -> Timf_object_by_coord(S_diachi.substr(slash_index + 1));
			else
				return Suni_doituong;
		} else {
			S_ten = S_diachi.substr(1);
			return this -> Timf_object_from_root(S_ten);
		}
	} else {
		if (slash_index != -1) {
			S_ten = S_diachi.substr(0, slash_index);
			Suni_doituong = this -> Doi_tuong_duoi(S_ten);

			if (Suni_doituong)
				return Suni_doituong -> Timf_object_by_coord(S_diachi.substr(slash_index + 1));
			else
				return Suni_doituong;
		} else {
			S_ten = S_diachi;
			return this -> Doi_tuong_duoi(S_ten);
		}
	}
}

// Метод поиска подчинённого объекта корневого объекта по имени
Suni* Suni::Timf_object_from_root(string S_thamso) {
	Suni* quet = this;

	while (quet -> Doi_tuong_boss())
		quet = quet -> Doi_tuong_boss();

	return quet -> Doi_tuong_duoi(S_thamso);
}

// Метод удаления объекта по имени
void Suni::xoa(string S_thamso) {
	Suni* current = Doi_tuong_duoi(S_thamso);

	if (current) {
		for (int i = 0; i < Suni_luutru.size(); i++) {
			if (Suni_luutru[i] == current) {
				Suni_luutru.erase(Suni_luutru.begin() + i);
				delete current;
				break;
			}
		}
	}
}

// Метод переопределения головного объекта для текущего в дереве иерархии
bool Suni::dichuyen(Suni* newHead) {
	if (this -> Doi_tuong_boss() == newHead) {
		return true;
	}

	if (!(Doi_tuong_boss())) {
		return false;
	}

	Suni* quet = newHead;

	while (quet -> Doi_tuong_boss()) {
		if (quet == this)
			return false;

		quet = quet -> Doi_tuong_boss();
	}

	vector <Suni*>& v_thamchieu = Suni_main -> Suni_luutru;

	for (int i = 0; i < v_thamchieu.size(); ++i) {
		if (v_thamchieu[i] == this) {
			v_thamchieu.erase(v_thamchieu.begin() + i);

			Suni_main = newHead;
			newHead -> Suni_luutru.push_back(this);

			return true;
		}
	}

	return false;
}

// Метод установки готовности объекта
void Suni::Gan_trangthai(int thamso_trangthai) {
	if (thamso_trangthai) {
		Suni* quet = Suni_main;

		while (quet) {
			if (!(quet -> trangthai))
				return;

			quet = quet -> Doi_tuong_boss();
		}

		trangthai = thamso_trangthai;
	} else {
		for (auto Suni_capduoi : Suni_luutru)
			Suni_capduoi -> Gan_trangthai(thamso_trangthai);

		trangthai = thamso_trangthai;
	}
}

// Mетод вывода класса базового и его пользователского класса c их готовностью
void Suni::pearnet1() {
	if (Doi_tuong_boss())
		cout << endl;

	int tabulia = 0;
	Suni* current = this;

	while (current -> Doi_tuong_boss()) {
		current = current -> Doi_tuong_boss();
		tabulia++;
	}

	for (int i = 0; i < tabulia; i++)
		cout << "    ";

	cout << S_lay_ten();

	if (trangthai) {
		cout << " is ready";
	} else {
		cout << " is not ready";
	}

	for (auto Suni_capduoi : Suni_luutru)
		Suni_capduoi -> pearnet1();
}

// Метод определения абсолютной пути до текущего объекта
string Suni::Toa_do() {
	Suni* quet = this;
	string S_ten = "/" + quet -> S_chuooix;

	while (quet -> Suni_main)
		quet = quet -> Suni_main;

	if (quet == this) {
		S_ten = "/";
	} else {
		quet = this;

		while (quet -> Suni_main -> Suni_main) {
			quet = quet -> Suni_main;
			S_ten = "/" + quet -> S_chuooix + S_ten;
		}
	}

	return S_ten;
}

// Метод установки связи
void Suni::caidat_ketnoi(TYPE_SIGNAL     ptr_tin_hieu,
							Suni*        ptr_Suni,
							TYPE_HANDLER ptr_nhan_th) {
	ketnoi* thucthi_ketnoi;

	// Цикл для исключения повторного установления связи
	for (int i = 0; i < Suni_ddeens.size(); i++) {
		if (Suni_ddeens[i] -> ptr_tin_hieu == ptr_tin_hieu &&
			Suni_ddeens[i] -> ptr_Suni == ptr_Suni &&
			Suni_ddeens[i] -> ptr_nhan_th == ptr_nhan_th) {

			return;
		}
	}

	// Cоздание объекта структуры для хранения информации о новой связи
	thucthi_ketnoi = new ketnoi();

	thucthi_ketnoi -> ptr_tin_hieu = ptr_tin_hieu;
	thucthi_ketnoi -> ptr_Suni = ptr_Suni;
	thucthi_ketnoi -> ptr_nhan_th = ptr_nhan_th;

	Suni_ddeens.push_back(thucthi_ketnoi);  // Добавление новой связи
}

// Метод удаления связи
void Suni::xoa_ketnoi(TYPE_SIGNAL    ptr_tin_hieu,
						Suni*        ptr_Suni,
						TYPE_HANDLER ptr_nhan_th) {
	auto itr = Suni_ddeens.begin();

	while (itr != Suni_ddeens.end()) {
		if ((*itr) -> ptr_tin_hieu == ptr_tin_hieu &&
			(*itr) -> ptr_Suni == ptr_Suni &&
			(*itr) -> ptr_nhan_th == ptr_nhan_th) {

			delete (*itr);
			itr = Suni_ddeens.erase(itr);
		} else {
			++itr;
		}
	}
}

// Метод выдачи сигнала
void Suni::phat_tin_hieu(TYPE_SIGNAL ptr_tin_hieu,
							string   tin_nhan,
							Suni*    S_ptr) {
	TYPE_HANDLER ptr_nhan_th;
	Suni*        ptr_Suni;

	if (!(this -> trangthai))
		return;

	(this ->* ptr_tin_hieu)(tin_nhan);  // вызов метода сигнала

	for (int i = 0; i < Suni_ddeens.size(); i++) {          // цикл по всем обработчикам
		if (Suni_ddeens[i] -> ptr_tin_hieu == ptr_tin_hieu  // определение допустимого обработчика
			&& Suni_ddeens[i] -> ptr_Suni -> trangthai
			&& Suni_ddeens[i] -> ptr_Suni == S_ptr) {

			ptr_nhan_th = Suni_ddeens[i] -> ptr_nhan_th;
			ptr_Suni = Suni_ddeens[i] -> ptr_Suni;

			(ptr_Suni ->* ptr_nhan_th)(tin_nhan);  // вызов метода обработчика
		}
	}
}

// Метод возврата номера класса
int Suni::Lay_solop() {
	return 1;
}

// Метод приведения всех объектов в состоянии готовности
void Suni::Active() {
	Gan_trangthai(1);

	for (int i = 0; i < Suni_luutru.size(); i++) {
		Suni_luutru[i] -> Active();
	}
}

// Деструктор класса Suni
Suni::~Suni() {
	for (int a = 0; a < Suni_luutru.size(); a++)
		delete Suni_luutru[a];
}
