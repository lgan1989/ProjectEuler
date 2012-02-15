#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#define _DEBUG_ 0

using namespace std;

char name[30];

vector < string > v;

int main()
{

	freopen("test.in" , "r" , stdin);
	freopen("test.out" , "w" , stdout);

	v.clear();
	memset(name , 0 , sizeof(name));
	while (scanf("%s" , name) == 1)
		v.push_back( string(name) );
	sort(v.begin() , v.end()); 
	int cnt = 0;
	int s = 0;
	for (int i = 0 ; i < v.size() ; i ++){
		int temp = 0;
		cnt ++;
		printf("%s\n" , v[i].c_str());
		for (int j = 0 ; j < v[i].length() ; j ++){
			temp += v[i][j] - 'A' + 1;
		}
		temp *= cnt;
		s += temp;
	}
	printf("%d\n" , s);
	
}