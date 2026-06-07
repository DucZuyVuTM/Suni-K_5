#ifndef __SUNI2__H
#define __SUNI2__H

#include "Suni.h"

class Suni2: public Suni {
	public:
		Suni2(Suni* Suni_main, string S_chuooix);
		int Lay_solop() override;

		void chuyen_tin_hieu(string& tin_nhan);
		void chuyen_tin_hieu1(string& tin_nhan);
		void nhan_tin_hieu(string tin_nhan);

		~Suni2();
};

#endif
