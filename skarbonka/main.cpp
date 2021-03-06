#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 10e6;

int dodawanie[N+1];

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    while(n--)
    {
        int a;
        cin >> a;
        dodawanie[a]++;
    }

    for(int i=0; i<N; i++)
    {
        dodawanie[i+1] += dodawanie[i]/2;
        dodawanie[i] %= 2;
    }

    for(int i=N; i>=0; i--)
    {
        if(dodawanie[i] != 0)
        {
            cout << i << "\n";
            return 0;
        }
    }





    return 0;
}