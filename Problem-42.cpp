#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

#define _DEBUG_ 0

using namespace std;

char name[100];

int d[10000];

void init()
{
	for (int i = 1 ; ; i ++){
		int tmp = i * (i + 1)/2;
		if (tmp >= 5000)break;
		d[tmp] = 1;
	}
}

int main()
{
	freopen("test.in" , "r" , stdin);
	freopen("test.out" , "w" , stdout);
	init();
	char c;
	int va = 0;
	int maxv = 0;
	int ans = 0;
	while (c = getchar()){
		if (c == -1)break;
		if (c == '"')continue;
		if (c == ','){
			if (d[va])ans ++;
			printf("%d\n" , va);
			va = 0;
			continue;
		}
		va += c - 'A' + 1;
		maxv = max(maxv , va);
	}
	printf("%d\n" , ans);
}
