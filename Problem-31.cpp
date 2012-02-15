#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

#define _DEBUG_ 0

using namespace std;

int bi[10] = {1 , 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256};
int dp[500][205];
int v[500];
int p[10] = {1 , 2 , 5 , 10 , 20 , 50 , 100 , 200};

int main()
{



	memset(v , 0 , sizeof(v));
	memset(dp , 0 , sizeof(dp));
	int cnt = 0;

	for (int i = 0 ; i < 8 ; i ++){
		int temp = p[i];
		int c = 0;
		while (temp * bi[c] <= 200){
			v[cnt ++] = temp * bi[c];
			c ++;
		}
	}
	dp[0][0] = 1;
	dp[0][v[0]] = 1;
	for (int i = 1 ; i < cnt ; i ++){
		for (int j = 0 ; j <= 200 ; j ++){
			if ( j - v[i] >= 0 )
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i]];
			else dp[i][j]  = dp[i - 1][j];
		}
	}

	int ans = 0;
	ans = dp[cnt - 1][200];

	printf("%d\n" , ans);

}