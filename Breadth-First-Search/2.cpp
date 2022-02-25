#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v = {1,4,3,2,9,8,7,6,5,4};
	sort(v.begin()+1,v.begin()+4);
	for(int i:v)
	{
		cout<<i<<endl;
	}
}