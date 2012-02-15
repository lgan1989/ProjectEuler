#include <cstdio>
#include <algorithm>

#define _DEBUG_ 0

using namespace std;

int mdays[12] = {31 ,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int y)
{
	if ((y % 100 && y % 4 == 0) || (y % 100 == 0 && y % 400 == 0))return true;
	return false;
}

int main()
{

	int y = 1900;
	int m = 1;
	int d = 7;
	int ans = 0;
	while (1){
		d += 7;
		if (y == 2000 && m == 12 && d > 1)break;
		int adn = 0;
		if (m == 2 && isleap(y) == 1)adn ++;
		if (d > mdays[m - 1] + adn){
			d -= mdays[m - 1] + adn;
			m ++;
		}
		if (m > 12){
			m -= 12;
			y ++;
		}
		if (d == 1 && y >= 1901){
			printf("%d %d %d\n" , y , m , d);
			ans ++;
		}
	}
	printf("%d\n" , ans);
	
}