#include <iostream>
#define info(msg) cout << #msg << " = " << msg << endl;

using namespace std;

string shift(string s){
    return s[s.size() - 1] + s.substr(0, s.size() - 1);
}

int movements(string s1, string s2, int moves = 0){
    if (s1 == s2)
        return moves;
    else if (moves == s1.size())
        return -1;
    else
        return movements(shift(s1), s2, ++moves);
}

int main()
{
    string s1 = "";
    string s2 = "";
    cin >> s1 >> s2;
    cout << movements(s1, s2);
    return 0;
}