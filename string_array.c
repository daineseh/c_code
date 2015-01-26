#include<stdio.h>

int main(int argc, char* argv){
    char path[64];
    char *file_list[4] = {
        "/home/dainese/c_practice/a",
        "/home/dainese/c_practice/b",
        "/home/dainese/c_practice/c",
        "/home/dainese/c_practice/d"};

    printf("file_list width: %lu\n", sizeof(file_list)/sizeof(char *));
    for (int i=0; i<7; i++){
        sprintf(path, "%s", file_list[i]);
        printf("%s\n", path);
        if(remove(path))
            printf("Failed!\n");
        else
            printf("Success!\n");
    }
    return 0;
}
