#ifndef __SUNI3__H
#define __SUNI3__H

#include "Suni.h"

class Suni3: public Suni {
	public:
		Suni3(Suni* Suni_main, string S_chuooix);
		int Lay_solop() override;

		void chuyen_tin_hieu(string& tin_nhan);
		void nhan_tin_hieu(string tin_nhan);

		~Suni3();
};

#endif
