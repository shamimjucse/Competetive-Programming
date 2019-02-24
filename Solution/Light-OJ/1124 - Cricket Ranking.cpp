#include<bits/stdc++.h>
#define ll long long
#define mod 100000007LL
using namespace std;
ll a[25],fact[2000025];
ll bigMod(ll a, ll b, ll m)
{
    ll ans = 1;
    a = a%m;
    while(b>0)
    {
        if(b&1)ans=(ans*a)%m;
        b/=2,a=(a*a)%m;
    }
    return ans;
}
ll ncr(ll n, ll r)
{
    if(n<0 || n<r)return 0;
    ll p = fact[n];
    p=(p*bigMod(fact[r],mod-2,mod))%mod;
    p=(p*bigMod(fact[n-r],mod-2,mod))%mod;
    return p;
}
int main()
{
    ll i,j,p,q,n,k,tc,t=1;
    fact[0]=1;
    for(i=1;i<=2000020;i++)
        fact[i]=(fact[i-1]*i)%mod;
    cin >> tc;
    while(tc--)
    {
        cin >> k >> n;
        for(i=0;i<k;i++)
        {
            cin >> p >> q;
            a[i]=q-p;
            n-=p;
        }
        ll sm = 0;
        for(i=0;i<(1<<k);i++)
        {
            p=0, q=0;
            for(j=0;j<k;j++)
            {
                if(i&(1<<j))
                {
                    p+=a[j]+1;
                    q++;
                }
            }
            if(q&1)sm=(sm-ncr(n-p+k-1,k-1)+mod)%mod;
            else sm=(sm+ncr(n-p+k-1,k-1));
        }
        sm%=mod;
        cout<<"Case "<<t++<<": "<<sm<<endl;
    }
    return 0;
}
