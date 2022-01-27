# ICPC Partial Solutions 2021
The g and h solutions may be messed up.
### Alien Integers
Find the larger and smaller and compare if their distance is equal.
The larger is the number with leading digit that is the smallest digit greater than the leading digit of N the input number, and not in N.
Or it starts with the smallest digit not in N, and the number is one digit longer.
The remaining digits is the smallest digit not in N.
The smaller number is the reverse, largest digit smaller than the leading digit, or largest digit and one digit shorter.
Maybe hard code single digits.
### Avoiding Asteroids
No idea.
### Common Factors
The Euler totient function determines the number of numbers coprime to the number less than or equal to itself.
For example, phi(30)=8.
1, 7, 11, 13, 17, 19, 23, 29.
The formula is, given all prime numbers that divide the input number, multiply the product by the product of the numbers one less than the primes.
Then divide by the product of the primes.

For example, phi(30)=1\*2\*4\*30/2/3/5=8.

We want to minimize the ratio of this to the original number.
Note that if k is already a prime factor of the original, we'll call the original n, it multiplies the result of the phi function by k, since phi is linear.
However, this doesn't change the ratio, so we don't want redundant prime factors.

Here's the algorithm, given the input number N, start with M=2, multiply by the next prime number continously until multiplying the next prime number will make M greater than N.
Small values may need to be hardcoded, and beware of overflow.
The fraction can be determined using the formula for the totient function above, remember to reduce the fraction to simplest terms.
