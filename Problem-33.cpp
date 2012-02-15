#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

#define _DEBUG_ 0

using namespace std;


int main()
{
	
	
	for (int i = 11 ; i <= 99 ; i ++){
		for (int j = i + 1 ; j <= 99 ; j ++){

			if (i % 10 == 0 || j % 10 == 0)continue;
			int a = i/10;
			int b = i % 10;
			int c = j/10;
			int d = j % 10;
			if (a * j == c * i && b == d){
				printf("%d / %d -> %d / %d\n" , i , j , a , c);
			}
			if (b * j == d * i && a == c){
				printf("%d / %d -> %d / %d\n" , i , j , b , d);
			}
			if (a * j == d * i && b == c){
				printf("%d / %d -> %d / %d\n" , i , j , a , d);
			}
			if (b * j == c * i && a == d){
				printf("%d / %d -> %d / %d\n" , i , j , b , c);
			}
		}
	}
}
/*
16 / 64 -> 1 / 4
19 / 95 -> 1 / 5
26 / 65 -> 2 / 5
49 / 98 -> 4 / 8
*/