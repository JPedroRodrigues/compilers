#include <stdio.h>

// Considering Σ = {a, b, c}
// L4 = { a^i b^j c^k | i >= 1, j >= 2, k >= 3 }

int fixedQuantity(char *word) {
    if (*word == 'a') {
        word++;
        goto q1;
    }

    q1:
        if (*word == 'a') {
            word++;
            goto q1;
        }
        if (*word == 'b') {
            word++;
            goto q2;
        }
        return 0;

    q2:
        if (*word == 'b') {
            word++;
            goto q3;
        }
        return 0;

    q3:
        if (*word == 'b') {
            word++;
            goto q3;
        }
        if (*word == 'c') {
            word++;
            goto q4;
        }
        return 0;

    q4:
        if (*word == 'c') {
            word++;
            goto q5;
        }
        return 0;

    q5:
        if (*word == 'c') {
            word++;
            goto q6;
        }
        return 0;

    q6:
        if (*word == 'c') {
            word++;
            goto q6;
        }
        return *word == '\0';

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("Word \"%s\" follows the rule: %d\n", argv[1], fixedQuantity(argv[1]));

    return 0;
}
