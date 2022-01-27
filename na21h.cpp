#include<bits/stdc++.h>
using namespace std;
using pairii = pair<unsigned, unsigned>;
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
istream &readrange(Range &r)
{
    return readrange(r.begin(), r.end());
}
int main_pp(std::vector<std::string>&args)
{
    unsigned c, n;
    cin >> c >> n;
    vector<unsigned>errors(n);
    readrange(errors);
    unsigned cstart = 0;
    vector<pairii>cranges, eranges;
    pairii er{0, 0};
    for(unsigned e : errors)
    {
        if(er.first == 0)
        {
            er = {e, e};
            if(e > 1)
                cranges.emplace_back(1, e - 1);
        }
        else if(er.second + 1 == e)
            ++er.second;
        else
        {
            eranges.push_back(er);
            cranges.emplace_back(er.second + 1, e - 1);
            er = {e, e};
        }
    }
    eranges.push_back(er);
    if(er.second < c)
        cranges.emplace_back(er.second + 1, c);
    cout << "Errors: ";
    for(unsigned i = 0; i < eranges.size(); i++)
    {
        auto r = eranges[i];
        if(r.first == r.second)
            cout << r.first;
        else
            cout << r.first << '-' << r.second;
        if(i == eranges.size() - 2)
            cout << " and ";
        else if(i == eranges.size() - 1)
            cout << endl;
        else
            cout << ", ";
    }
    cout << "Correct: ";
    for(unsigned i = 0; i < cranges.size(); i++)
    {
        auto r = cranges[i];
        if(r.first == r.second)
            cout << r.first;
        else
            cout << r.first << '-' << r.second;
        if(i == cranges.size() - 2)
            cout << " and ";
        else if(i == cranges.size() - 1)
            cout << endl;
        else
            cout << ", ";
    }
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
