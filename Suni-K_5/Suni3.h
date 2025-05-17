#ifndef __SUNI3__H
#define __SUNI3__H

#include "Suni.h"

class Suni3 : public Suni {
public:
	Suni3(string name, Suni* pt) :Suni(name, pt) { number = 3; };
	void signal(string&);
	void handler(string);
};
#endif
