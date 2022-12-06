#include "Individual.h"
#include "functions.h"

Individual::Individual(const bitset<BIT_LEN> &chromosome)
{
    this->chromosome = chromosome;
    this->compute_val(function_to_evaluate);
};

ld Individual::compute_val(ld (*func)(vector<ld>& x, ll d))
{
    vector<ld> double_vect(dim, 0.0000000);
    ll poz = 0;
    for (ll i = 0; i < total_length; i += bit_length) {
        ll xi = 0LL;
        for (ll j = i; j < i + bit_length; ++j) {
            xi *= 2;
            xi += this->chromosome[j];
        }
        //Optimizare 3: GRAY CODES
        xi = BinaryToGray(xi);
        ld value = (ld)xi / (log_pow(2.000, bit_length) - 1.0000);
        double_vect[poz++] = LO + value * (HI - LO);
        //        cout << double_vect[poz - 1] << ' ';
    }
    this->individual_value = func(double_vect, dim);

    fitness = 0.0001 + this->individual_value;
    if(func == Michalewicz)
        fitness = 30 + this->individual_value;
    
    fitness = 1 / fitness;
    minim = min(minim, individual_value);
    return this->individual_value;
};

// Overloading < operator
bool operator<(const Individual& ind1, const Individual& ind2)
{
    return ind1.fitness < ind2.fitness;
}

void Individual::mutate() {
    for (int i = 0; i < total_length; ++i)
    {
        ld probability = dis(gen);
        // cout << probability << ' ';
        // cout << '\n';
        if (probability < mutationProbability)
        {
            // cout << i << '\n';
            this->chromosome[i] = 1 - this->chromosome[i];
        }
        
    }
}

Individual crossover(const Individual& p1, const Individual& p2)
{
    bitset <BIT_LEN> child_chromosome;
    int poz = random_generator() % total_length;
    for (int i = 0; i < poz; ++i)
        child_chromosome[i] = p1.chromosome[i];

    for (int i = poz; i < total_length; ++i)
        child_chromosome[i] = p2.chromosome[i];
    Individual child(child_chromosome);
    return child;
}

void Individual::print(){
    for(int i = 0; i < total_length; ++i)
        cout << this->chromosome[i];
    cout << '\n';
    cout << '\n';
}