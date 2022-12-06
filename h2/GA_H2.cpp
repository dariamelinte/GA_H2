
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

#include "Individual.cpp"
#include "Individual-Functions.cpp"
using namespace std::chrono;
void run_genetic_alg(ld(*func)(vector<ld>& x, ll d), ll dimensions, ld L, ld H, string file_name)
{
    LO = L;
    HI = H;
    dim = dimensions;
    function_to_evaluate = func;
    update_length();
    ///RUN ALGO
    vector<Individual> population;
    auto start = steady_clock::now();
    for (int i = 1; i <= max_pop_size; ++i)
        population.push_back(Individual());
 
    ofstream f(file_name, std::ios_base::app);
    f << setprecision(5) << fixed;
    for (int i = 1; i <= nr_pop; ++i)
    {
        selection(population);
 
        for (auto& it : population)
            it.mutate();
 
        random_shuffle(population.begin(), population.end());
 
        int old_size = population.size();
        for (int i = 0; i + 1 < old_size; i += 2)
        {
            ld probability = dis(gen);
            if (probability < crossoverProbability)
            {
                population.push_back(crossover(population[i], population[i + 1]));
            }
        }

        ///Optimizare - ultimii x 
        sort(population.begin(), population.end());
        for(int i = 0; i < five_percent ; ++i)
            population[i] = Individual();
    }
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    f << minim << " ; " << float(duration.count() / 1000000.00) << "\n\n";
}
 
int main() {
    cout << setprecision(5) << fixed;
    int runs = 50;
    ld ans = 0;
    for (int i = 1; i <= runs; ++i)
    {
        run_genetic_alg(Schwefels, 30, -500, 500, "Schwefels_o_30.txt");
        ans += minim;
    }
    cout << ans / runs << '\n';

    return 0;
}
 
