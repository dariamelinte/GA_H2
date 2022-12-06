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
#define run(X, Y)                \
	for (int i = 1; i <= X; ++i) \
		Y;
#define BIT_LEN 3000
using namespace std;

typedef double ld;
typedef long long int ll;
typedef pair<ld, ld> lld;

const ld eps = 1e-5;
const ld eps_dif = 1e-10;
const ll precision = 5;
const ld pi = 3.141592653;

const int five_percent = 10;
ld HI = 5.12;
ld LO = -5.12;
ll dim = 5;
ll bit_length, total_length;

ld mutationProbability = 0.0008;
ld crossoverProbability = 0.89;

const ll max_pop_size = 200;
const ll nr_pop = 2000;
ld minim = numeric_limits<ld>::max();

void update_length()
{
	minim = numeric_limits<ld>::max();
	bit_length = ceil(log2(pow(10, precision) * (HI - LO)));
	total_length = bit_length * dim;
}

std::random_device rd;
std::mt19937 gen(rd());
uniform_real_distribution<> dis(0.0, 1.0);
