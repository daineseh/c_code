#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char s[] = "Self-trust is the first secret of success.";
    char t[] = "AAAA";
    char *test;

    test = strstr(s, t);
    if(test == NULL){
        printf("Not found");
        return 0;
    }
    printf("%s\n", test);

    return 0;   
}

