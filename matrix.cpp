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
	rvetv(this, 0, cur);
}

void matrix::rvetv(matrix* t, int a, std::valarray<int> b)
{
	if (a < t->columns)
	{
		std::thread thr1(rvetv, t, a + 1, b);
		b[a] = 1;
		std::thread thr2(lvetv, t, a + 1, b);
		thr1.join();
		thr2.join();
	}
}

void matrix::lvetv(matrix* t, int a, std::valarray<int> b)
{
	std::valarray<int> tr(t->columns);
	bool check = true;
	for (auto i : t->matr)
	{
		tr = i*b;
		if (tr.sum() < 1)
			check = false;
	}

	if (check)
	{
		tr = b*t->ogr;
		if (tr.sum() < t->opt)
		{
			t->optv = b;
			t->opt = tr.sum();
		}
	}
	else if (a < t->columns)
	{
		std::thread thr1(rvetv, t, a + 1, b);
		b[a] = 1;
		std::thread thr2(lvetv, t, a + 1, b);
		thr1.join();
		thr2.join();
	}
}

void matrix::output(std::ofstream& a)
{
	for (auto i : optv)
		a << i << ' ';
	a << std::endl << opt;
}