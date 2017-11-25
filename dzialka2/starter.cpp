#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include "message.h"
#include "dzialka.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll INS = 100;

void updateMin(deque<pii> &D, ll time, ll llerv, ll val)
{
    while(!D.empty() && D.front().second <= time-llerv)
    {
        D.pop_front();
    }

    while(!D.empty() && D.back().first > val)
    {
        D.pop_back();
    }

    D.push_back(pii(val, time) );

    return;
}

ll fnd(ll x, ll y, ll n, ll m)
{
    vector<ll> above;
    deque<pii> minim;
    above.resize(m);



    ll res = 0;
    //cout << n << m;
    for(ll i=0; i<n; i++)
    {
        ll behindMe = 0;
        minim.clear();
        for(ll j=0; j<m; j++)
        {
            if(IsUsableCell(i, j) )
            {
                behindMe++;
                above[j]++;
                //cout << 1 << " ";
            }
            else
            {
                //cout << 0 << " ";
                behindMe = 0;
                above[j] = 0;
                // wrzuc na heap 
            }

            updateMin(minim, j, x, above[j]);

            if(behindMe >= x && minim.front().first >= y)
            {
                res++;
            }
        }
        //cout << "\n";
    }

    //cout << "\n\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    ll n = GetFieldHeight();
    ll m = GetFieldWidth();

    
    //ll instance = MyNodeId();
    
    //<p, k)

    ll p = 1; //(n / 100) * instance;
    ll k = n;//(n / 100) * (instance + 1);

    ll res = 0;

    /*
    if(instance == INS)
    {
        k = n;
    }*/

    for(ll i=p; i<=k; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            //cout << j << " " << i << "\n";
            res += fnd(j, i, n, m);
        }
    }

    /*if(instance != 0)
    {
        Putll(0, res);
        Send(0);
    }
    else
    for(ll i=1; i<100; i++)
    {
        Receive(i);
        res += Getll(i);
    }
    */

    if(MyNodeId() == 0)
    {
        cout << res << "\n";
    }
    

    return 0;
}