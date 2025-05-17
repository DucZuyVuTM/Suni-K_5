#ifndef __SUNI4__H
#define __SUNI4__H

#include "Suni.h"

class Suni4 :public Suni {
public:
	Suni4(string name, Suni* pt) :Suni(name, pt) { number = 4; };
	void signal(string&);
	void handler(string);
};
#endif
