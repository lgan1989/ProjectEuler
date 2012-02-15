#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#define _DEBUG_ 0

using namespace std;

int a[5];

int main()
{
	
	a[0] = a[1] = a[2] = a[3] = 1;
	int s = 1;
	int temp = 2;
	for (int i = 0 ; i < 1001/2 ; i ++){
		for (int j = 0 ; j < 4; j ++){
			a[j] += temp;
			temp += 2;
			s += a[j];
		}
	}
	printf("%d\n" , s);
	
}