#pragma once
#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>

struct cell {
	int a; // row
	int b; // col

	cell() {};
	cell(int a, int b);

	bool operator < (const cell &p) const;

	bool operator == (const cell &p) const;

	bool operator != (const cell &p) const;
};

std::ostream& operator << (std::ostream &out, const cell &p);

#endif