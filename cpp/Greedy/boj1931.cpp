#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int>p[100005];
int n;
int cnt = 0;
int start = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (size_t i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first;
	sort(p, p + n);
	for (size_t i = 0; i < n; i++)
	{
		if (start > p[i].second)
			continue;
		cnt++;
		start = p[i].first;
	}
	cout << cnt;
    return 0;
}