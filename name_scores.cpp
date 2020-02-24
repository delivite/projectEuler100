/*
 * name_scores.cpp
 *
 *  Created on: 24 Feb 2020
 *      Author: Troy
 *
 * PROBLEM:
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 * What is the total of all the name scores in the file?
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

std::vector<std::string> read_file(std::string file_name) {

	std::vector<std::string> store;

	std::fstream txt_file;
	txt_file.open(file_name, std::ios::in); //Open file
	if (txt_file.is_open()) {

		while (txt_file.good()) {
			std::string temp { };
			std::getline(txt_file, temp, ','); //Read names
			store.push_back(temp);			//Save to the vector
		}

	} else {
		std::cerr << "Could not open file." << std::endl;
	}
	txt_file.close(); //Close file
	return store;
}

int calculate_name_score(std::string name) {
	int result { };
	for (char c : name) {
		if (c != '"')
			result += c - 64;
	}

	return result;
}


int main() {
	std::vector<std::string> names = read_file("names.txt");
	long result { };

	std::sort(names.begin(), names.end()); //Sort vector

	for (unsigned int i = 0; i < names.size(); i++) {

		long temp = calculate_name_score(names[i]) * (i + 1); //i + 1 to get the position of i because vector is zero indexed

		result += temp;
	}

	std::cout << result;

	return 0;
}

