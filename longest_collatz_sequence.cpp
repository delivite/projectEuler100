/*
 * largest_collatz_sequence.cpp
 *
 *  Created on: 22 Jan 2020
 *      Author: Troy
 *
 *
 *
 * The following iterative sequence is defined for the set of positive integers:
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <chrono>

long collatz(long long term) {
	int count { 1 };

	while (term != 1) {
		if (term == 1) {
			return 1;
		}

		if (term % 2 == 0) {

			term = term / 2;

		} else if (term % 2 != 0) {

			term = 3 * term + 1;

		}

		count++;
	}
	return count;
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();



	int temp { };
	int count { 0 };
	for (int i = 100001; i < 1000000; i += 2) {

		temp = collatz(i);

		if (temp >= count) {
			count = temp;
			std::cout << i << ' ' << count << std::endl;
		}
	}



	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end - start;

	std::cout << "Time taken: " << diff.count() << " seconds." << std::endl;
	return 0;
}

