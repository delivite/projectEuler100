/*

 * summation_of_primes.cpp
 *
 *  Created on: 10 Jan 2020
 *      Author: Troy
 *
 *
 *  PROBLEM #10
 *  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *	Find the sum of all the primes below two million.
 **/

#include <iostream>
#include <cstdlib>
#include <exception>

bool is_prime(const int &x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

long long prime_sum(const int &number) {
	if (number < 2) {
		throw std::invalid_argument(
				"Error: Enter a positive integer greater than 1");
	}

	long long sum { 5 };

	for (long i = 5; i <= number; i += 2) {
		if (is_prime(i)) {
			sum += i;
		}
	}
	return sum;
}

int main() {

	try {
		std::cout << prime_sum(2000000);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}

