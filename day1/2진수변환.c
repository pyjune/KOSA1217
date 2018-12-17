#include <stdio.h>

char dec2bin[][5]= {"0000", "0001", "0010", "0011",
				"0100",	"0101", "0110", "0111", 
				"1000", "1001", "1010", "1011", 
				"1100", "1101", "1110", "1111"	};

int main(void) 
{
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		char str[11];
		int N;
		scanf("%d", &N);
		scanf("%s", str);
		printf("#%d ", tc);
		int i = 0;
		while(str[i] != '\0') 
		{
			int idx;
			if(str[i]>='0' && str[i]<='9')
				idx = str[i] - '0';
			else
				idx = str[i] - 'A' + 10;
			printf("%s", dec2bin[idx]);
			i++;
		}
		printf("\n");
		
	}
	return 0;
}
