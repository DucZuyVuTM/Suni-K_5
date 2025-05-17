#ifndef __SUNI_H
#define __SUNI_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Suni;

typedef void(Suni::* TYPE_SIGNAL)(std::string&);
typedef void(Suni::* TYPE_HANDEL)(std::string);

class Suni {
protected:
	int status = 0;
	string name;
	Suni* pt;
	vector<Suni*> ukas;
	static Suni* Virt_obj;
	static Suni* jetzt;
	struct sv {
		TYPE_SIGNAL sig;
		Suni* p;
		TYPE_HANDEL hen;
	};
	vector<sv*> connects;
	int number;
	int summ = 0, fi, te;
	vector <string>ncoffe;
	vector <int>pcoffe;
public:
	void SetName(string name);
	string GetName();
	Suni(string name, Suni* pt);
	Suni();
	void print(int n);
	void print_status(int n);
	Suni* Get_hd();
	void Set_hd(Suni* ptr);
	Suni* GetVater(string name);
	void Set_status(int p);
	Suni* finde(string adres);
	bool set(string adres);
	string Get_adres();
	int GetNumber();
	void Set_status_all(int a);
	void set_sv(TYPE_SIGNAL sig, Suni* p, TYPE_HANDEL hen);
	void del_sv(TYPE_SIGNAL sig, Suni* p, TYPE_HANDEL hen);
	void get_sv(TYPE_SIGNAL sig, string stroka, Suni* p);
	bool GetStatus();
	friend class Suni2;
	friend class Suni3;
	friend class Suni4;
};

#endif
