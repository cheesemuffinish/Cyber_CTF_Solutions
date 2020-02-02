#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[215], key[11], msg[201], output[201];
	int i, j, k, shiftkeychar, shiftkeynum, ch;

	printf("Input: ");
	gets(input);

	for(i = 0; input[i] != ':'; i++)
		key[i] = input[i];
    key[i] = '\0';

    i++;

    k=0;
    for(j = i; input[j] != '\0'; j++){
		msg[k] = input[j];
		k++;
    }
    msg[k] = '\0';

	printf("\nmessage: %s\n", msg);
	printf("key: %s\n", key);

    shiftkeychar = atoi(key) % 26;
    shiftkeynum = atoi(key) % 10;

    printf("shiftkey for characters: %d\n", shiftkeychar);
    printf("shiftkey for numbers: %d\n", shiftkeynum);

    strcpy(output, msg);

	for(i = 0; output[i] != '\0'; i++)
        {
		ch = output[i];

		if(ch >= 'a' && ch <= 'z')
            {
			ch = ch + shiftkeychar;

			if(ch > 'z')
				ch = ch - 'z' + 'a' - 1;
			if(ch < 'a')
				ch = ch + 'z' - 'a' + 1;
            }

		if(ch >= 'A' && ch <= 'Z')
            {
			ch = ch + shiftkeychar;

			if(ch > 'Z')
				ch = ch - 'Z' + 'A' - 1;
			if(ch < 'A')
				ch = ch + 'Z' - 'A' + 1;
			}

		if(ch >= '0' && ch <= '9')
            {
			ch = ch + shiftkeynum;

			if(ch > '9')
				ch = ch - '9' + '0' - 1;
			if(ch < '0')
				ch = ch + '9' - '0' + 1;
            }

		output[i] = ch;
		//printf("output[%d]: %c", i, ch);
	}

	printf("Output: %s", output);

	return 0;
}