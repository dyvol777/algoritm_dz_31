// algdz31.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "matrix.h"

int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	
	try
	{
		int a, b;
		fin >> a >> b;
		matrix mat(a, b);
		mat.input(fin);
		mat.deistv();
		mat.output(fout);
	}
	catch (...)
	{
		fout << "WTF?" << std::endl;
	}
	fin.close();
	fout.close();
    return 0;
}

