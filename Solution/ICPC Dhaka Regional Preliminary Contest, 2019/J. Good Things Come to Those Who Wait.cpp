#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main()
{
    int tc,t=1;
    cin >> tc;
    while(tc--)
    {
		ll n; cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		sort(a,a+n);
		ll p = a[0]*a[n-1];
        cout << "Case " << t++ << ": " << p << endl;
    }
    return 0;
}
