#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, int> > flowers;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		flowers.push_back(make_pair(sm * 100 + sd, em * 100 + ed));
	}

	int t = 301;
	int ans = 0;
	while (t < 1201)
	{
		int next_t = t;
		for (int i = 0; i < n; i++)
		{
			if (flowers[i].X <= t && flowers[i].Y > next_t)
				next_t = flowers[i].Y;
		}
		if (next_t == t)
		{
			cout << 0;
			return 0;
		}
		t = next_t;
		ans++;
	}
	cout << ans;
	return 0;
}