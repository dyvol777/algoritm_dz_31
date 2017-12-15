// algdz31.cpp: определяет точку входа для консольного приложения.
//

#include "header.h"
#include "matrix.h"

int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");

	try
	{
		if (!fin.is_open())
			throw std::logic_error("no file!");
		int a, b;
		bool che = fin.eof();
		if (!(fin >> a >> b))
			throw std::logic_error("empty file!");
		std::string y;
		std::getline(fin, y);
		if (!y.empty())
			throw std::logic_error("wrong input!");

		std::valarray<std::valarray<std::string>> m(std::valarray<std::string>(a+2), b);
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a + 2; j++)
			{
				if (fin.eof())
					throw std::logic_error("bad input!");
				fin >> m[i][j];
			}
		}
		if (!fin.eof())
			throw std::logic_error("bad input!");

		matrix mat(a, b);
		mat.input(m);
		mat.deistv();
		auto p = mat.output();

		
		for (auto i : p.second)
		{
			fout << i << ' ';
		}
		fout << std::endl << p.first;
	}
	catch (std::exception e)
	{
		fout << "something going wrong! - " << e.what() << std::endl;
	}
	fin.close();
	fout.close();
	return 0;
}