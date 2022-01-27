#include<bits/stdc++.h>
using namespace std;
array<int, 16>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int main_pp(std::vector<std::string>&args)
{
    long n;
    cin >> n;
    if(n < 6)
    {
        cout << "1/2" << endl;
        return 0;
    }
    long unsigned p = 3, q = 1;
    long unsigned r = 1;
    unsigned d = 1;
    n /= 2;
    while(d < 15 && q <= n)
    {
        p = primes[d];
        q *= p;
        r *= p - 1;
        ++d;
    }
    if(q > n)
    {
        q /= p;
        r /= p - 1;
    }
    r /= 2;
    long div = gcd(q, r);
    q /= div;
    r /= div;
    r = q - r;
    cout << r << '/' << q << endl;
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
