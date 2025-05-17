#ifndef __SUNI_APP__H
#define __SUNI_APP__H

#include "Suni.h"

class Suni_app : public Suni {
public:
	Suni_app();
	Suni_app(string name, Suni* pt);
	void Taoj_cay_phan_cap();
	void pearnet_tong();
	void signal(string& now);
	void handler(string now);
};
#endif
