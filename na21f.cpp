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
constexpr int MOD = 1000000007;
array<array<long, 100000>, 5>cnts;
string vs = "aeiou";
int main_pp(std::vector<std::string>&args)
{
    string str;
    cin >> str;
    string tmp;
    bool last = vs.find(str[0]) == string::npos;
    for(char c : str)
    {
        if(vs.find(c) != string::npos)
        {
            if(!last)
                tmp += c;
            last = true;
        }
        else
        {
            if(last)
                tmp += c;
            last = false;
        }
    }
    str = tmp;
    unsigned pos = 0;
    for(char c : str)
    {
        if(vs.find(c) != string::npos)
        {
            if(pos == 0)
            {
                cnts[0][0] = 1;
                goto loopend;
            }
            else
            {
                cnts[1][pos] = cnts[1][pos-1];
                cnts[3][pos] = cnts[3][pos-1];
                cnts[0][pos] = cnts[0][pos-1] + 1;
                cnts[2][pos] = cnts[1][pos-1] + cnts[2][pos-1];
                cnts[4][pos] = cnts[3][pos-1] + cnts[4][pos-1];
            }
        }
        else
        {
            if(pos == 0)
                goto loopend;
            else
            {
                cnts[0][pos] = cnts[0][pos-1];
                cnts[2][pos] = cnts[2][pos-1];
                cnts[4][pos] = cnts[4][pos-1];
                cnts[1][pos] = cnts[0][pos-1] + cnts[1][pos-1];
                cnts[3][pos] = cnts[2][pos-1] + cnts[3][pos-1];
            }
        }
        for(auto &arr : cnts)
            arr[pos] %= MOD;
        for(auto &arr : cnts)
            cout << arr[pos] << ' ';
        cout << endl;
    loopend:
        ++pos;
    }
    cout << str << endl;
    cout << cnts[4][str.size() - 1] << endl;
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
