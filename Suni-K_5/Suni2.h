#ifndef __SUNI2__H
#define __SUNI2__H

#include "Suni.h"

class Suni2 :public Suni {
public:
	Suni2(string name, Suni* pt) :Suni(name, pt) { number = 2; };
	void signal(string&);
	void handler(string);
	void signal_go(string&);
};
#endif
