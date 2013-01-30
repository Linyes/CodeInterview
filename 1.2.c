#include <stdio.h>
#include <string.h>

void reverse (char *str)
{
	char *end = str;
	char *head = str;
	char tmp;
	
	/* Find the last character in the string */
	while (*end)
		++end;
	
	/* Move the pointer back from null */
	end--;
	
	/* Swap the head and tail */
	while (head < end) {
		tmp = *head;
		*head++ = *end;
		*end-- = tmp;
	}

	printf("%s\n",str);

}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s string\n", argv[0]);
		return -1;
	}
	
	reverse(argv[1]);
	
	return 0;

}
