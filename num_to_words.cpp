/*
 * num_to_words.cpp
 *
 *  Created on: 5 Mar 2020
 *      Author: Troy
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

std::string num_to_word(long value) {
	std::string word;
	std::vector<std::string> ones { "zero", "one", "two", "three", "four",
			"five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
			"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
			"eighteen", "nineteen" };
	std::vector<std::string> tens { "", "ten", "twenty", "thirty", "forty",
			"fifty", "sixty", "seventy", "eighty", "ninety" };

	long temp = std::abs(value);
	while (temp >= 0) {

		if (temp >= 1000000 && temp < 1000000000) {
			word += num_to_word(temp / 1000000) + " million ";
			temp = temp % 1000000;
			if (temp==0) break;
		}
		if (temp >= 1000 && temp < 1000000) {
			word += num_to_word(temp / 1000) + " thousand ";
			temp = temp % 1000;
			if (temp==0) break;
		}

		if (temp >= 100 && temp < 1000) {
			word += num_to_word(temp / 100) + " hundred";
			temp = temp % 100;
			if (temp==0) break;
			else word+= " and ";
		}

		if (temp >= 20 && temp < 100) {
			word += tens[temp / 10] + " ";
			temp = temp % 10;
			if (temp==0) break;
		}

		if (temp < 20) {
			word += ones[temp];
			temp = temp % 100;
			break;
		}

	}
	if (value < 0) {
		word = "minus " + word;
	}
	return word;
}

int main() {
	std::cout << num_to_word(4500000);
	return 0;
}

