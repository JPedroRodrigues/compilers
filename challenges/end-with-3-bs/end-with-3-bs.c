#include <stdio.h>

// Considering Σ = {a, b, c}
// L6 = { W ∈ Σ* | W end with exactly 3 b's }

int endWith3Bs(char *word) {
    q0:
        if (*word == 'a' || *word == 'c') {
            word++;
            goto q0;
        }
        if (*word == 'b') {
            word++;
            goto q1;
        }
        return 0;

    q1:
        if (*word == 'a' || *word == 'c') {
            word++;
            goto q0;
        }
        if (*word == 'b') {
            word++;
            goto q2;
        }
        return 0;

    q2:
        if (*word == 'a' || *word == 'c') {
            word++;
            goto q0;
        }
        if (*word == 'b') {
            word++;
            goto q3;
        }
        return 0;

    q3:
        if (*word == 'a' || *word == 'b' || *word == 'c') {
            word++;
            goto q0;
        }
        return 1;

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("\"%s\" ends exactly with 3 b's: %d\n", argv[1], endWith3Bs(argv[1]));
    return 0;
}
