#include <stdio.h>

int noConsecutiveAs(char *word) {
    q0:
        if (*word == 'b') {
            word++;
            goto q0;
        }
        if (*word == 'a') {
            word++;
            goto q1;
        }
        return 1;

    q1:
        if (*word == 'b') {
            word++;
            goto q0;
        }
        return *word == '\0';

    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("\"%s\" does not has consecutive a's: %d\n", argv[1], noConsecutiveAs(argv[1]));

    return 0;
}
