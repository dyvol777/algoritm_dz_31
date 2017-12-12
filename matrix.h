#pragma once

#include "header.h"

class matrix
{
private:
	int lines;
	int columns;
	std::valarray<std::valarray<int>> matr;
	std::valarray<int> ogr;
	std::valarray<int> optv;
	std::valarray<std::string> oname;
	int opt;
public:
	matrix();
	matrix(int,int);
	~matrix();
	void input(std::ifstream&);
	void deistv();
	void lvetv(int, std::valarray<int>, int);
	void rvetv(int, std::valarray<int>, int);
	void output(std::ofstream&);
};