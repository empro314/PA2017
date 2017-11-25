#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include "message.h"
#include "dzialka.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INS = 100;

void updateMin(deque<pii> &D, int time, int interv, int val)
{
    while(!D.empty() && D.front().second < time-interv)
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

int fnd(int x, int y, int n, int m)
{
    vector<int> above;
    deque<pii> minim;
    above.resize(m);

    int res = 0;

    for(int i=0; i<n; i++)
    {
        int behindMe = 0;
        minim.clear();
        for(int j=0; j<m; j++)
        {
            if(IsUsableCell(i, j) )
            {
                behindMe++;
                above[j]++;
            }
            else
            {
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
    }

    return res;
}

int main()
{
    //ios_base::sync_with_stdio(0);

    //cout << "dupa\n";
    //int n = GetFieldHeight();
    //int m = GetFieldWidth();

    
    int instance = MyNodeId();
    /*
    //<p, k)

    int p = (n / 100) * instance;
    int k = (n / 100) * (instance + 1);

    int res = 0;

    if(instance == INS)
    {
        k = n;
    }

    for(int i=p; i<=k; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fnd(j, i, n, m);
        }
    }

    if(instance != 0)
    {
        PutInt(0, res);
        Send(0);
    }
    else
    {
        for(int i=1; i<100; i++)
        {
            Receive(i);
            res += GetInt(i);
        }

        cout << res << "\n";
    }
    */

    return 0;
}