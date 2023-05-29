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

![2023-05-29](https://github.com/Panithecracker/Billionaire-investment/assets/97905110/a403bd75-8267-497d-9324-515af9edd671)

![2023-05-29 (2)](https://github.com/Panithecracker/Billionaire-investment/assets/97905110/40eb6c7f-ea54-42b8-a512-25ce0c157e13)

![2023-05-29 (1)](https://github.com/Panithecracker/Billionaire-investment/assets/97905110/517fa299-de06-4e34-be15-f98e5e31e35f)
