#include "user_interface.h"
#include <iostream>

void printField(Field field) {
	std::cout << '+';
	for (int iLength{ 0 }; iLength < field.length; ++iLength) {
		std::cout << "--";
	}
	std::cout << '+';
	for (int iLength{ 0 }; iLength < field.width; ++iLength) {
		std::cout << "\n|";
		for (int iWidth{ 0 }; iWidth < field.length; ++iWidth) {
			if ((iLength == field.applePos.first) && (iWidth == field.applePos.second)) {
				std::cout << char(0xFE) << char(0xFE);
			}
			else {
				std::cout << char(0x20) << char(0x20);
			}
		}
		std::cout << '|';
	}
	std::cout << "\n+";
	for (int iLength{ 0 }; iLength < field.length; ++iLength) {
		std::cout << "--";
	}
	std::cout << "+\n";
}