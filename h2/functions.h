#pragma once
#include <vector>
#include <bitset>
#include <random>
#include <iostream>
#include <ctime>
#include <chrono>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "constants.h"

mt19937 random_generator(time(NULL));
using namespace std;

ld inline log_pow(ld a, ll b) {
	ld r = 1;
	while (b) {
		if (b & 1)
			r *= a;
		a *= a;
		b /= 2;
	}
	return r;
}

unsigned long long BinaryToGray(ll num)
{
    return num ^ (num >> 1); 
}

inline ld Rastrigin(vector<ld>& x, ll d) {
	ld fx = 10.00 * d;
	for (ll i = 0; i < d; ++i) {
		fx += x[i] * x[i] - cos(2 * pi * x[i]) * 10;
	}

	return fx;
}


inline ld De_Jongs(vector<ld>& x, ll d) {
	ld fx = 0;
	for (ll i = 0; i < d; ++i) {
		fx += x[i] * x[i];
	}

	return fx;
}

inline ld Michalewicz(vector<ld>& x, ll d) {
	ld fx = 0;
	for (ll i = 0; i < d; ++i) {
		fx -= sin(x[i]) * log_pow(sin((i + 1) * x[i] * x[i] / pi), 20);
	}

	return fx;
}

inline ld Schwefels(vector<ld>& x, ll d) {
	ld fx = d * 418.9829;
	for (ll i = 0; i < d; ++i) {
		fx -= x[i] * sin(sqrt(abs(x[i])));
	}
	return fx;
}


inline void random_bit_string(bitset<BIT_LEN>& x, ll total_length) {
	for (ll i = 0; i < total_length; ++i) {
		x[i] = random_generator() % 2;
	}
}
auto function_to_evaluate = &Rastrigin;

