#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9;

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

    vector<int> Min(F + 1, inf), Max(F + 1);

    Min[0] = 0;

    for (int i = 1; i <= C; i++)
    {
        for (int f = w[i]; f <= F; f++)
        {
            Min[f] = min(Min[f], Min[f - w[i]] + p[i]);
            Max[f] = max(Max[f], Max[f - w[i]] + p[i]);
        }
    }

    int Pmin = Min[F], Pmax = Max[F];

    // Output
    if (Pmin == inf)
    {
        cout << "NIE" << endl;
    }
    else
    {
        cout << "TAK" << endl;
        cout << Pmin << endl;
        cout << Pmax << endl;
    }

    return 0;
}

