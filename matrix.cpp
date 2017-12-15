#include "header.h"
#include "matrix.h"


matrix::matrix()
{
}

matrix::matrix(int a, int b) : matr(std::valarray<int>(b), a), optv(b), ogr(b), oname(b)
{
	lines = a;
	columns = b;
	opt = -1;
}

matrix::~matrix()
{
}

void matrix::input(std::ifstream& a)
{
	
	std::valarray<std::valarray<int>> mat(std::valarray<int>(lines), columns);
	
	//std::getline(a, s1);
	//if (!s1.empty())
		//throw std::logic_error("bad input!");
	for (int i = 0; i < columns; i++)
	{
		std::stringstream s;
		std::string s1;
		std::getline(a, s1);
		//s.getline(a);
		s << s1;
		for (int j = 0; j < lines; j++)
		{
			if (s.eof())
				throw std::logic_error("bad input!");
			s >> mat[i][j];
			if ((mat[i][j] > 1) || (mat[i][j] < 0))
				throw std::logic_error("incorrect value!");
		}
		s >> ogr[i];
		if (ogr[i] < 0)
			throw std::logic_error("incorrect value!");
		s >> oname[i];
		if (!s.eof())
			throw std::logic_error("bad input!");
	}
	for (int i = columns; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (ogr[j] > ogr[j + 1])
			{
				std::swap(ogr[j], ogr[j + 1]);
				std::swap(oname[j], oname[j + 1]);
				std::swap(mat[j], mat[j + 1]);
			}
		}
	}//sort
	//int b;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			matr[j][i] = mat[i][j];
		}
		a >> ogr[i];
	}
}

void matrix::deistv()
{
	std::valarray<int> cur(columns);
	for (auto& i : cur)
	{
		i = 0;
	}
	for (auto&i : matr)
	{
		if (i.sum() < 1)
			throw std::logic_error("no solution!");//3.1 yslovie
	}
	rvetv(0, cur, columns);
}

void matrix::rvetv(int a, std::valarray<int> b, int gr)
{
	if (a < gr)
	{
		
		b[a] = 1;
		lvetv(a + 1, b, gr);
		b[a] = 0;
		rvetv(a + 1, b, gr);
		//thr1.join();
		//thr2.join();
	}
}

void matrix::lvetv(int a, std::valarray<int> b, int gr)
{
	std::valarray<int> tr(columns);
	bool check = false;

	for (auto& i : matr)
	{
		if (i[a-1]>0)
			check = true;
	}
	if (check != true)
		return;

	check = true;
	for (auto& i : matr)
	{
		tr = i*b;
		if (tr.sum() < 1)
			check = false;
	}

	if (check)
	{
		tr = b*ogr;
		if (opt == -1)
		{
			optv = b;
			opt = tr.sum();
		}
		else if (tr.sum() < opt)
		{
			optv = b;
			opt = tr.sum();
		}
	}//1 yslovie
	else if (a < gr)
	{
		int k = (b*ogr).sum();
		{
			tr = b;
			for (int i = a; i < columns; i++)
			{
				tr[i] = 1;
			}
			for (auto& i : matr)
			{
				if ((tr*i).sum() < 1)
					gr = a;
			}
		}//3.2 yslovie
		{
			if (opt != -1)
				for (int i = a; i < gr; i++)
				{
					//k = k + ogr[i];
					if (k + ogr[i] > opt)
					{
						gr = i;
						break;
					}
				}
		}//2 yslovie
		
		b[a] = 1;
		lvetv(a + 1, b, gr);
		b[a] = 0;
		rvetv(a + 1, b, gr);
		//thr1.join();
		//thr2.join();
	}
}

void matrix::output(std::ofstream& a)
{
	for (int i = 0; i < optv.size(); i++)
		if (optv[i] == 1)
			a << oname[i] << ' ';
	a << std::endl << opt;
}