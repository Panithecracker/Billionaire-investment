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

double CountHeads(vector<int> sequence)
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

double FinalCapital(vector<int> sequence, double f)
{
    int heads = CountHeads(sequence);
    int tails = sequence.size()-heads;
    return (pow((1+2*f),heads))*(pow(1-f,tails)); //this formula is incredibly useful and its discovery was key...
}

vector<int> RandomSequence(int size)
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

int MinHeads(double f) //this function depends on a proportion f, and returns the min number of heads to make for a given f , at least a billion 
{
    return ceil((9.0*log(10.0) - 1000.0*log(1.0-f))/(log(1.0+2.0*f) - log(1.0-f)));
}


vector<int> ones_and_zeros(int n, int s) {
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
double f(double x)
{
    return 1000*(1+2*x)*log((1+2*x)/(1-x)) +3000*log(1-x)-27*log(10);
}

//numerical derivative of the specified function f above

double fp(double x, double delta ) //evaluates the num derivative of f using a delta as parameter
{
    return (f(x+delta)-f(x))/(delta);
}

//function that performs the newton raphson algorithm (numerically) up to a limit amount of iterations

double NewtonRaphson(double guess, int iters, double delta)
{
    for(int i = 0; i<iters ; ++i)
    {
        double d = fp(guess,delta);
        if( d!= 0){
            guess -= (f(guess))/(d);
        }else{
            break;
        }
    }
    return guess;
}

//recursive implementation of the binomial random variable cumulative distribution function

//first, define the pmf recursively

double binomial_pmf(int n, double p, int x)
{
    //base case:
    if (x == 0)
    return pow(1.0-p,n);
    //recursive part:
    return (p*(n-x))/((1.0-p)*(x+1.0))* binomial_pmf(n, p, x-1);

}

double binomial_cdf(int n, double p, int x)
{
    //Base case:
    if (x == 0)
    return pow(1.0-p,n);
    //Recursive part:
    return binomial_pmf(n, p, x) + binomial_cdf(n, p, x-1);
}

