#ifndef __SUNI7__H
#define __SUNI7__H

#include "Suni.h"

class Suni7 : public Suni {
	public:
		Suni7(Suni* Suni_main, string S_chuooix);
		int Lay_solop() override;

		void chuyen_tin_hieu(string&);
		void nhan_tin_hieu(string);

		~Suni7();
};

#endif
