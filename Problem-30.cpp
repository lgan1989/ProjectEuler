#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

#define _DEBUG_ 0

using namespace std;

int a[10];
int ans;
bool hash[1000000];

bool ok(int x)
{
	int s = 0;
	int prex = x;
	if (x == 1 || x == 0)return false;
	while (x){
		int tp = x % 10;
		s += tp * tp * tp * tp * tp;
		x /= 10;
	}
	if (s == prex)return true;
	return false;
}

void dfs(int p , int l , int va)
{
	int x = va;
	if (p == l){
		if (ok(va) && hash[va] == 0){
			hash[va] = 1;
			printf("%d\n" , va);
			ans += va;
		}
		
		return;
	}
	for (int i = 0 ; i <= 9 ; i ++){
		int temp = i * i * i * i * i;
		dfs(p + 1 , l , va + temp);
	}
}

int main()
{

	int len = 0;
	ans = 0;
	memset(hash , 0 , sizeof(hash));
	while (++ len && len <= 6){
		dfs(0 , len , 0);
	}
	printf("%d\n" , ans);

}