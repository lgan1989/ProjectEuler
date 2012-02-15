#include <cstdio>
#include <cstring>
#include <memory>
using namespace std;

bool notPrimes[1000000];
int s[12];

void init(){

	notPrimes[1] = 1;
	for (int i = 2 ; i <= 500000 ; i ++){
		if (notPrimes[i] == 1)continue;
		for (int j = i * 2 ; j <= 1000000 ; j += i){
			notPrimes[j] = 1;
		}
	}

}

bool rep(int idx , int len){

	int count = 0;
	int tmp[12];
	memcpy(tmp , s , sizeof(s));
	int tv = tmp[idx];
	for (int i = 0 ; i <= 9 ; i ++){
		memcpy(tmp , s , sizeof(s));
		int fst = 0;
		if (i == 0)fst = 1;
		for (int j = fst ; j < len ; j ++){
			if (tmp[j] == tv)tmp[j] = i;
		}
		int val = 0;
		int bas = 1;
		for (int i = 0 ; i < len ; i ++)
			val += tmp[len  - 1 - i] * bas , bas *= 10;
		if (notPrimes[val] == 0)count ++;
	}
	if (count >= 8)return true;
	return false;
}

bool ganit(int p , int len){
	if (p == len){
		int val = 0;
		int bas = 1;
		int cdigit[10];
		memset(cdigit , 0 , sizeof(cdigit));
		for (int i = 0 ; i < p ; i ++){
			val += s[len  - 1 - i] * bas; 
			bas *= 10;
			cdigit[s[i]] ++;
		}
		if (notPrimes[val] == 0){
			for (int i = 0 ; i < len ; i ++){
				if (rep(i , len)){
					printf("%d\n" , val);
					return true;
				}
			}
		}
		return false;
	}
	int fst = 0;
	if (p == 0)fst = 1;
	for (int i = fst ; i <= 9 ; i ++){
		s[p] = i;
		if(ganit(p + 1 , len) == true)return true;
	}
	return false;
	
}


int main()
{

	init();
	int len = 6;
	while (ganit(0 , len ++) == false){};

}