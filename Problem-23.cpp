#include <cstdio>
#include <algorithm>

#define _DEBUG_ 0

using namespace std;

bool h[30000];
int abNumbers[30000];
int cnt = 0;

void init()
{
	for (int i = 2 ; i <= 28123  ; i ++){
		int s = 0;
		for (int j = 1 ; j <= i/2 ; j ++){
			if (i % j == 0)s += j;
			if (s > i)break;
		}
		if (s > i){
			abNumbers[cnt ++] = i;
		}
	}
}

int main()
{
	init();
	for (int i = 0 ; i < cnt ; i ++){
		for (int j = 0 ; j <= i ; j ++){
			if (abNumbers[i] + abNumbers[j] > 28123)break;
			h[abNumbers[i] + abNumbers[j]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= 28123 ; i ++){
		if (h[i] == 0)ans += i; 
	}
	printf("%d\n" , ans);

	
}