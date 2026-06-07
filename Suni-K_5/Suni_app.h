#ifndef __SUNI_APP__H
#define __SUNI_APP__H

#include "Suni.h"

class Suni_app: public Suni {
	public:
		Suni_app(Suni* Suni_main);
		void Taoj_cay_phan_cap();
		int pearnet_tong();
		~Suni_app();
};

#endif
