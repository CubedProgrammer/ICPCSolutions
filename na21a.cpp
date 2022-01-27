#include<bits/stdc++.h>
using namespace std;
template<typename Arr, typename T>
void fillarr(Arr &arr, const T &val)
{
    using Stored = typename remove_all_extents<Arr>::type;
    Stored *f = reinterpret_cast<Stored*>(&arr);
    char *tmp = reinterpret_cast<char*>(f) + sizeof(Arr);
    Stored *l = reinterpret_cast<Stored*>(tmp);
    fill(f, l, val);
}
template<typename InIt>
ostream &putrange(InIt first, InIt last)
{
    while(first != last)
    {
        cout << *first;
        ++first;
        if(first != last)
            cout << ' ';
    }
    return cout;
}
template<typename Range>
ostream &putrange(Range r)
{
    return putrange(r.begin(), r.cend());
}
template<typename OutIt>
istream &readrange(OutIt first, OutIt last)
{
    while(first != last)
    {
        cin >> *first;
        ++first;
    }
    return cin;
}
template<typename Range>
istream &readrange(Range r)
{
    return readrange(r.begin(), r.end());
}
int main_pp(std::vector<std::string>&args)
{
    long n;
    cin >> n;
    string s = to_string(n);
    array<unsigned, 10>freq;
    freq.fill(0);
    for(char c : s)
        ++freq[c - '0'];
    long small = s[0] - '0';
    while(small > 0 && freq[--small] != 0);
    int digit = 10;
    while(digit > 0 && freq[--digit] != 0);
    if(freq[digit] != 0)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if(small == 0)
        small = digit;
    if(digit == 0)
        goto zero;
    while(small < n)
    {
        small *= 10;
        small += digit;
    }
    small /= 10;
zero:
    long big = find(freq.begin() + s[0] - '0', freq.end(), 0) - freq.begin();
    digit = find(freq.begin(), freq.end(), 0) - freq.begin();
    if(big == 10)
        big = digit;
    if(big == 0)
        big = find(freq.begin() + 1, freq.end(), 0) - freq.begin();
    if(big == 10)
        big = 99999999999999999;
    while(big < n)
    {
        big *= 10;
        big += digit;
    }
    if(big - n == n - small)
        cout << small << ' ' << big << endl;
    else if(big - n > n - small)
        cout << small << endl;
    else
        cout << big << endl;
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
