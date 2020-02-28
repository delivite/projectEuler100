/*
 * pig_latin.cpp
 *
 *  Created on: 26 Feb 2020
 *      Author: Troy
 *
 * PROBLEM:
 * Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

std::string pig_Latin(const std::string& str) {
	const char *c = &str[0];
	std::string new_phrase;
	while (*c != 0) {
		if (*c >= 'A' && *c <= 'z') {
			char temp = *c;
			++c;
			while (*c != ' ' && *c != 0) {
				new_phrase += *c;
				++c;
			}
			new_phrase += temp;
			new_phrase += "ay";
		} else {
			new_phrase += *c;
			++c;
		}
	}

	return new_phrase;
}

int main() {
	std::cout << pig_Latin("This is my string  .");

	return 0;
}

