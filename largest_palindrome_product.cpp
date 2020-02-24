/*


 * largest_palindrome_product.cpp
 *
 *  Created on: 5 Jan 2020
 *  Author: Samuel 'Troy' Chinedu


 PROBLEM:
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

bool is_palindrome(const long int &number) {
	//Check if given number is palindrome

	long temp = number, reverse{};

	//reverse the digits of the temporary number
	while (temp > 0) {
		reverse = reverse * 10 + temp % 10;
		temp /= 10;
	}

	//Check if reversed number matches original number
	if (reverse == number) {
		return true;
	} else {
		return false;
	}
}

(long long int large_palindrome;
 std::vector<long long> products;
 for (int i = 100; i < 1000; i++) {
 for (int j = 100; j < 1000; j++) {
 auto temp = i * j;
 if (is_palindrome(temp)) {
 products.push_back(temp);
 }
 }
 }

 auto max = max_element(products.begin(), products.end());
 std::cout << *max;)

int main() {
	long int large_palindrome { };

	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			auto product = i * j;
			if (is_palindrome(product)) {
				if (product > large_palindrome) {
					large_palindrome = product;
				}
			}
		}
	}

	std::cout << large_palindrome;
	return 0;
}

*/
