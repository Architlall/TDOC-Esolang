#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 4
char* stringINIT(char *str)
{
	int mem = SIZE;
	str = (char *)malloc(mem);
	char *next_read = str;
	fgets(next_read, mem, stdin);
	while(str[strlen(str)-1] != '\n') 
	{
	 	mem += SIZE;
		str = realloc(str, mem); 
	 	next_read = str + strlen(str);
	 	fgets(next_read, SIZE+1, stdin);
	}
	return str;
}
int main(){
    char * ch="plo",ch1="klo";
    printf("%s %s",ch,ch1);
    return 0;
}