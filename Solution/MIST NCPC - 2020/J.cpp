#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll fr[(1<<20)+2],a[(1<<20)+2],b[(1<<20)+2],ar[100004];
vector<ll>v[(1<<20)+2];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int tc,t=1; cin >> tc;
    while(tc--)
    {
        int n,N; cin >> n >> N;
        memset(fr,0,sizeof fr);
        memset(b,0,sizeof b);
        for(int i=1; i<=n ;i++)
        {
            ll p; cin >> s >> p;
            ar[i] = p;
            if(s[0]=='!')
            {
                ll q = 0;
                for(int i=1; i<s.size(); i++)
                {
                    int c = s[i]-'A';
                    q|=(1<<c);
                }
                a[i] = (1<<N)-1-q;
                fr[(1<<N)-1-q]++;
                b[(1<<N)-1-q]++;
                v[a[i]].push_back(p);
            }
            else
            {
                ll q = (1<<N)-1;
                for(int i=1; i<s.size(); i++)
                {
                    int c = s[i]-'A';
                    q^=(1<<c);
                }
                a[i] = (1<<N)-1-q;
                fr[(1<<N)-1-q]++;
                b[(1<<N)-1-q]++;
                v[a[i]].push_back(p);
            }
        }
        for(int i=0; i<N; i++)
        {
            for(int mask=0; mask<(1<<N); mask++)
            {
                if(mask & (1<<i))
                {
                    fr[mask]+=fr[mask^(1<<i)];
                }
            }
        }
        for(int i=0; i<(1<<N); i++)
        {
            sort(v[i].begin(), v[i].end());
        }
        cout << "Case " << t++ << ":";
        for(int i=1; i<=n; i++)
        {
            ll p = fr[a[i]] - b[a[i]] + 1;
            p += lower_bound(v[a[i]].begin(), v[a[i]].end(), ar[i])-v[a[i]].begin();
            cout << " " << p;
        }
        cout << "\n";
        for(int i=0; i<(1<<N); i++)v[i].clear();
    }
    return 0;
}
