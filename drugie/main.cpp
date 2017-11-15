#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

bool isPrime(ll n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool check(string &s)
{
    if(s.size() < 2)
        return false;

    for(int i=1; i<s.size(); i++)
    {
        ll n = 0, k=0;
        if(s[i] == '0')
        {
            continue;
        }

        for(int j=0; j<i; j++)
        {
            n *= 10;
            n += s[j] - '0';
        }

        for(int j=i; j<s.size(); j++)
        {
            k *= 10;
            k += s[j] - '0';
        }

        //cout << n << " " << k << "\n";

        if(isPrime(n) && isPrime(k) )
            return true;
    }

    return false;
}


int main()
{
    //ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);
    
    //cout << "here\n";

    if(check(s))
    {
        cout << "TAK\n";
    }
    else
    {
        cout << "NIE\n";
    }



    return 0;
}