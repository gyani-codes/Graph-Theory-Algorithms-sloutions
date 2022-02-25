bool helper(string &a,string &b)
{
	int n = a.size();
	int c = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])c++;
	}
	return c==1;
}
int ladderLength(string beginWord, string endWord, vector<string> wordList) {
			
			int n = wordList.size();
			queue<int> q;
			vector<bool> vis(n,false);
			q.push(-1);
			int step = 1;
			while(!q.empty())
			{
				int sz = q.size();
				while(sz--)
				{
					int a = q.top();
					string s = a==-1 ? beginWord : wordList[a];
					if(s==endWord)return step;
					for(int i=0;i<n;i++)
					{
						if(!vis[i]and helper(s,wordList[i]))
						{
							q.push(i);
							vis[i]=true;
						}
					}
				}
				step+=1;
			}   
			return 0; 
}