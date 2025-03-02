#include <stdio.h>

int oddAEvenB(char *string) {
    pApB:
        if (*string == 'a') {
            string++;  // consuming 'a'
            goto iApB;
        }
        if (*string == 'b') {
            string++;
            goto pAiB;
        }
        // if the char sequence ends here, then it should return 0
        return 0;

    iApB:
        if (*string == 'a') {
            string++;
            goto pApB;
        }
        if (*string == 'b') {
            string++;
            goto iAiB;
        }
        return 1;

    pAiB:
        if (*string == 'a') {
            string++;
            goto iAiB;
        }
        if (*string == 'b') {
            string++;
            goto pApB;
        }
        return 0;

    iAiB:
        if (*string == 'a') {
            string++;
            goto pAiB;
        }
        if (*string == 'b') {
            string++;
            goto iApB;
        }
        return 0;

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("%s: Error - invalid number of arguments\nUsage: %s <input_string>", argv[0], argv[0]);
        return -1;
    }

    printf("Answer: %d\n", oddAEvenB(argv[1]));
    return 0;
}
