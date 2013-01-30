#include <stdio.h>
#include <string.h>

void count (char *str, int *check)
{
	int val;
	
	while (*str) {
		val = *str++;
		check[val]++;	
	}
}

void compare (char *str1, char *str2)
{
	int check1[128], check2[128];
	int flag, i;
	
	memset(check1, 0, sizeof(int)*128);
	memset(check2, 0, sizeof(int)*128);
	
	count(str1, check1);
	count(str2, check2);
	
	flag = 1;
	
	for (i = 0; i < 128; i++) {
		if (check1[i] != check2[i]) {
			flag = 0;
			break;
		}
	}
	
	printf("The two strings are %s\n",flag?"True":"False");

}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Usage: %s string_one string_two\n", argv[0]);
		return -1;
	}
	
	compare(argv[1], argv[2]);
	
	return 0;

}
