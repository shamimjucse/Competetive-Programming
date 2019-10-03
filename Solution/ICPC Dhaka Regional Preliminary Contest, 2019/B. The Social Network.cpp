#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>order_set;

order_set st[100005];
int par[100005];
int dsu(int u)
{
    return par[u]==u ? u : par[u]= dsu(par[u]);
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc,t=1;
    cin >> tc;
    while(tc--)
    {
        int n,qry;
        cin >> n >> qry;
        for(int i=1; i<=n; i++)par[i]= i, st[i].clear();
        cout << "Case " << t++ << ":\n";
        while(qry--)
        {
            int type; cin >> type;
            if(type==0)
            {
                int a,b; cin >> a >> b;
                int p= dsu(a);
                int q= dsu(b);
                if(p!=q)
                {
                    if(st[p].size()>st[q].size())
                    {
                        par[q]= p;
                        for(auto pr : st[q])
                        {
                            st[p].insert(pr);
                        }
                    }
                    else
                    {
                        par[p]= q;
                        for(auto pr : st[p])
                        {
                            st[q].insert(pr);
                        }
                    }
                }
            }
            else if(type==1)
            {
                int a,b; cin >> a >> b;
                int p= dsu(a);
                st[p].insert(b);
            }
            else
            {
                int a,l,r; cin >> a >> l >> r;
                int p = dsu(a);
                int ans = st[p].order_of_key(r+1) - st[p].order_of_key(l);
                cout <<ans << "\n";
            }
        }
    }
    return 0;
}
