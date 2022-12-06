#include "Individual.h"
#include "constants.h"
#include "functions.h"

using namespace std;


void selection(vector<Individual>& population)
{
	ld total_fitness = 0;
	vector <ld>prob(population.size() + 1) ;
	vector <ld>q(population.size() + 1) ;


	for (auto& it : population)
		total_fitness += it.fitness;
	vector <Individual> new_population;
  int poz_in_pop = 0;
	
	/// Optimizare 2: ELITISM
	sort(population.begin(), population.end());
	for(int i = five_percent; i > 0; i--)
	{
			new_population.push_back(population.back());
			population.pop_back();
	}


	q[0] = 0;
	for (int i = 0; i < population.size(); ++i)
	{
		prob[i] = population[i].fitness / total_fitness;
		q[i + 1] = q[i] + prob[i];

    }
	for (int i = five_percent; i < max_pop_size; ++i)
    {
		ld probability = dis(gen);

		int poz = 0, st = 0, dr = population.size() - 1;
		while(st <= dr)
		{
			int mid = (st + dr) / 2;
			if(q[mid] < probability)
			{
				poz = mid;
				st = mid + 1;
			}
			else 
				dr = mid - 1;
		}
        new_population.push_back(population[poz]);
    }
    population = new_population;
}
