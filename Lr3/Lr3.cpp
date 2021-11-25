#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

const int N = 1002;

int x[N], y[N], a[N][N];

int main() {

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> y[i];
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                a[i][j] = 1 + a[i - 1][j - 1];
            }
            else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }

    vector<int> v;

    int i = n, j = m;

     while (i && j) {
        if (x[i] == y[j])  {
            v.push_back(x[i]);
            i--;
            j--;
        }
        else if (a[i - 1][j] == a[i][j]) {
            i--;
        }
        else {
            j--;
        }
    }

    for (int k = v.size() - 1; k >= 0; k--) {
        cout << v[k] << ' ';
    }

    return 0;
}