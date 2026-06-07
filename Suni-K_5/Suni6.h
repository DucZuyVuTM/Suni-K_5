#ifndef __SUNI6__H
#define __SUNI6__H

#include "Suni.h"

class Suni6: public Suni {
	public:
		Suni6(Suni* Suni_main, string S_chuooix);
		int Lay_solop() override;

		void chuyen_tin_hieu(string& tin_nhan);
		void nhan_tin_hieu(string tin_nhan);

		~Suni6();
};

#endif
