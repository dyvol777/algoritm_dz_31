#include "stdafx.h"
#include "matrix.h"


matrix::matrix()
{
}

matrix::matrix(int a, int b)
{
	lines = a;
	columns = b;
	std::valarray<std::valarray<int>> mat(std::valarray<int>(b), a);
	matr = std::move(mat);
	std::valarray<int> q(b);
	optv = q;
	ogr = std::move(q);
	opt = 99999;
}

matrix::~matrix()
{
}

void matrix::input(std::ifstream& a)
{
	//int b;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			a >> matr[j][i];
		}
		a >> ogr[i];
	}
}

void matrix::deistv()
{
	std::valarray<int> cur(columns);
	for (auto& i : cur)
		i = 0;
	rvetv(0, cur);
}

void matrix::rvetv(int a, std::valarray<int> b)
{
	if (a < columns)
	{
		rvetv(a + 1, b);
		b[a] = 1;
		lvetv(a + 1, b);
		//thr1.join();
		//thr2.join();
	}
}

void matrix::lvetv(int a, std::valarray<int> b)
{
	std::valarray<int> tr(columns);
	bool check = true;
	for (auto& i : matr)
	{
		tr = i*b;
		if (tr.sum() < 1)
			check = false;
	}

	if (check)
	{
		tr = b*ogr;
		if (tr.sum() < opt)
		{
			optv = b;
			opt = tr.sum();
		}
	}
	else if (a < columns)
	{
		rvetv(a + 1, b);
		b[a] = 1;
		lvetv(a + 1, b);
		//thr1.join();
		//thr2.join();
	}
}

void matrix::output(std::ofstream& a)
{
	for (auto i : optv)
		a << i << ' ';
	a << std::endl << opt;
}