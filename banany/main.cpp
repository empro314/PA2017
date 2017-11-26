#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll maxN = 100000;
const ll INF = 9223372036854775807;

ll prof[maxN+1];
vector<ll> E[maxN+1];
vector<ll> C[maxN+1];

pii dfs(ll v, ll pred, ll myCosts, ll a, ll b, ll c, bool starter)
{
    pii res; 
    if(!starter)
    {
        res = pii(prof[v]-myCosts, -v);
    }
    else
    {
        res = pii(INF, v);
    }

    for(ll i=0; i<E[v].size(); i++)
    {
        ll nei = E[v][i];

        if(nei == b && v == a)
        {
            C[v][i] = c;
        }

        if(nei == a && v == b)
        {
            C[v][i] = c;
        }
        if(nei == pred)
        {
            continue;
        }
        res = max(res, dfs(nei, v, myCosts + C[v][i], a, b, c, false) );
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    for(ll i=1; i<=n; i++)
    {
        cin >> prof[i];
    }
    
    ll a, b, c;
    for(ll i=0; i<n-1; i++)
    {
       
        cin >> a >> b >> c;

        E[a].push_back(b);
        C[a].push_back(c);

        E[b].push_back(a);
        C[b].push_back(c);
    }

    ll orig = 1;

    while(q--)
    {
        ll cmd;
        cin >> cmd;

        if(cmd == 1)
        {
            ll v, d;
            cin >> v >> d;
            prof[v] = d;
            a = b = c = 0;
        }
        else
        {
            cin >> a >> b >> c;
        }

        pii getter = dfs(orig, 0, 0, a, b, c, true);

        orig = -getter.second;
        cout << orig << "n"; //<< getter.first << "\n";
    }




    return 0;
}