#ifndef __SUNI6__H
#define __SUNI6__H

#include "Suni.h"

class Suni6 :public Suni {
public:
	Suni6(string name, Suni* pt) : Suni(name, pt) { number = 6; };
	void signal(string&);
	void handler(string);
};
#endif
