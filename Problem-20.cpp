#include <cstdio>
#include <algorithm>

#define _DEBUG_ 0

using namespace std;

char str[1000] = "9332621544394415268169923885626670049071596826438162146859296389521759\
9993229915608941463976156518286253697920827223758251185210916864000000\
000000000000000000";


int main()
{
	int ans = 0;
	for (int i = 0 ; i < strlen(str) ; i ++){
		ans += str[i] - '0';
	}
	printf("%d\n" , ans);
}