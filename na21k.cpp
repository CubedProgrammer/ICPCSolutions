#include<bits/stdc++.h>
using namespace std;
using ustu = unordered_set<unsigned>;
array<unsigned, 1000000>stamps, sums;
int main_pp(std::vector<std::string>&args)
{
    unsigned m, n;
    cin >> m >> n;
    for(unsigned i = 0; i < m; i++)
        cin >> stamps[i];
    sums = stamps;
    for(unsigned i = 1; i < m; i++)
        sums[i] += sums[i-1];
    unsigned tot = 0;
    ustu rsums;
    for(int i = m - 1; i >= 0; i--)
    {
        tot += stamps[i];
        rsums.insert(tot);
    }
    rsums.insert(0);
    bool no;
    unsigned q;
    for(unsigned i = 0; i < n; i++)
    {
        cin >> q;
        if(q > tot)
            cout << "No" << endl;
        else if(q == tot)
            cout << "Yes" << endl;
        else if(rsums.count(q))
            cout << "Yes" << endl;
        else
        {
            no = true;
            for(unsigned j = 0; j < m; j++)
            {
                if(rsums.count(q - sums[j]))
                {
                    cout << "Yes" << endl;
                    no = false;
                    break;
                }
            }
            if(no)
                cout << "No" << endl;
        }
    }
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
