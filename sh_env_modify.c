#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *path_head = "PATH=";
    char *path = getenv("PATH");
    char *new_path;

    new_path = calloc(512, sizeof(char));
    strcpy(new_path, path_head);
    strcat(new_path, path);
    printf("Current $%s\n", new_path);
    strcat(new_path, ":/usr/local/NEW_PATH");
    printf("Add path-[/usr/local/NEW_PATH] to $PATH\n");
    putenv(new_path);
    printf("Current $PATH=%s\n", getenv("PATH"));

    free(new_path);

    return 0;
}

