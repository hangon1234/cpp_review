#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>

 class Printer
 {
	private:
		char string[30];
	public:
		void SetString(const char * input);
		void ShowString();
 };

#endif