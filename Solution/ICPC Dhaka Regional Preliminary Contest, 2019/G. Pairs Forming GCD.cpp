#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx = 10000005;

ll phi[mx];
ll sm[mx];
void computeTotientPhi(int N)
{
    phi[1] = 1 ;
    for(int i=2; i<=N; i++)
    {
        if(phi[i]==0)
        {
            phi[i] = i-1 ;
            for(int j=i+i; j<=N; j+=i)
            {
                if(phi[j]==0)
                    phi[j] = j ;
                phi[j] = phi[j] - phi[j]/i ;
            }
        }
    }
    for(int i=1; i<=N; i++)
        sm[i]=sm[i-1]+phi[i];
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    computeTotientPhi(10000002);
    int tc,t=1;
    cin >> tc;
    while(tc--)
    {
        ll n,k;
        cin >> n >> k;
        ll lo = 1, hi = n, mid, ans = -1;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(sm[n/mid]>=k)
            {
                ans = max(ans,mid);
                lo = mid+1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << "Case " << t++ << ": " << ans << "\n";
    }
    return 0;
}
