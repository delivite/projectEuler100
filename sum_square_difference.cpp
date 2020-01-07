/*
 * sum_square_difference.cpp
 *
 *  Created on: 6 Jan 2020
 *      Author: Samuel 'Troy' Chinedu
 */

/* PROBLEM #6
 * The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

long sum_square(int n) {
	long sum { 0 };

	/*	My initial naive solution. Linear time complexity ie O(n)
	 * for (int i = 1; i <= n; i++) {
	 sum += i * i;
	 }*/

	//My final researched solution...Constant time complexity ie O(1)
	sum = ((2 * n + 1) * (n + 1) * n) / 6;
	return sum;
}

long square_sum(int n) {
	long sum { 0 };

	/*	My initial naive solution. Linear time complexity ie O(n)
	 * for (int i = 1; i <= n; i++) {
	 * sum += i;
	 * }
	 */

	//My final researched solution...Constant time complexity ie O(1)
	sum = n * (n + 1) / 2;
	return sum * sum;
}

int main() {
	std::cout << square_sum(100) - sum_square(100);
	return 0;
}

