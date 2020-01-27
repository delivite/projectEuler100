/*
 * power_digit_sum.cpp
 *
 *  Created on: 27 Jan 2020
 *      Author: Troy
 *
 *      PROBLEM:
 *      215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *      What is the sum of the digits of the number 21000?
 */

#include <iostream>
#include <vector>
#include <cmath>

/*long long int power_sum(long long int power) {
 int digit_sum { };
 while (power > 0) {
 int temp = (power % 10);
 digit_sum += temp;
 power = power / 10;
 }

 return digit_sum;
 }

 long long int power(int num, int exp){
 long long int product{1};
 for(int i = 0; i<exp; i++){
 product*=num;
 }
 return product;
 }*/

std::vector<int> products(int base, int power, int upper) {
	//Create a vector with upper number of elements.

	std::vector<int> cache(upper, 0);

	cache[0] = 1;
	for (int i = 0; i < power; i++) {
		cache[0] = base * cache[0];

		for (int j = 1; j < upper; j++) {
			cache[j] = base * cache[j] + cache[j - 1] / 10;

		}

		for (int k = 0; k < upper; k++) {
			cache[k] = cache[k] % 10;
		}
	}

	return cache;
}


int main() {

	std::vector<int> cache = products(2, 1000, 310);
	int sum { };

	for (int x : cache) {
		sum += x;
	}

	std::cout << sum << std::endl;

	return 0;
}

