#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

void debg(ll a)
{
    for(ll i=63; i >= 0; i--)
    {
        cout << (bool)(a & ((ll)1 << i) );
    }

    cout << " " << a << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    ll suma = 0;

    while(n--)
    {
        ll a;
        cin >> a;
        suma += ((ll)1 << a);
    }

    for(ll i=63; i >= 0; i--)
    {
        if((suma & ((ll)1 << i) )!= 0)
        {
            cout << i << "\n";
            return 0;
        }
    }   


    return 0;
}