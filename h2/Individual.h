#include "functions.h"
#include "constants.h"

using namespace std;
typedef double ld;
typedef long long int ll;
typedef pair<ld, ld> lld;

class Individual
{
public:
    bitset<BIT_LEN> chromosome;
    ld fitness;
    ld individual_value;
    Individual(const bitset<BIT_LEN> &);
    Individual()
    {
        random_bit_string(this->chromosome, total_length);
        this->compute_val(function_to_evaluate);
    };
    Individual mate(const Individual &parent2);
    void mutate();
    void print();
    ld compute_val(ld (*func)(vector<ld> &x, ll d));
    friend Individual crossover(const Individual &p1, const Individual &p2);
};
