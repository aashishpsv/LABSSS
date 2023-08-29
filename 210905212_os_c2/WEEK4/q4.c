#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char old_path[256];
    char new_path[256];

    printf("Enter the old file path: ");
    scanf("%s", old_path);

    printf("Enter the new soft link path: ");
    scanf("%s", new_path);
    
    if (syslink(old_path, new_path) == 0) {
        printf("New soft link created successfully at %s\n", new_path);
    } else {
        perror("Failed to create a new soft link");
        exit(EXIT_FAILURE);
    }
    

    if (unlink(new_path) == 0) {
        printf("soft link unlinked successfully\n");
    } else {
        perror("Failed to unlink the soft link");
        exit(EXIT_FAILURE);
    }

    return 0;
}
