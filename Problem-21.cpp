#include <cstdio>
#include <algorithm>

#define _DEBUG_ 0

using namespace std;

bool h[10010];
int tp[10010];

int work(int n)
{
	if (tp[n] != -1)return tp[n];
	int s = 1;
	for (int i = 2 ; i <= n/2 ; i ++){
		if (n % i == 0)s += i;
	}
	return tp[n] = s;
}

int main()
{

	memset(tp , -1 , sizeof(tp));
	for (int i = 2 ; i <= 10000 ; i ++){
		int temp = work(i);
		if (temp == i)continue;
		if (temp > 10000)continue;
		if (work(temp) == i){
			h[temp] = h[i] = 1;
		}
	}
	int ans = 0;
	for (int i = 2 ; i <= 10000 ; i ++)
		if (h[i])ans += i;
	printf("%d\n" , ans);
	
}