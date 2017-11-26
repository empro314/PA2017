#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

char board[3001][3001];
int czysta[3001][3001];

int res = 0;

bool spojna(int n)
{
    int addX[4] = {0, -1, 1, 0};
    int addY[4] = {-1, 0, 0, 1};
    bool marked = false;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            czysta[i][j] = 0;
        }
    }

    queue<pii> Q;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j] == '#' && czysta[i][j] == 0)
            {
                if(marked)
                {
                    return false;
                }

                Q.push(pii(i, j) );

                while(!Q.empty())
                {
                    pii odb = Q.front();
                    Q.pop();

                    if(czysta[odb.first][odb.second])
                        continue;

                    czysta[odb.first][odb.second] = 1;

                    for(int k=0; k<4; k++)
                    {
                        if(!czysta[odb.first+addX[k]][odb.second+addY[k]])
                            Q.push(pii(odb.first+addX[k], odb.second+addY[k]) );
                    }
                }
                marked = true;
            }
        }
    }

    return true;
}

void chk(int left, int x, int y, int n)
{
    if(board[x][y] == '#')
        return;

    board[x][y] = '#';

    if(left == 1)
    {
        if(spojna(n) )
            res++;
    }

    for(int i=x+1; i<n; i++)
    {
        chk(left-1, i, y, n);
    }

    for(int i=y+1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            chk(left-1, j, i, n);
        }
    }

    

    board[x][y] = '.';
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> board[i][j];
        }
    }

    chk(k, 0, 0, n);

    cout << res << "\n";




    return 0;
}