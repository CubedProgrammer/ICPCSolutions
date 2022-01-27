#include<bits/stdc++.h>
using namespace std;
string tripleX = "XXX";
string tripleO = "OOO";
int main_pp(std::vector<std::string>&args)
{
    unsigned tests;
    cin >> tests;
    unsigned statenum;
    string statestr;
    string board = "         ", tboard = board;
    for(unsigned test = 0; test < tests; test++)
    {
        cin >> statestr;
        statenum = stoi(statestr, nullptr, 8);
        for(unsigned i = 0; i < 9; i++)
        {
            if(statenum & 1 << i)
                board[i] = statenum & 1 << (i + 9) ? 'X' : 'O';
            else
                board[i] = ' ';
        }
        for(unsigned i = 0; i < 3; i++)
        {
            tboard[i] = board[i*3];
            tboard[i+3] = board[i*3+1];
            tboard[i+6] = board[i*3+2];
        }
        if(board.substr(0, 3) == tripleX || board.substr(3, 3) == tripleX || board.substr(6, 3) == tripleX)
            cout << "X wins" << endl;
        else if(tboard.substr(0, 3) == tripleX || tboard.substr(3, 3) == tripleX || tboard.substr(6, 3) == tripleX)
            cout << "X wins" << endl;
        else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
            cout << "X wins" << endl;
        else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
            cout << "X wins" << endl;
        else if(board.substr(0, 3) == tripleO || board.substr(3, 3) == tripleO || board.substr(6, 3) == tripleO)
            cout << "O wins" << endl;
        else if(tboard.substr(0, 3) == tripleO || tboard.substr(3, 3) == tripleO || tboard.substr(6, 3) == tripleO)
            cout << "O wins" << endl;
        else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
            cout << "O wins" << endl;
        else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
            cout << "O wins" << endl;
        else if(board.find(' ') != string::npos)
            cout << "In progress" << endl;
        else
            cout << "Cat's" << endl;
    }
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
