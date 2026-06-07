#ifndef __SUNI__H
#define __SUNI__H

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Suni;

#define SIGNAL_D(chuyen_tin_hieu)  (TYPE_SIGNAL)(&chuyen_tin_hieu)
#define HANDLER_D(nhan_tin_hieu)  (TYPE_HANDLER)(&nhan_tin_hieu)

typedef void (Suni :: *TYPE_SIGNAL)(string&);
typedef void (Suni :: *TYPE_HANDLER)(string);

struct ketnoi {                 // Структура задания одной связи
	TYPE_SIGNAL  ptr_tin_hieu;  // Указатель на метод сигнала
	Suni*        ptr_Suni;      // Указатель на целевой объект
	TYPE_HANDLER ptr_nhan_th;   // Указатель на метод обработчика
};

class Suni {
	protected:
		string S_chuooix;
		Suni* Suni_main;

		vector <Suni*> Suni_luutru;
		vector <ketnoi*> Suni_ddeens;

		vector <string> Ncoffee;
		vector <int> Pcoffee;

		int trangthai = 0;
		int sum = 0;
		int c5, c10;

		static Suni* Virt_obj;
	public:
		Suni();
		Suni(Suni* Suni_main, string S_chuooix = "System");

		bool GanGiaTri(string S_thamsomoi);
		void Gan_trangthai(int thamso_trangthai);

		Suni* Doi_tuong_duoi(string S_thamsomoi2);
		Suni* Doi_tuong_boss();

		void pearnet();
		void pearnet1();

		Suni* Timf_object_from_current(string S_thamso);
		Suni* Timf_object_from_root(string S_thamso);
		Suni* Timf_object_by_coord(string S_diachi);

		bool dichuyen(Suni* newHead);
		void xoa(string S_thamso);

		string S_lay_ten();
		string Toa_do();

		void caidat_ketnoi(TYPE_SIGNAL   ptr_tin_hieu,
							Suni*        ptr_Suni,
							TYPE_HANDLER ptr_nhan_th);

		void xoa_ketnoi(TYPE_SIGNAL  ptr_tin_hieu,
						Suni*        ptr_Suni,
						TYPE_HANDLER ptr_nhan_th);

		void phat_tin_hieu(TYPE_SIGNAL ptr_tin_hieu,
							string     tin_nhan,
							Suni*      S_ptr);

		virtual int Lay_solop();
		void Active();

		friend class Suni2;
		friend class Suni3;
		friend class Suni4;

		~Suni();
};

#endif
