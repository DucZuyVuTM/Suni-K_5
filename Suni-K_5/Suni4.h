#ifndef __SUNI4__H
#define __SUNI4__H

#include "Suni.h"

class Suni4: public Suni {
	public:
		Suni4(Suni* Suni_main, string S_chuooix);
		int Lay_solop() override;

		void chuyen_tin_hieu(string& tin_nhan);
		void nhan_tin_hieu(string tin_nhan);

		~Suni4();
};

#endif
