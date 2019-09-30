#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

const int mx = 1e5+5;
ll h[mx];
pll position(ll s, int i)
{
    ll direction = s/h[i];
    ll hight = s%h[i];
    if(direction & 1)hight = h[i]-hight;
    return {direction, hight};
}
ll f1(ll p1, ll p2, int i)
{
    return min(p1,p2);
}
ll f2(ll p1, ll p2, int i)
{
    return max(p1,h[i+1]-p2);
}
ll f3(ll p1, ll p2, int i)
{
    ll p = (p2-p1+1)/2;
    return (p1+p>h[i]) ? (p2-h[i]) : p;
}
ll f4(ll p1, ll p2, int i)
{
    return min(h[i]-p1, h[i+1]-p2);
}
int main()
{
    int tc,t=1;
    cin >> tc;
    while(tc--)
    {
        int n; cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> h[i];
        }
        ll s = 0;
        for(int i=1;i<n;i++)
        {
            while(true)
            {
                pll pr = position(s,i);
                ll d1 = pr.first, p1 = pr.second;
                pr = position(s,i+1);
                ll d2 = pr.first, p2 = pr.second;

                if(p1>=p2){s++;break;}
                if((d1&1) && (d2&1))s+=f1(p1,p2,i);
                else if(d1&1)s+=f2(p1,p2,i);
                else if(d2&1)s+=f3(p1,p2,i);
                else s+=f4(p1,p2,i);
            }
        }
        cout << "Case " << t++ << ": " << s << endl;
    }
    return 0;
}
