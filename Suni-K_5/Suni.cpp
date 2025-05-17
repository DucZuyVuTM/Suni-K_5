#include "Suni.h"

Suni::Suni(string name, Suni* pt) {
	this->name = name;
	if (pt != nullptr) {
		this->pt = pt;
		pt->ukas.push_back(this);
	}
	else {
		this->pt = Virt_obj;
		Virt_obj->ukas.push_back(this);
	}
	number = 1;
}
string Suni::GetName() {
	return name;
}
void Suni::SetName(string name) {
	this->name = name;
}
void Suni::print(int n) {
	string tab(n, ' ');
	cout << endl << tab << GetName();
	for (int i = 0; i < ukas.size(); i++) {
		ukas[i]->print(n + 4);
	}
}
void Suni::print_status(int n) {
	string tab(n, ' ');
	cout << endl << tab << GetName();
	if (status == 0)
		cout << " is not ready";
	else
		cout << " is ready";
	for (int i = 0; i < ukas.size(); i++) {
		ukas[i]->print_status(n + 4);
	}
}
Suni::Suni() {
	pt = nullptr;
}

Suni* Suni::GetVater(string name) {
	for (int i = 0; i < ukas.size(); i++) {
		if (ukas[i]->GetName() == name) {
			return ukas[i];
		}
	}
	for (int i = 0; i < ukas.size(); i++) {
		if (ukas[i]->GetVater(name)->GetName() == name) {
			return ukas[i]->GetVater(name);
		}
	}
	return this;
}
Suni* Suni::Get_hd() {
	return pt;
}
void Suni::Set_hd(Suni* ptr) {
	if (pt != nullptr) {
		auto help = pt->ukas;
		auto help1 = find(help.begin(), help.end(), this);
		help.erase(help1);
		pt->ukas = help;
	}
	pt = ptr;
	if (pt != nullptr) {
		pt->ukas.push_back(this);
	}
}
Suni* Suni::Virt_obj = new Suni();
void Suni::Set_status(int p) {
	if (p == 0) {
		this->status = 0;
		for (int i = 0; i < ukas.size(); i++)
			ukas[i]->Set_status(0);
	}
	else {
		if (pt != nullptr) {
			if (pt->status != 0)
				this->status = p;
		}
		else
			this->status = p;
	}
}
Suni* Suni::jetzt = Virt_obj;
Suni* Suni::finde(string adres) {
	if (adres == "/")
		return Virt_obj;
	else if (adres == ".")
		return jetzt;
	else if (adres[0] + adres[1] == '//') {
		if (Virt_obj->GetVater(adres.substr(2))->GetName() == adres.substr(2))
			return Virt_obj->GetVater(adres.substr(2));
		else
			return nullptr;
	}
	else if (adres.find("/") == 0 and Virt_obj->GetVater(adres.substr(adres.rfind("/") + 1))->Get_adres() == adres) {
		if (Virt_obj->GetVater(adres.substr(adres.rfind("/") + 1))->GetName() == adres.substr(adres.rfind("/") + 1) \
			and Virt_obj->GetVater(adres.substr(adres.rfind("/") + 1))->pt != nullptr)
			return Virt_obj->GetVater(adres.substr(adres.rfind("/") + 1));
		else
			return nullptr;
	}
	else if (adres.find("/") != 0 and adres.find("/") != 1) {
		if (Virt_obj->GetVater(adres.substr(adres.rfind("/") + 1))->GetName() == adres.substr(adres.rfind("/") + 1))
			return jetzt->GetVater(adres.substr(adres.rfind("/") + 1));
		else
			return nullptr;
	}
	else
		return nullptr;
}
bool Suni::set(string adres) {
	if (finde(adres) == nullptr)
		return false;
	else {
		jetzt = finde(adres);
		return true;
	}
}
int Suni::GetNumber() {
	return number;
}
string Suni::Get_adres() {
	vector<string> mas;
	if (pt == nullptr)
		return"/";
	string adres = "";
	mas.push_back(this->name);
	Suni* help;
	help = this->pt;
	while (help != nullptr) {
		mas.push_back(help->name);
		help = help->pt;
	}
	for (int i = mas.size() - 2; i >= 0; i--) {
		adres += "/";
		adres += mas[i];
	}
	return adres;
}
void Suni::set_sv(TYPE_SIGNAL sig, Suni* p, TYPE_HANDEL hen) {
	for (int i = 0; i < connects.size(); i++) {
		if (connects[i]->sig == sig and connects[i]->p == p and connects[i]->hen == hen)
			return;
	}
	connects.push_back(new sv{ sig,p,hen });
}
void Suni::del_sv(TYPE_SIGNAL sig, Suni* p, TYPE_HANDEL hen) {
	for (int i = 0; i < connects.size(); i++) {
		if (connects[i]->sig == sig and connects[i]->p == p and connects[i]->hen == hen)
			connects.erase(connects.begin() + i);
	}
}

void Suni::get_sv(TYPE_SIGNAL sig, string stroka, Suni* p) {
	(this->*sig)(stroka);//Получение конкретного метода signal
	for (int i = 0; i < connects.size(); i++) {
		if ((connects[i]->sig == sig) and (connects[i]->p == p)) {
			TYPE_HANDEL hendl = connects[i]->hen;// Конкретный метод отдачи (класса)
			if (connects[i]->p->status != 0)
				(connects[i]->p->*hendl)(stroka);//Объект нужен для вывода адреса
		}
	}
}
void Suni::Set_status_all(int a) {
	Set_status(a);
	for (int i = 0; i < ukas.size(); i++) {
		ukas[i]->Set_status_all(a);
	};
}
bool Suni::GetStatus() {
	if (this->status != 0)
		return true;
	else
		return false;
}
