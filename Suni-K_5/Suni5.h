#ifndef __SUNI5__H
#define __SUNI5__H

#include "Suni.h"

class Suni5: public Suni {
	public:
		Suni5(Suni* Suni_main, string S_chuooix);
		int Lay_solop() override;

		void chuyen_tin_hieu(string& tin_nhan);
		void nhan_tin_hieu(string tin_nhan);

		~Suni5();
};

#endif
