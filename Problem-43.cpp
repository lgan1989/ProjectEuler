#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

#define _DEBUG_ 0

using namespace std;

int p[10] = {0 , 1 , 2 , 3 , 4 , 5 ,6 ,7 , 8 ,9};
int primes[10] = {2, 3 , 5 , 7, 11, 13 , 17};

int main()
{
	long long ans = 0;
	do{
		int temp = 0;
		bool flag = 0;
		for (int i = 0 ; i < 7 ; i ++){
			temp = 100 * p[1 + i] + 10 * p[2 + i] + p[3 + i];
			if (temp % primes[i]){
				flag = 1;
				break;
			}
		}
		if (!flag){
			long long t = 1;
			long long s = 0;
			for (int i = 9 ; i >= 0 ; i --){
				s += t * p[i];
				t *= 10;
			}
			printf("%lld\n" , s);
			ans += s;
		}

	}while (next_permutation(p , p + 10));

	printf("%lld\n" , ans);
}
