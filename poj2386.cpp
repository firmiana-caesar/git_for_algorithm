/////////////////////////////////////////////////////////////////
//description：有一个大小为N×M的院子，雨后积起了水。八连通的给水被认
//为是连接在一起的。请求出院子里总共有多少水洼from：POJ 2386				      
//input：N，M，W代表积水，.代表没有积水		       
//output:积水的数量        
//sample input：N=10，M=12
//		W........WW.
//		.WWW.....WWW
//		....WW...WW.
//		.........WW.
//		.........W..
//		..W......W..
//		.W.W.....WW.
//		W.W.W.....W.
//		.W.W......W.
//		..W.......W.					     	
//sample output：3
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
/*
const int MAX_N = 100;
//n是行号，m是列号
int N,M;
//定义存储积水信息的字符数组
char field[MAX_N+1][MAX_N+1];
int cnt = 0;

int main()
{	
	//input your code from here
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		cin >> field[i][j];
	//调用的解决函数
	void solve();
	//调用的深度优先搜索函数
	void dfs(int n, int m, char field[][MAX_N+1]);
	
	solve();	
	return 0;
}

void dfs(int n, int m, char field[][MAX_N+1])
{
	if (n == MAX_N && m == MAX_N)
		return;
	if (field[m][n] == '.')
		cnt = cnt;
	else if (field[m-1][n-1]=='W'||field[m][n-1]=='W'||field[m+1][n-1]=='W'||field[m-1][n-1]=='W'||field[m+1][n-1]=='W'||field[m+1][n-1]=='W'||field[m+1][n]=='W'||field[m+1][n+1]=='W')
		{
			cnt++;
			dfs(m+1,n,field);
			dfs(m+1,n+1,field);
			dfs(m,n+1,field);	
		}
}

void solve()
{
	dfs(0,0,field);
	cout << cnt;
}
*/
const int MAX_N = 100;
const int MAX_M = 100;
int N,M;
char field[MAX_N][MAX_M];

void dfs(int x, int y)
{
	field[x][y] = '.';
	
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1; dy <= 1; dy++){
		int nx = x + dx, ny = y + dy;
		if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')//这里原先写的是nx < M以及ny < N，现在已经改过来了
			dfs(nx, ny);
		}
	}
	return ;
}

void solve()
{
	int res = 0;
	for (int i = 0; i < N; i++)
	{	
		for (int j = 0; j < M; j++)
		{
			if(field[i][j] == 'W')
			{
				dfs(i,j);
				res++;
			}
		}
	}
	cout << res;
}

int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			cin >> field[i][j];
		}
	void solve();
	void dfs(int x, int y);
	solve();
	return 0;
}
//解释：按照题解，这题的思路是，从任意的W开始，用.来代替，进行一次dfs之后和这个任意选择的开始的W联通的所有W就被
//替换成.，这时候就会退出这一次dfs。按照这个思路，遍历了所有的点，如果有X块连通域，就会进行X次dfs。原先的做法存
//在缺陷，原先的思路是每调用一次这个dfs，先判断是不是到了边界。第二个if，如果第一个起始点就是.，那么这个dfs已经
//废了，就算进入了第三个if，每调用一次dfs，如果这个连通域的大小到达一定的程度，那么就会变成计算W的熟练而不是连通域
//的数量。
