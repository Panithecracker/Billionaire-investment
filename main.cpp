#include<iostream>
#include "billionaire.hpp"


using namespace std;

int main()
{
    /*
    // Step 1 : Compute the value of f that minimizes the amount of heads needed to make at least a billion dollars
    double optimal_f = NewtonRaphson(0.2,25,0.001); 
    int min_heads = MinHeads(optimal_f);
    cout << "Optimal proportion is estimated to be -> " << optimal_f << endl;
    cout << "In fact the min heads in the game to ensure billion gains is -> " << MinHeads(optimal_f) << endl; 
    */
    cout << binomial_pmf(100, 0.75, 70) << endl;
    return 0;
}





