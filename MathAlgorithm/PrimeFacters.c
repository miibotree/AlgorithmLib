//素数分解
//Miibotree
//2015.1.17

#include <stdio.h>

#define MAX 100000

bool mark[MAX+1];
int prime[MAX+1];
int primeSize;

void init()
{
	primeSize = 0;
	for(int i = 1; i <= MAX; i++)
		mark[i] = false;
	for (int i = 2; i <= MAX; i++)
	{
		if (mark[i] == true)
			continue;
		prime[primeSize++] = i;
		if (i >= 1000)
			continue;
		for(int j = i * i; j <= MAX; j+=i)
			mark[j] = true;
	}
}

int main()
{
	init();//初始化
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int ansPrime[30];
		int ansSize = 0;
		int ansNum[30];
		for(int i = 0; i < primeSize; i++)
		{
			if(n%prime[i]==0)				//说明是素因子
			{
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while(n % prime[i] == 0)//有几个这样的素因子
				{
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if (n == 1)//结束了
					break;
			}
		}
		if (n != 1)//说明肯定只有一个了
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		}
		int ans = 0;
		for (int i = 0; i < ansSize; i++)
			ans += ansNum[i];
		printf("%d\n", ans);
	}
	return 0;
}