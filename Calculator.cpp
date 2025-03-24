#ifndef _Calculator_H_
#define _Calculator_H_

#include <iostream>
#include <math.h>
#include "Calculator.h"


int Calculator::factorielle(int a) {
	int fact = 1;
	int i = 0;
	while (i <= a) {
		fact *= i;
		i++;
	}
	return fact;
}

int Calculator::add(int a, int b) {
	return a + b;
}

int Calculator::sub(int a, int b) {
	return a - b;
}

double Calculator::div(double a, double b) {
	if (b == 0) throw std::invalid_argument("Division by zero");
	// if (b == 0) {
	// 	std::cerr << "Error: Division by 0 not possible" << std::endl;
	// 	exit(255);
	// }
	return a / b;
}

#endif
