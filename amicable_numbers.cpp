/*
 * amicable_numbers.cpp
 *
 *  Created on: 19 Feb 2020
 *      Author: Troy
 *
 * PROBLEM:
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <vector>

int div_sum(const int &number) {
	int sum { 0 };

	for (int i = 1; i <= number / 2; i++) {
		if (number % i == 0) {
			sum += i;
		}
	}

	return sum;
}

bool is_amicable(const int &a, const int &b) {

	return (div_sum(a) == b && div_sum(b) == a && a != b) ? true : false;
}

int main() {
	int amicable_sum { };
	for (int num = 0; num < 10000; num++) {
		if (is_amicable(num, div_sum(num))) {
			amicable_sum += num;
		}
	}

	std::cout << amicable_sum;

	return 0;
}

