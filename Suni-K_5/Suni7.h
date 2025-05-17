#ifndef __SUNI7__H
#define __SUNI7__H

#include "Suni.h"

class Suni7 : public Suni {
public:
	Suni7(string name, Suni* pt);
	void signal(string&);
	void handler(string);
};
#endif
