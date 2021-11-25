#include <bits/stdc++.h>
 
#define int int64_t
#define t feuer_frei
 
using namespace std;
 
int a[100000];
 
struct segtree
{
    int MAXN = 1000000;
    int t[400000];
    int n;
    int sz = -1;
    void build(int v, int l, int r)
    {
        if (l == r)
        {
            t[v] = a[l];
        }
        else
        {
            int mid = (l + r) / 2;
            build(v * 2, l, mid);
            build(v * 2 + 1, mid + 1, r);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    int get(int v, int l, int r, int ql, int qr)
    {
        if(l > r){
            return 0;
        }
        if (l > qr || r < ql)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return t[v];
        }
        int mid = (l + r) / 2;
        return get(v * 2, l, mid, ql, qr) + get(v * 2 + 1, mid + 1, r, ql, qr);
    }
    void upd(int v, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[v] = val;
            a[l] = val;
        }
        else
        {
            int mid = (l + r) / 2;
            if (pos <= mid)
            {
                upd(v * 2, l, mid, pos, val);
            }
            else
            {
                upd(v * 2 + 1, mid + 1, r, pos, val);
            }
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};
 
 
int32_t main()
{
    int n, m;
    cin >> n;
 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segtree t;
    t.build(1, 0, n - 1);
    cin >> m;
    while(m--)
    {
        int l, r;
        char c;
        cin >> c;
        cin >> l >> r;
        if(c == 's')cout << t.get(1, 0, n - 1, l - 1, r - 1) << endl;
        if(c == 'u')t.upd(1, 0, n - 1, l - 1, r);
 
 
 
    }
 
 
}