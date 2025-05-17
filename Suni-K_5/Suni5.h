#ifndef __SUNI5__H
#define __SUNI5__H

#include "Suni.h"

class Suni5 :public Suni {
public:
	Suni5(string name, Suni* pt) :Suni(name, pt) { number = 5; };
	void signal(string&);
	void handler(string);
};
#endif
