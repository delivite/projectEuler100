/*
 * 1000st_prime.cpp
 *
 *  Created on: 7 Jan 2020
 *      Author: Samuel 'Troy' Chinedu
 */

/* PROBLEM #7: 10001st Prime
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 */

#include <iostream>
#include <cstdlib>
#include <chrono>

bool is_prime(long number) {

	if (number == 1) //Terminate if number is 1. 1 is not a prime number
			{
		return false;
	}

	for (int i = 2; i < number; i++) {
		//Terminate and return false if number is not 2 AND, is divisible by 2 OR is divisible by any number in the iterator
		if (number != 2 && (number % 2 == 0 || number % i == 0)) {
			return false;
		}
	}
	return true;
}

long nth_prime(int n) {
	int num { 1 }, count { 0 };
	while (true) {
		num++;
		if (is_prime(num)) {
			//std::cout << num << ' ' << std::flush;
			count++;
		}

		//stops loop when the counter is equal to the given nth term
		if (count == n) {
			break;
		}
	}
	return num;
}

int main() {

	/*
	 * I'm interested to see how long it takes to find different nth prime numbers.
	 * I will compare this with other algorithms.
	 */

	//Get start time
	auto start_time = std::chrono::high_resolution_clock::now();

	//Call function
	std::cout<<nth_prime(10001)<<'\n';

	//Get end time
	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end_time - start_time;

	std::cout << "Time elapsed: " << diff.count() << " seconds."
			<< std::endl;
}

