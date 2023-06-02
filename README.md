# Billionaire-investment
This repo consists on a solution to an interesting real life problem, looking for an accurate and efficient algorithm that relies on the mathematics from the fundamental fields of calculus and probability.
Some of the main concepts that I relied on in order to solve it were : 
- Random variables
- The Binomial random variable and recursivity
- Transformation of random variables
- Expectation
- Optimization 
- Newton Raphson method
- Graphs

# Problem description: 
You are given a unique investment opportunity.
Starting with £1 of capital, you can choose a fixed proportion, f, of your capital to bet on a fair coin toss repeatedly for 1000 tosses.
Your return is double your bet for heads and you lose your bet for tails.
For example, if f = 1/4, for the first toss you bet £0.25, and if heads comes up you win £0.5 and so then have £1.5. You then bet £0.375 and if the second toss is tails, you have £1.125.
Choosing f to maximize your chances of having at least £1,000,000,000 after 1,000 flips, what is the chance that you become a billionaire?
All computations are assumed to be exact (no rounding), but give your answer rounded to 12 digits behind the decimal point in the form 0.abcdefghijkl.

# Solution :
In order to allow others to enjoy the experience of solving the problem by themsleves, one can only see the quantitative answer with 12 digits of precision printed on screen when executing the main program. On the other hand, I decided to visualize the results obtained after coming up with the solution by graphing a function that I derived, which tells you the minimum number of heads needed


![2023-05-29 1](https://github.com/Panithecracker/Billionaire-investment/assets/97905110/350a62c8-92d8-4a65-b71f-65b75e133318)

![2023-05-29 2](https://github.com/Panithecracker/Billionaire-investment/assets/97905110/f5fcef08-373f-46cb-a21a-426d45e3a71e)
![2023-05-29](https://github.com/Panithecracker/Billionaire-investment/assets/97905110/bac57965-2ec4-4c51-9de8-a0152a5e5644)

