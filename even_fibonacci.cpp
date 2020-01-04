/*
 * even_fibonacci.cpp
 *
 *  Created on: 4 Jan 2020
 *      Author: Troy
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

int main(){
	std::vector<int> numbers = { 1, 2 };
	int sum { 0 };
	while (sum <= 4000000) {
		sum = numbers[numbers.size() - 1] + numbers[numbers.size() - 2];
		numbers.push_back(sum);
	}

	sum = 0;

	for (int x : numbers)
		if (x % 2 == 0) {
			sum += x;
		}

	std::cout << sum;
}


