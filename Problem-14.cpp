#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000010];

int process(int s)
{
	long long x = s;
	int tep = s;
	int len = 1;
	while (x != 1){


		if (x <= 1000000 && dp[x] != -1){
			len += dp[x];
			break;
		}
		if (x & 1)
			x = 3 * x + 1;
		else
			x >>= 1;
		len ++;
	}
	return dp[tep] = len;
}

int main()
{
	int ans = 0;
	int maxs = -1;

	memset(dp , -1 , sizeof(dp));
	for (int i = 1 ; i <= 1000000 ; i ++){

		int temp = process(i);
		if (temp > maxs){
			maxs = temp;
			ans = i;
		}
	}
	printf("%d %d\n" , ans , maxs);
}