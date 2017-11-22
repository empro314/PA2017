#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll tabSiz = 2097153;
const ll adder = 1048576;
const ll maxD = 1000000+1;

struct tree
{
    vector<pii> T;

    tree()
    {
        T.resize(tabSiz);
    }

    void insert(ll i, ll p, ll k, ll x, ll y, ll ulg)
    {
        bool done = false;

        if(p == x && k == y)
        {
            T[i].first += ulg;
            T[i].second++;
            //cout << "drzewo tutaj: " << i << "! "<< x << " " << y << "\n";
            return;
        }

        ll m = (p + k) / 2;

        if(x <= m)
        {
            insert(2*i, p, m, x, min(y, m), ulg);
        }
        if(y > m)
        {
            insert(2*i+1, m+1, k, max(m+1, x), y, ulg);
        }
    }

    ll getCost(ll i)
    {
        ll ind = i + adder;
        ll res = 0;

        while(ind)
        {
            //cout << ind << " ";
            //cout << "(" << T[ind].first << " " << T[ind].second << ") ";

            /*if(T[ind].second != 0)
            {
                cout << ind << "! ";
            } */
            res += (i * T[ind].second) - T[ind].first;
            ind /= 2; 
        }
        
        return res;
    } 
};

tree Costs;

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

    for(ll i=1; i<clients.size(); i++)
    {
        //cout << clients[i] << " ";
        ll differ = clients[i] - clients[i-1];

        if(differ <= maxD)
        {
            Costs.insert(1, 0, adder-1, differ+1, maxD, differ);
        }
    }

    for(ll i=0; i<m; i++)
    {
        ll d;
        cin >> d;

        //cout << "d: " << d << "\n";

        cout << Costs.getCost(d) << "\n"; 
    }


    return 0;
}