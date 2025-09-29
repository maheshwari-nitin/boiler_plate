#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE 
#define IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#else
#define IO 
#define time
#endif
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define db double
#define vb vector<bool>
#define vii vector<int>
#define nl '\n'
#define pll vector<pair<ll, ll>>
#define pii pair<int, int>
#define fl(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define dis(v) for (auto x : v) cout << x << " ";
#define fi first
#define se second
#define YES cout << "YES" << nl;
#define NO cout << "NO" << nl;
#define mod 998244353
#define ld long double
using namespace std;

const int MOD = 1e9 + 7; 

void solve() {
    int n = 5 * 1e6 + 5;
    vii spf(n);
    iota(all(spf), 0);

    //sieve to store spf of each number from 1 to n
    for(int i = 2; i * i < n; i++){
        if(spf[i] == i){
            for(int j = i * i; j < n; j += i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
  
    //number of prime factors of each number from 1 to n
    vii cnt(n, 0);
    FOR(i, 2, n){
        cnt[i] = cnt[i / spf[i]] + 1;
    }  
    

}

int32_t main() { 
    IO; 
    fastio;
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
