/*
 * largest_prime_factor.cpp
 *
 *  Created on: 4 Jan 2020
 *      Author: Troy
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

int largest_prime(long long number) {

	//Container to hold prime numbers
	std::vector<int> prime;

	while (number % 2 == 0) {
		prime.push_back(2);
		number = number / 2;
	}

	for (int i = 3; i <= sqrt(number); i += 2) {
		while (number % i == 0) {
			prime.push_back(i);
			number = number / i;
		}
	}

	if (number > 2)
		prime.push_back(number);

	//Get a pointer to the largest element in the container
	auto max = std::max_element(prime.begin(), prime.end());

	//Return a de-referenced element
	return *max;

}

int main() {

	std::cout << "Largest Prime number for 600851475143 is "
			<< largest_prime(600851475143) << std::endl;

}
