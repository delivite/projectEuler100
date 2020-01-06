/*
 * smallest_multiple.cpp
 *
 *  Created on: 5 Jan 2020
 *      Author: Samuel 'Troy' Chinedu
 */

/* PROBLEM:
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

long long multiple(int number){
	long long ans = 1;

	for (long long i = 1; i<=number; i++){
		ans = (ans * i) / (__gcd(ans, i));
	}
	return ans;
}

int main(){
	cout<<multiple(20)<<endl;

	return 0;
}


