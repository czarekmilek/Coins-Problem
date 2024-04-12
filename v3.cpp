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

    vector<int> Min(F + 1, INT_MAX), Max(F + 1);
    
    Min[0] = 0;

    vector<vector<int>> minDP(F + 1, vector<int>(C + 1, 0));
    vector<vector<int>> maxDP(F + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= C; i++)
    {
        for (int f = w[i]; f <= F; f++)
        {
            if (Min[f - w[i]] + p[i] < Min[f] && Min[f - w[i]] != INT_MAX)
            {
                Min[f] = Min[f - w[i]] + p[i];
                minDP[f] = minDP[f - w[i]];
                minDP[f][i]++;
            }
        }
    }

    // Output min
    if (Min[F] == INT_MAX)
    {
        cout << "NIE" << endl;
        return 0; // Nie trzeba patrzeć dalej, koniec
    }

    else 
    {
        cout << "TAK" << endl;
        cout << Min[F] << endl;
        for (int i = 1; i <= C; i++)
        {
            cout << minDP[F][i] << " ";
        }
        cout << endl;
    }
    

    for (int i = 1; i <= C; i++)
    {
        for (int f = w[i]; f <= F; f++)
        {
            if (Max[f - w[i]] + p[i] > Max[f])
            {
                Max[f] = Max[f - w[i]] + p[i];
                maxDP[f] = maxDP[f - w[i]];
                maxDP[f][i]++;
            }
        }
    }

    // Output max
    cout << Max[F] << endl;
    for (int i = 1; i <= C; i++)
    {
        cout << maxDP[F][i] << " ";
    }
    cout << endl;

    return 0;
}
