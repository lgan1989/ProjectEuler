#include <cstdio>
#include <algorithm>

#define _DEBUG_ 0

using namespace std;

char word[30][20] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};
char tens[20][20] = {
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sisty",
	"seventy",
	"eighty",
	"ninety",
};

int process(int num)
{
	if (num == 1000){
		return 11;
	}
	else if (num < 20){
#if _DEBUG_
	printf("%s\n" , word[num]);
#endif
		return strlen(word[num]);
	}
	else if (num < 100){
		if (num % 10 == 0){
#if _DEBUG_
			printf("%s\n" , tens[num/10 - 2]);
#endif
			return strlen(tens[num/10 - 2]);
		}
		else{
#if _DEBUG_
			printf("%s %s\n" , tens[num/10 - 2] , word[num % 10]);
#endif
			return strlen(tens[num/10 - 2]) + strlen(word[num % 10]);
		}
	}
	else{
		if (num % 100 == 0){
#if _DEBUG_
			printf("%s hundred\n" , word[num/100]);
#endif
			return strlen(word[num/100]) + 7;
		}
		else if (num % 10 == 0){
			if (num % 100 < 20){
#if _DEBUG_
				printf("%s hundred and ten\n" , word[num/100]);
#endif
				return strlen(word[num/100]) + 13;
			}
			else{
#if _DEBUG_
				printf("%s hundred and %s\n" , word[num/100] , tens[(num%100)/10 - 2]);
#endif
				return strlen(word[num/100]) + 10 + strlen(tens[(num%100)/10 - 2]);;
			}
		}
		else{
			if (num % 100 < 20){
#if _DEBUG_
				printf("%s hundred and %s\n" , word[num/100] , word[num % 100]);
#endif
				return strlen(word[num/100]) + 10 + strlen(word[num % 100]);
			}
			else{
#if _DEBUG_
				printf("%s hundred and %s %s\n" , word[num/100] , tens[(num%100)/10 - 2] , word[num % 10]);
#endif
				return strlen(word[num/100]) + 10 + strlen(tens[(num%100)/10 - 2]) + strlen(word[num % 10]);
			}
		}
	}
	
}

int main()
{
	int ans = 0;
	for (int i = 1 ; i <= 1000 ; i ++){
		ans += process(i);
	}
	printf("%d\n" , ans);
}