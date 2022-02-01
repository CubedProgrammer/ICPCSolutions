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
### Dimensional Analysis
No idea.
### Eye of Sauron
Search for the string "()". Let n be the length of the input string. The index should be n/2-1.

Make sure to check if the input string has even length.
### ilove Strings
Did not solve. The idea is probably to use a multidimensional array. Let n be the length of the string.

The array should be 27 by 5 by n, to cache what letters are already in partial words, and how many ilove-substrings of lengths 1-5 up to that point.
### MrCodeFormatGrader
Have two arrays, one for ranges of error lines and one for ranges of correct lines.
Loop through the array of errors, if the current error line is the one after the end of the last error range, extend it, otherwise, add the lines in between the error lines as a correct range to that array, and make new error range.

Beware of edge case for the first error line or range.
### Mult!
Have a start variable to store the starting value, it should start at an invalid value, like 999999999.
Loop through all numbers, if start is invalid, set it to current, if current number is a multiple, print and set start to the invalid value.
### Pizza Party
No idea.
### Stacking Up
No idea.
### Stamp Combinations
Use a hash table to store the values of the prefix sum array.
Be sure to take care of the edge case of zero.
Loop through the reverse prefix sum array and check if there is a number in the forward prefix sum array.
If it exists, it's possible, otherwise, not possible.
### Sword Counting
No idea.
### Tic-Tac State
Use a string to store the board state. Use bit shift and bitwise and operator to obtain the value of a bit.

Check indices 0-2, 3-5, and 6-8 for triple Xs, then transpose the board and do it again.
Then, check the diagonals, and repeat for Os.

Finally, check if the board is filled, search for the character used for empty space.
### Venn Intervals
No idea.

