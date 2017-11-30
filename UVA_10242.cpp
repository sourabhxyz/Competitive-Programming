#include<bits/stdc++.h>

using namespace std;

map<pair<double, double>, int> data;

#define eps 1e-6

int main()
{
	cout << fixed << setprecision(3);
	double x1, y1, x2, y2, x3, y3, x4, y4;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		data.clear();
		data[make_pair(x1, y1)]++;
		data[make_pair(x2, y2)]++;
		data[make_pair(x3, y3)]++;
		data[make_pair(x4, y4)]++;
		double x = 0, y = 0;
		for(map<pair<double, double>, int>::iterator it = data.begin(); it != data.end(); it++)
		{
			int cnt = it->second;
			if(cnt > 1) 
			{
				x -= (it -> first).first;
				y -= (it -> first).second;	
			}
			else
			{
				x += (it -> first).first;
				y += (it -> first).second;	
			}
		}
		cout << x;
		cout << " " << y << "\n";
	}
}
