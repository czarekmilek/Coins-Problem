#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    // F, C => masa i liczba monet
    int F, C;
    cin >> F >> C;

    // p, w => tablice z nominałami i wagami monet
    vector<int> p(C + 1), w(C + 1);
    for (int i = 1; i <= C; i++)
    {
        cin >> p[i] >> w[i];
    }

    vector<int> Result(F + 1, INT_MAX);
    
    Result[0] = 0;

    vector<vector<int>> DP(F + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= C; i++)
    {
        for (int f = w[i]; f <= F; f++)
        {
            if (Result[f - w[i]] + p[i] < Result[f] && Result[f - w[i]] != INT_MAX)
            {
                Result[f] = Result[f - w[i]] + p[i];
                DP[f] = DP[f - w[i]];
                DP[f][i]++;
            }
        }
    }

    // Output min
    if (Result[F] == INT_MAX)
    {
        cout << "NIE" << endl;
        return 0; // Nie trzeba patrzeć dalej, koniec
    }

    else 
    {
        cout << "TAK" << endl;
        cout << Result[F] << endl;
        for (int i = 1; i <= C; i++)
        {
            cout << DP[F][i] << " ";
        }
        cout << endl;
    }
    

    for (int i = 1; i <= C; i++)
    {
        for (int f = w[i]; f <= F; f++)
        {
            if (Result[f - w[i]] + p[i] > Result[f])
            {
                Result[f] = Result[f - w[i]] + p[i];
                DP[f] = DP[f - w[i]];
                DP[f][i]++;
            }
        }
    }

    // Output max
    cout << Result[F] << endl;
    for (int i = 1; i <= C; i++)
    {
        cout << DP[F][i] << " ";
    }
    cout << endl;

    return 0;
}
