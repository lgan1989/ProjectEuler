#include <cstdio>
#include <cstring>
#include <memory>
using namespace std;


int q[10];
int h[2][10];

int main()
{
	int i , j , k;
	for (i = 1 ; i <= 3000000 ; i ++){
		memset(h , 0 , sizeof(h));
	
		for (j = 1 ; j <= 6 ; j ++){
			memset(h[j%2] , 0 , sizeof(h[j%2]));
			q[j] = i * j;
			int tmp = q[j];
			while (tmp){
				h[j%2][tmp%10] ++;
				tmp/=10;
			}
			if (j == 1)continue;
			bool flag = 0;
			for (k = 0 ; k < 10 ; k ++){
				if (h[0][k] != h[1][k]){
					flag = 1;
					break;
				}
			}
			if(flag)break;
		}
		if (j == 7)break;
		
	}
	printf("%d\n" , i);

}