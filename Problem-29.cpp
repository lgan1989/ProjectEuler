#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

#define _DEBUG_ 0

using namespace std;


map < vector < int > , bool > hash;

int main()
{
	int ans = 0;
	for (int a = 2 ; a <= 100 ; a ++){
		for (int b = 2 ; b <= 100 ; b ++){
			vector < int > temp;
			temp.clear();
			int x = a;
			for (int i = 2 ; i <= a && x != 1 ; i ++){
				int c = 0;
				while (x % i == 0 && x != 1){
					x /= i;
					c ++;
				}
				if (c){
					temp.push_back(i);
					temp.push_back(c * b);
				}
			}
			if (hash[temp] == 0){
				ans ++;
				hash[temp] = 1;
			}
		}
	}
	printf("%d\n" , ans);
	
}