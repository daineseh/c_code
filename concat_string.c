#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *head = "PATH=";
    char *body = getenv("PATH");
    char *tail = ":/usr/local/NEW_PATH"
    char *new_path;

    printf("HEAD: %S\n", path_head);
    printf("BODY: %s\n", path);
    new_path = malloc(512);
    printf("New Path: %s\n", new_path);
    strcpy(new_path, head);
    printf("New Path+HEAD: %s\n", new_path);
    strcat(new_path, body);
    printf("New Path+HEAD+BODY: %s\n", new_path);
    strcat(new_path, tail);
    printf("New Path+HEAD+BODY+TAIL: %s\n", new_path);

    free(new_path);

    return 0;
}

