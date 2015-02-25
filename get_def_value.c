#include <stdio.h>
#include <string.h>

#define TEST "1.2.3"

int main(int argc, char* argv){
    char buf[32] = {0};
    snprintf(buf, sizeof(buf), "%s", TEST);
    puts(buf);
    printf("%s\n", buf);
    printf("%zu\n", sizeof(buf));

    return 0;
}
