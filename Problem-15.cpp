#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[25][25];

int main()
{
	memset(dp , 0 , sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0 ; i <= 20 ; i ++){
		for (int j = 0 ; j <= 20 ; j ++){
			dp[i][j + 1] += dp[i][j];
			dp[i + 1][j] += dp[i][j];
		}
	}
	printf("%lld\n" , dp[20][20]);
}