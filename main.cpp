#include <fstream>
#include <sstream>
#include <iostream>
#include "zip.h"

using namespace std;

int main() {
	ofstream ofs("out.zip", ios_base::binary);
	zip z(ofs, 128);
	{
		stringbuf str("caaaaaaaaaaaaaaaaaaabbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac");
		istream istream(&str);
		z.add("a.txt", istream);
	}
	z.write();
	ofs.close();
}