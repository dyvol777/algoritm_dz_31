#pragma once

#include "stdafx.h"

class matrix
{
private:
	int lines;
	int columns;
	std::valarray<std::valarray<int>> matr;
	std::valarray<int> ogr;
	std::valarray<int> optv;
	int opt;
public:
	matrix();
	matrix(int,int);
	~matrix();
	void input(std::ifstream&);
	void deistv();
	void lvetv(int, std::valarray<int>);
	void rvetv(int, std::valarray<int>);
	void output(std::ofstream&);
};