#include <iostream>
#include"fromFile.h"

int main()
{
    
	ReadFile file;
	file.Display("test.txt");
	std::cout << file.data();
	std::cout << "\n\n\n";

	ReadFileASCII fileASCII;
	fileASCII.Display("test.txt");
	std::cout << fileASCII.data();
	std::cout << "\n\n\n";

	ReadFileBinary fileBin;
	fileBin.Display("test.txt");
	std::cout << fileBin.data();
	std::cout << "\n\n\n";

	/*std::bitset<64> boo = 4;
	std::string asd = boo.to_string();
	std::cout << asd << std::endl;*/

}

