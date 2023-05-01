#include<iostream>
#include "billionaire.hpp"


using namespace std;

int main()
{
    double optimal_f = NewtonRaphson(0.2,25,0.001); 
    int min_heads = MinHeads(optimal_f);
    cout << "Optimal proportion is estimated to be -> " << optimal_f << endl;
    cout << "In fact the min heads in the game to ensure billion gains is -> " << MinHeads(optimal_f) << endl; 
    return 0;
}



