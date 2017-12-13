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
		std::getline(fin,y);
		if (!y.empty())
			throw std::logic_error("wrong input!");
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
    return 0;
}

