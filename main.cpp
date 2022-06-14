#include <fstream>
#include <sstream>
#include <iostream>
#include "zip.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc <= 2)
		return 0;
	ofstream ofs(argv[argc - 1], ios_base::binary);
	zip z(ofs, 128);

	for (int i = 1; i < argc - 1; i++)
	{
		ifstream istream(argv[i], ios_base::binary);
		z.add(argv[i], istream);
		istream.close();
	}
	z.write();
	ofs.close();
}