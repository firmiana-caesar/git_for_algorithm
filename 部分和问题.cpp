/////////////////////////////////////////////////////////////////
//from:挑战程序设计竞赛p30
//description：给定整数a1、a2、...、an，判断是否可以从中选出若干
//数，使他们的和恰好为k				      
//input：1<=n<=20
//	 -10e8<=ai<=10e8
//	 -10e8<=k<=10e8		       
//output:yes/no        
//sample input：n=4
//		a={1,2,4,7}
//		k = 13					     	
//sample output：yes
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

const int MAX_N=20;//定义整个数组长度为最大长度
int a[MAX_N]={0};  //定义数组
int n;		   //输入数字的数量
int k;		   //要求的总和

int main()
{	
	//input your code from here
	cin >> n;			//输入数组长度
	for (int i = 0; i < n; i++)	//输入数组内容
		cin >> a[i];
	cin >> k;			//输入要求的总和
	void solve();			//解决函数
	bool dfs(int i, int sum);	//深度优先搜索

	solve();
	return 0;
}

//已经从前i项得到了和sum，对于i项之后的进行分支
bool dfs(int i, int sum)
{
	//如果前n项计算过了，返回sum是否与k相等
	if (i == n)return sum == k;
	//不加上i的情况		
	if (dfs(i+1,sum)) return true;
	//加上i的情况
	if (dfs(i+1,sum+a[i]))return true;
	//无论是否加上a[i]都不能凑成k就返回false
	return false;
}

void solve()
{
	if (dfs(0,0))
	cout << "Yes\n";
	else
	cout << "No\n";
}

//解释：将每一个递归的结果列出来，会有2^（n+1）个结果。
//从第i个开始计算，如果当前已经满足sum=k，自然就返回true
//从第i个开始，第i+1个会面临加上去或者不加上的情景，由此
//形成一个树状的、有2^（n+1）个叶节点对应各种递归情况的图
//每执行完一种情况的递归，就能够判断是否存在满足sum=k的情形
//所以采用dfs的形式来解题
