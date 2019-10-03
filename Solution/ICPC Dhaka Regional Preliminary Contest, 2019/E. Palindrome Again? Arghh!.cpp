#include<bits/stdc++.h>
using namespace std;
int a[6][6],dp[(1<<11)+2],fr[6],N;
vector<pair<int,int>>vc;
int call(int mask)
{
    if(mask==(1<<N)-1)return 0;
    int &ret = dp[mask];
    if(~ret)return ret;
    ret = 1e9;

    for(int i=0;i<N;i++)
    {
        if((mask&(1<<i))==0)
        {
            queue<pair<int,int>>qu;
            qu.push({vc[i].first, vc[i].second});
            qu.push({0,mask|(1<<i)});
            while(!qu.empty())
            {
                int u = qu.front().first;
                int v = qu.front().second;
                qu.pop();
                int cost = qu.front().first;
                int msk = qu.front().second;
                qu.pop();

                for(int j=0; j<N; j++)
                {
                    if((msk&(1<<j))==0)
                    {
                        if(u==vc[j].first && v==vc[j].second)
                        {
                            ret = min(ret, cost+1+call(msk|(1<<j)));
                            continue;
                        }
                        int p,q;
                        if(u==vc[j].first)p = v, q = vc[j].second;
                        else if(u==vc[j].second)p = v, q = vc[j].first;
                        else if(v==vc[j].first)p = u, q = vc[j].second;
                        else if(v==vc[j].second)p = u, q = vc[j].first;
                        else continue;

                        if(p>q)swap(p,q);
                        qu.push({p,q});
                        qu.push({cost+1, msk|(1<<j)});
                    }
                }
            }
        }
    }
    return ret;
}
int main()
{
    int tc,t=1;
    cin >> tc;
    while(tc--)
    {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        memset(fr,0,sizeof fr);
        for(int i=0; i<s.size(); i++)
        {
            fr[s[i]-'a']++;
        }
        int odd = 0;
        for(int i=0;i<k;i++)
        {
            if(fr[i]&1)odd++;
        }
        if(odd>1)
        {
            cout << "Case " << t++ << ": " << -1 << "\n";
            continue;
        }
        if(odd == 1)
        {
            for(int i=0; i<k; i++)
            {
                if(fr[i]&1)
                {
                    if(s[n/2]-'a' != i)
                    {
                        string x = s.substr(0,n/2);
                        x+=(i+'a');
                        s = x+ s.substr(n/2);
                        n++;
                    }
                }
            }
        }
        memset(a,0,sizeof a);
        for(int i=0,j=n-1; i<n/2; i++,j--)
        {
            if(s[i]==s[j])continue;
            int p = s[i]-'a';
            int q = s[j]-'a';
            if(p>q)swap(p,q);
            a[p][q]++;
        }
        int ans = 0;
        vc.clear();
        for(int i=0; i<k; i++)
        {
            for(int j=i+1; j<k; j++)
            {
                ans+=a[i][j]/2;
                if(a[i][j] & 1)
                {
                    vc.push_back({i,j});
                }
            }
        }
        N = vc.size();
        memset(dp,-1,sizeof dp);
        ans+=call(0);
        cout << "Case " << t++ << ": " << ans << "\n";
    }
    return 0;
}
