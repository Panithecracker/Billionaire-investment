#include<iostream>
#include "billionaire.hpp"


using namespace std;

int main()
{

    // Computing the value of f that minimizes the amount of heads needed to make at least a billion dollars
    //minimum capital to make is c:
    //for the specific problem it is a billion, however it works with any other value
    double c = pow(10.0,9.0);
    double optimal_f = NewtonRaphson(0.2,25,0.001,c ); 
    int min_heads = MinHeads(optimal_f, c);
    cout << "Optimal proportion is estimated to be -> " << optimal_f << endl;
    cout << "In fact the min heads in the game to ensure billion gains is -> " << min_heads << endl; 
    
    return 0;
}





