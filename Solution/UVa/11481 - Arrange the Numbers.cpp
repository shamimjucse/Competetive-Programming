#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007LL
using namespace std;
ll fact[1002],ncr[1002][1002];
void factorial(int n = 1000)
{
    fact[0]=1;
    for(int i=1;i<=n;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}
void combination(int n = 1000)
{
    for(int i=0;i<=n;i++)
    {
        ncr[i][0]=ncr[i][i]=1;
        for(int j=0;j<i;j++)
        {
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }
}
int main()
{
    factorial();
    combination();
    int i,j,m,n,k,tc,t=1;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> k;
        ll ans = 0;
        for(i=0;i<=m-k;i++)
        {
            if(i&1)ans=(ans-ncr[m-k][i]*fact[n-k-i])%mod;
            else   ans=(ans+ncr[m-k][i]*fact[n-k-i])%mod;
        }
        ans = ((ans*ncr[m][k])%mod+mod)%mod;
        cout<<"Case "<<t++<<": "<<ans<<endl;
    }
    return 0;
}
