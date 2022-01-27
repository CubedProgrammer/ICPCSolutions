#include<iostream>
#include<vector>
using namespace std;
int main_pp(std::vector<std::string>&args)
{
    string eye;
    cin >> eye;
    if(eye.length() % 2 != 0)
        cout << "fix" << endl;
    else
    {
        if(eye.find("()") == eye.size() / 2 - 1)
            cout << "correct" << endl;
        else
            cout << "fix" << endl;
    }
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
