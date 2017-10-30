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
	static void lvetv(matrix*, int, std::valarray<int>);
	static void rvetv(matrix*, int, std::valarray<int>);
	void output(std::ofstream&);
};