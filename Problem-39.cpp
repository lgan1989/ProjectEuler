#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

#define _DEBUG_ 0

using namespace std;

int d[1010];

int main()
{
	for (int i = 1 ; i <= 1000 ; i ++){
		for (int j = i ; j + i <= 1000 ; j ++){
			int x = i * i + j * j;
			int tmp = sqrt(x * 1.0);
			if (tmp * tmp == x){
				if (i + j + tmp <= 1000)d[i + j + tmp] ++;
			}
		}
	}
	int ans = 0;
	int m = -1;
	for (int i = 1 ; i <= 1000 ; i ++){
		if (m < d[i]){
			ans = i;
			m = d[i];
		}
	}
	printf("%d %d\n" , ans , m);
}
