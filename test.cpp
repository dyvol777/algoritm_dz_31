// test.cpp: определяет точку входа для консольного приложения.
//

#include "header.h"
#include "matrix.h"

int main()
{
	std::ifstream w("test.txt");
	std::string in;
	std::string out;

	while (w >> in >> out)
	{
		in = "tests/" + in;
		out = "tests/" + out;
		std::ifstream fin(in);
		std::ofstream fout(out);

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

			std::valarray<std::valarray<std::string>> m(std::valarray<std::string>(a + 2), b);
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

			fout << p.first << std::endl;
			for (auto i : p.second)
			{
				fout << i << ' ';
			}
		}
		catch (std::exception e)
		{
			fout << "something going wrong! - " << e.what() << std::endl;
		}
		fin.close();
		fout.close();
	}
	w.close();
	return 0;
}

