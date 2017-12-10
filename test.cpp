// test.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
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
				throw std::exception("no file!");
			int a, b;
			bool che = fin.eof();
			if (!(fin >> a >> b))
				throw std::exception("empty file!");
			std::string y;
			std::getline(fin, y);
			if (!y.empty())
				throw std::exception("wrong input!");
			matrix mat(a, b);
			mat.input(fin);
			mat.deistv();
			mat.output(fout);
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
