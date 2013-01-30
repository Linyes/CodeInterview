#include <stdio.h>
#include <string.h> /* memset */ 

void replaceSpace (char *str, int len)
{
	int space_count = 0, newLen, i;
	
	for (i = 0; i < len; i++) {
		if (str[i] == ' ')
			space_count++;
	}
	newLen = len + space_count*2;
	
	str[newLen] = '\0';
	for (i = len-1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[newLen-1] = '0';
			str[newLen-2] = '2';
			str[newLen-3] = '%';
			newLen = newLen - 3;	
		}
		else {
			str[newLen - 1] = str[i];
			newLen--;
		}
	}
}

int main(int argc, char *argv[])
{
	char str[] = "a b  c      ";
	printf("%s\n",str);
	replaceSpace(str, 6);
	printf("%s\n",str);
	return 0;

}
