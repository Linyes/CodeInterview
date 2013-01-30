#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s string\n", argv[0]);
		return -1;
	}
	
	char *str = argv[1];
	int val, i;
	int check[128];
	memset(check, 0, sizeof(int)*128);
	int flag = 1;
	for (i = 0; i < strlen(str); i++) {
		val = str[i];
		if (check[val]==1){
			flag = 0;
			break;
		}
		check[val]=1;
	}
	printf("%s\n", flag?"True":"False");
	return 0;

}
