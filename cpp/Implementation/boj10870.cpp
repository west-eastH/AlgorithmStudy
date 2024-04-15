#include <iostream>
using namespace std;

int t[25];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    t[0] = 0;
    t[1] = 1;
    for (int i = 2; i < n + 1; i++)
        t[i] = t[i - 2] + t[i - 1];
    cout << t[n];
    return 0;
}