#include <iostream>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct node
{
	int row;
	int column;
};
node mat[128];
stack <node> st;
bool check(node a, node b)
{
	return a.column == b.row;
}
int main()
{
	int n, row, column, ans;
	bool is_error;
	char c;
	string s;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> c >> row >> column;
		mat[c].row = row;
		mat[c].column = column;
	}
	while (cin >> s)
	{		
		while (!st.empty()) st.pop();
		is_error = false;
		ans = 0;	
		for (int i=0; i<s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				st.push(mat[s[i]]);
			} else if (s[i] == ')')
			{
				if (st.size() > 1)
				{
					cout<<st.size()<<"\n";
					node x, y;
					y = st.top();
					st.pop();
					x = st.top();
					st.pop();
//					cout << x.column << " " << y.row << "\n";
					if (check(x, y))
					{
						ans += x.row * x.column * y.column;
						node res;
						res = {x.row, y.column};
						st.push(res);
					} else
					{
						is_error = true;
						break;
					}	
				} 
			}
		}
		
		if (is_error)
		{
			cout << "error\n";
		} else
		{
			cout << ans << "\n";
		}
	}
	
	return 0;
}
