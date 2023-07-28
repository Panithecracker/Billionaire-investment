#pragma once
/*
This is the header file for the functions defined to find the solution to the problem
*/
#include<iostream>
#include<vector>
#include<random>
#include<cmath>
using namespace std;

void Play_Game(vector<int> sequence, double f) //Naive way to compute the resulting capital for a given sequence and proportion
{
    //useful to play and become familiar with the problem allowing me to conjecture some interesting claims.
    double capital = 1.0;
    double bet;
    for(int i = 0; i<sequence.size(); i++)
    {
        bet = f*capital; //current bet 
        if (sequence[i] == 1)
        {
          capital += 2*bet; //wins twice the current bet (WIN)
        }
        else
        {
            capital -= bet; //remove  the bet amount (LOSS)
        }
    }
    cout << "SEQUENCE :  ";
    for(int j = 0; j<sequence.size() ; ++j)
    {
        cout << sequence[j] << " ";
    }
    cout << "\nRESULTING CAPITAL -> " << capital << endl;
}

double CountHeads(vector<int> sequence) //counts the amount of heads (wins) seen on a 1000toss sequence
{
    double count = 0.0;
    for(int i = 0; i<sequence.size(); ++i)
    {
        if (sequence[i] == 1)
        {
            count++;
        }
    }
    return count;
}

double FinalCapital(vector<int> sequence, double f) //after some work, I derived this formula!
{
    // notice that surprisingly, the final capital has turned out to depend only on the amount of heads , ignoring the order in which these appeared (that was really neat to discover)!
    // if you dont believe me, test this claim with the PlayGame function in the beginning!
    int heads = CountHeads(sequence);
    int tails = sequence.size()-heads;
    return (pow((1+2*f),heads))*(pow(1-f,tails)); //this formula is incredibly useful and its discovery was key...
}

vector<int> RandomSequence(int size) //initializes a random 1000 toss results sequence 
{
    vector<int> rsequence;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    for(int i = 0; i < size; ++i)
    {
        rsequence.push_back(dis(gen));
    }
    return rsequence;
}

int MinHeads(double f, double c) //this function depends on a proportion f, and returns the min number of heads to make for a given f ,at least c units of money
{
    //f:fixed proportion before starting the game
    //c:minimum capital to make
    return ceil((log(c) - 1000*log(1-f))/(log(1 + 2*f) - log(1-f)));
}


vector<int> ones_and_zeros(int n, int s) { //returns a sequence with n ones
    vector<int> result(s, 0);
    fill(result.begin(), result.begin() + n, 1);
    return result;
}

long long nchoosek(int n, int k) { 
    if (k > n || k < 0) {
        return 0;
    }

    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    return res;
}


//define your function here : 
double f(double x, double c)
{
    //function whose roots wants to be found must be expressed below:
    //x : fixed proportion before starting the game
    //c : minimum capoital to make
    return ((-2*pow(x,2.0) + (2000*c + 1)*x +1000*c +1)*log(1 + 2*x) + (2*pow(x,2.0) - (2000*c +1)*x +2000*c-1)*log(1 - x) -3*c*log(c) );
}

//numerical derivative of the specified function f above

double fp(double x, double delta , double c) //evaluates the num derivative of f using a delta as parameter
{
    return (f(x+delta, c)-f(x,c))/(delta);
}

//function that performs the newton raphson algorithm (numerically) up to a limit amount of iterations

double NewtonRaphson(double guess, int iters, double delta, double c)
{
    //guess : initial root estimate
    //iter : # of iterations to do
    //delta: step size for derivative estimate
    //c: minimum capital to make
    for(int i = 0; i<iters ; ++i)
    {
        double d = fp(guess,delta, c);
        if( d!= 0){
            guess -= (f(guess, c))/(d);
        }else{
            break;
        }
    }
    return guess;
}

//recursive implementation of the binomial random variable cumulative distribution function

//first, define the pmf recursively

double binomial_pmf(int n, double p, int x) //defining the binomial random variable probability mass function recursively
{
    //base case:
    if (x == 0)
    return pow(1.0-p,n);
    //recursive part:
    return (p*(n-x))/((1.0-p)*(x+1.0))* binomial_pmf(n, p, x-1);

}

double binomial_cdf(int n, double p, int x) //cumulative distribution function respectively 
{
    //Base case:
    if (x == 0)
    return pow(1.0-p,n);
    //Recursive part:
    return binomial_pmf(n, p, x) + binomial_cdf(n, p, x-1);
}

