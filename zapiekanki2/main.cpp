#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll tabSiz = 2097153;
const ll adder = 1048676;
const ll maxD = 1000000;

struct tree
{
    vector<pii> T;

    tree()
    {
        T.resize(tabSiz);
    }

    void insert(int i, int p, int k, int x, int y, int ulg)
    {
        bool done = false;

        if(p == x && k == y)
        {
            T[i].first += ulg;
            T[i].second++;
            return;
        }

        int m = (p + k) / 2;

        if(x <= m)
        {
            insert(2*i, p, m, x, min(y, m), ulg);
        }
        if(y > m)
        {
            insert(2*i+1, m+1, k, max(m+1, x), y, ulg);
        }

    }

    int getCost(int i)
    {
        int ind = i + adder;
        int res = 0;

        while(ind)
        {
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

    vector<int> clients;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        clients.push_back(a);
    }
    clients.push_back(0);
    sort(clients.begin(), clients.end());

    for(int i=1; i<clients.size(); i++)
    {
        int differ = clients[i] - clients[i-1];

        if(differ <= maxD)
        {
            Costs.insert(1, 0, adder-1, differ+1, maxD, differ);
        }
    }

    for(int i=0; i<m; i++)
    {
        int d;
        cin >> d;

        cout << Costs.getCost(d) << "\n"; 
    }


    return 0;
}