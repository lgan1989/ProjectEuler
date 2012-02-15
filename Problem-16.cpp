#include <cstdio>
#include <algorithm>

using namespace std;

int a[10] = {34, 23, 25, 35, 35, 34, 35, 30, 23, 28};
int main()
{
	int ans = 0;
	for (int i = 0 ; i < 9 ; i ++)
		ans += a[i] * (i + 1);
	printf("%d\n" , ans);
}