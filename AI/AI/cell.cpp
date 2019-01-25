#include "cell.h"
#include<iostream>


cell::cell(int a=0, int b=0 ) {
	this->a = a;
	this->b = b;
}

std::ostream& operator << (std::ostream &out, const cell &p) {
	out << "(" << p.a << " " << p.b << ")";
	return out;
}

bool cell::operator < (const cell &p) const {
	return this->a < p.a;
}

bool cell::operator == (const cell &p) const {
	return this->a == p.a && this->b == p.b;
}

bool cell::operator != (const cell &p) const {
	return this->a != p.a || this->b != p.b;
}
