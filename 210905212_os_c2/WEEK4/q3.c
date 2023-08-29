#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char old_path[256];
    char new_path[256];

    printf("Enter the old file path: ");
    scanf("%s", old_path);

    printf("Enter the new hard link path: ");
    scanf("%s", new_path);

   
    if (link(old_path, new_path) == 0) {
        printf("New hard link created successfully at %s\n", new_path);
    } else {
        perror("Failed to create a new hard link");
        exit(EXIT_FAILURE);
    }

    if (unlink(new_path) == 0) {
        printf("Hard link unlinked successfully\n");
    } else {
        perror("Failed to unlink the hard link");
        exit(EXIT_FAILURE);
    }

    return 0;
}

//home/student/Desktop/C2_210905212/WEEK4/q3.c
//home/student/Desktop/C2_210905212/WEEK4/q3new.c