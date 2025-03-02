#include <stdio.h>

// Considering Σ = {a,b}
// L1 = {W ∈ Σ* | W has an odd number of a's}

int oddA(char *word) {
    evenA:
        if (*word == 'a') {
            word++;
            goto oddA;
        }

        return 0;

    oddA:
        if (*word == 'a') {
            word++;
            goto evenA;
        }

        return 1;

    return 0;
}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("\"%s\" has an odd number of a's: %d\n", argv[1], oddA(argv[1]));
    return 0;
}
