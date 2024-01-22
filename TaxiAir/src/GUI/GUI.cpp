#include"GUI.h"

std::string  GUI:: getFile()
{
	std::string filename;
	std::cout << "Enter File: ";
	std::cin >> filename;
	return filename;
}