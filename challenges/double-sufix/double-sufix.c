#include <stdio.h>

// Considering Σ = {a,b}
// L2 = {W ∈ Σ* | the W sufix is aa or bb}

int doubleSufix(char *word) {
    if (*word == 'a') {
        word++;
        goto q1;
    }
    if (*word == 'b') {
        word++;
        goto q2;
    }

    q1:
        if (*word == 'a') {
            word++;
            goto q3;
        }
        if (*word == 'b') {
            word++;
            goto q2;
        }
        return 0;

    q2:
        if (*word == 'a') {
            word++;
            goto q1;
        }
        if (*word == 'b') {
            word++;
            goto q4;
        }
        return 0;

    q3:
        if (*word == 'a') {
            word++;
            goto q3;
        }
        if (*word == 'b') {
            word++;
            goto q2;
        }
        return 1;

    q4:
        if (*word == 'a') {
            word++;
            goto q1;
        }
        if (*word == 'b') {
            word++;
            goto q4;
        }
        return 1;

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("\"%s\" ends with \"aa\" or \"bb\": %d\n", argv[1], doubleSufix(argv[1]));
    return 0;
}
