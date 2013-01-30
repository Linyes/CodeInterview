#include <stdio.h>
#include <string.h> /* memset */ 
#include <stdlib.h>

char *compress(char *src)
{
	char cur, str[10];
	int count, i;

	/* Initialize output string */
	char *out;
	out = malloc(strlen(src));
	out[0] = '\0';
	
	/* begin compression */
	count = 0;
	cur = *src;
	for (i = 0; i <= strlen(src); i++) {
		if (cur == src[i])
			count++;
		else {
			sprintf(str, "%c%d", cur, count);
			
			/* check the validation of compress */
			if (strlen(str)+strlen(out) >= strlen(src)) {
				free(out);
				return src;
			}

			strcat(out, str);
			
			cur = src[i];
			count = 1;
		}
	}
	return out;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s string\n", argv[0]);
		return -1;
	}
	
	char *ret;
	ret = compress(argv[1]);
	printf("output is: %s\n", ret);
	
	return 0;

}
