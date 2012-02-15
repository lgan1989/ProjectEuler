#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

#define _DEBUG_ 0

using namespace std;

//123456789
int p[10] = {1 , 2 ,3 , 4 ,5 , 6 , 7 ,8 ,9};
map < int , bool > hash;

int main()
{
	hash.clear();
	int ans = 0;
	do{

		for (int i = 0 ; i < 7 ; i ++){
			for (int j = i + 1 ; j < 8 ; j ++){
				int c = 1;
				int m1 = 0 , m2 = 0;
				int prod = 0;
				for (int k = i ; k >= 0 ; k --){
					m1 += p[k] * c;
					c *= 10;
				}
				c = 1;
				for (int k = j ; k > i ; k --){
					m2 += p[k] * c;
					c *= 10;
				}
				c = 1;
				for (int k = 8 ; k > j ; k --){
					prod += p[k] * c;
					c *= 10;
				}
				if (prod == m1 * m2 && hash[prod] == 0){
					hash[prod] = 1;
					//printf("%d %d %d\n" , m1 , m2 , prod);
					ans += prod;
				}
			}
		}

	}while (next_permutation(p , p + 9));

	printf("%d\n" , ans);

}