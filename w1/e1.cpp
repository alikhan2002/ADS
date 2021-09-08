#include<iostream>
#include<queue>
using namespace std;
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	queue<int> p1, p2;
	for(int i=0;i<5;i++)
	{
		int t;
		cin>>t;
		p1.push(t);
	}
	for(int i=0;i<5;i++)
	{
		int t;
		cin>>t;
		p2.push(t);
	}
	int cnt = 0;
	while(!p1.empty() and !p2.empty())
	{
		int t1 = p1.front();
		p1.pop();
		int t2 = p2.front();
		p2.pop();
		if(t1==0 and t2 == 9)
		{
			p1.push(t1);
			p1.push(t2);
		}
		else if(t1==9 and t2 == 0)
		{
			p2.push(t1);
			p2.push(t2);
		}
		else if(t1>t2) 
		{
			p1.push(t1);
			p1.push(t2);
		}
		else if(t1<t2) 
		{
			p2.push(t1);
			p2.push(t2);
		}
		cnt++;
		if(cnt==1000000) 
		{
			cout<<"botva";
			return 0;
		}
		// cout<<t1<<" "<<t2<<" -"<<cnt<<endl;
	}
	if(p1.empty())
	{
		cout<<"second "<<cnt;
	}
	else cout<<"first "<<cnt;
	return 0;
}