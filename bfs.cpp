/////////////////////////////////////////////////////////////////
//description:给定一个大小为N×M的迷宫。迷宫有通道和墙壁组成，每一步
//可以向邻接的上下左右四格的通道移动。请求出从起点到终点所需的最小
//步数。请注意，本题假定从起点一定可以移动到终点			      
//input：N，M，迷宫示意图		       
//output:最小的步数        
//sample input：N = 10,M = 10(S是起点，G是终点,#是墙壁)
//#S######.#
//......#..#
//.#.##.##.#
//.#........
//##.##.####
//....#....#
//.#######.#
//....#.....
//.####.###.
//....#...G#					     	
//sample output：22
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
using namespace std;
/*
const int MAX_NM = 100;
char field[MAX_NM][MAX_NM];
int N;
int M;
int step = 0;

int main()
{	
	//input your code from here
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> field[i][j];
	void solve();
	void bfs(int x, int y);
	
	solve();
	return 0;
}

void bfs(int x, int y)
{
	if (field[x][y] == 'G')	return;
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1; dy <= 1; dy++){
			int nx = x +dx, ny = y + dy;
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] != '#'){
				step++;
				bfs(nx, ny);
			}
		}
	}
}	

void solve()
{	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (field[i][j] == 'S')
				bfs(i, j);
			}
	}
	cout << step;						
}
*/
//这个INF用来表示最初始的距离
const int INF = 100000000;
//使用pair表示状态，利用typedef会更加方便
typedef pair<int, int> P;
const int MAX_N = 100;//迷宫数组的大小
const int MAX_M = 100;
int N, M;//迷宫的具体大小
int sx,sy;//起点坐标
int gx,gy;//终点坐标
char maze[MAX_N][MAX_M + 1];//储存迷宫信息的数组
int d[MAX_N][MAX_M];//储存到各个位置的对端距离的数组
int dx[4] = {1,0,-1,0};//这两个数组配合使用，表示上下左右四个方向的状态转移
int dy[4] = {0,1,0,-1};

//求从（sx，sy）到（gx，gy）的最短距离,如果无法到达距离就是INF
int bfs(){
	queue<P> que;
	//把所有的位置都初始化为INF
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j ++) d[i][j] = INF;
	//将起点加入队列。并把这一地点的距离设为0
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	
	/不断循环直到队列长度为0
	while (que.size()){
		//从队列的最前端取出元素
		P p = que.front();que.pop();
		//如果取出的状态已经是终点，则搜索结束
		if (p.first == gx && p.second == gy) break;

	//四个方向的循环
	for (int i = 0; i < 4; i++){
		//移动之后的位置记为（nx，ny）
		int nx = p.first + dx[i], ny = p.second + dy[i];

	//判断是否可以移动以及是否已经访问过
	if (0 <= nx && nx < N && 0 <= ny && ny <= M && maze[nx][ny] != '#' && d[nx][ny] == INF){
		//可以移动的话，加入队列，并且到该位置的距离确定为到p的距离
		que.push(P(nx, ny));
		d[nx][ny] = d[p.first][p.second] + 1;
		}
	}
}
	return d[gx][gy];
}

void solve()
{
	int res = bfs();
		cout << res;
}

int main()
{	
	//input your code from here
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];
	void solve();
	int bfs();

	for (int i= 0 ; i < N; i++){
		for (int j = 0; j < M; j++){
			if (maze[i][j] == 'S'){
				sx = i; 
				sy = j;
			}
		}
	}

	for (int i= 0 ; i < N; i++){
		for (int j = 0; j < M; j++){
			if (maze[i][j] == 'G'){
				gx = i; 
				gy = j;
			}
		}
	}
	
	solve();
	return 0;
}

//解释：参考数据结构p408，算法竞赛入门经典p165，
