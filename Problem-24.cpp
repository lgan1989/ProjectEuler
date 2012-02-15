#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#define _DEBUG_ 0

using namespace std;

int p[10] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};

int main()
{
	
	int cnt = 0;
	do{
		cnt ++;

		if (cnt == 1000000){	
		for (int i = 0 ; i < 10 ; i ++)
			printf("%d" , p[i]);
			break;
		}
	}while (next_permutation(p , p + 10));
	
	
}