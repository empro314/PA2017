#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);

    vector<ll> clients;

    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;
        clients.push_back(a);
    }
    clients.push_back(0);
    sort(clients.begin(), clients.end());

    vector<ll> differs;

    for(ll i=1; i<clients.size(); i++)
    {
        ll differ = clients[i] - clients[i-1];

        differs.push_back(differ);
    }

    for(ll i=0; i<m; i++)
    {
        ll d;
        cin >> d;

        ll res = 0;
        ll akt = d;

        for(ll i=0; i<differs.size(); i++)
        {
            akt = max(akt - differs[i], (ll)0);
            res += akt;
            akt += d;
        }

        cout << res << "\n"; 
    }


    return 0;
}