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

    // Indeksy użytych monet dla danej wagi
    vector<int> DP(F + 1, -1);

    // Znajdowanie minimum
    for (int f = 1; f <= F; f++)
    {
        for (int i = 1; i <= C; i++)
        {
            if (f >= w[i] && Result[f - w[i]] + p[i] < Result[f] && Result[f - w[i]] != INT_MAX)
            {
                Result[f] = Result[f - w[i]] + p[i];
                DP[f] = i;
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

        vector<int> coin_counts(C + 1, 0);
        int current_weight = F;
        while (current_weight > 0)
        {
            int coin_index = DP[current_weight];
            coin_counts[coin_index]++;
            current_weight -= w[coin_index];
        }

        for (int i = 1; i <= C; i++)
        {
            cout << coin_counts[i] << " ";
        }
        cout << endl;
    }

    // Znajdowanie maximum
    for (int f = 1; f <= F; f++)
    {
        for (int i = 1; i <= C; i++)
        {
            if (f >= w[i] && Result[f - w[i]] + p[i] > Result[f])
            {
                Result[f] = Result[f - w[i]] + p[i];
                DP[f] = i;
            }
        }
    }

    // Output max
    cout << Result[F] << endl;

    vector<int> coin_counts(C + 1, 0);
    int current_weight = F;
    while (current_weight > 0)
    {
        int coin_index = DP[current_weight];
        coin_counts[coin_index]++;
        current_weight -= w[coin_index];
    }

    for (int i = 1; i <= C; i++)
    {
        cout << coin_counts[i] << " ";
    }
    cout << endl;

    return 0;
}
