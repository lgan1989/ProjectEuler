#include <cstdio>
#include <algorithm>

#define _DEBUG_ 0

using namespace std;

int dp[50][50];
int a[50][50];

int f(int x , int y)
{
	if (dp[x][y] != -1)
		return dp[x][y];
	int tx = x + 1;
	int ty = y;
	int temp = a[x][y];
	int t1 = 0 , t2 = 0;
	if (tx >= 0 && ty >= 0 && a[tx][ty] != -1){
		t1 = f(tx  ,ty);
	}
	tx = x + 1;
	ty = y + 1;
	if (tx >= 0 && ty >= 0 && a[tx][ty] != -1){
		t2 = f(tx  ,ty);
	}
	temp = max(temp + t1 , temp + t2);
	return dp[x][y] = temp;
}

int main()
{
	memset(dp , -1 , sizeof(dp));
	memset(a , -1 , sizeof(a));
	for (int i = 0 ;i < 15 ; i ++){
		for (int j = 0 ; j <= i ; j ++){
			scanf("%d" , &a[i][j]);
		}
	}
	printf("%d\n" , f(0 , 0));
}