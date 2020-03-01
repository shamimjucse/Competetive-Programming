#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
const ll mod = 1000000007;
vector<int>adj[N];
int lev[N], x;
void dfs(int u, int p)
{
    lev[u] = lev[p]+1;
    for(auto v : adj[u])
    {
        if(v!=p)
        {
            if(lev[v]==-1) dfs(v, u);
            else if(lev[v]<=lev[u])x = lev[u]+1-lev[v];
        }
    }
}
ll power(ll a, ll b, ll mod)
{
    ll ans = 1;
    a%=mod;
    while(b>0)
    {
        if(b&1)ans = ans * a % mod;
        a = a * a % mod;
        b/=2;
    }
    return ans;
}
ll fact[N];
ll nCr(int n, int r)
{
    if(n<0 || n<r)return 0LL;
    return fact[n] * power(fact[r], mod-2, mod)%mod * power(fact[n-r], mod-2, mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    fact[0] = 1;
    for(ll i=1; i<N; i++)fact[i] = fact[i-1] * i % mod;
    int tc,t=1; cin >> tc;
    while(tc--)
    {
        int n,k; cin >> n >> k;
        for(int i=1; i<=n; i++)
        {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(lev, -1, sizeof lev);
        lev[1] = 0;
        x = 0;
        dfs(1,0);
        if(x==0)x=2;

        ll p = ( nCr(n, k) + nCr(x, 1) * nCr(n-1, k-1) % mod * nCr(n-k, 1) % mod ) % mod;
        ll q = nCr(n, k) * nCr(n, k) % mod;
        p = ((q-p)%mod+mod)%mod;
        ll ans = (p * power(q, mod-2, mod)) % mod;
        cout << ans << "\n";
        for(int i=1; i<=n; i++)adj[i].clear();
    }
    return 0;
}
