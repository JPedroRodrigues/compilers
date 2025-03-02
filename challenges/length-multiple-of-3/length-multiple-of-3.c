#include <stdio.h>

// Considering Σ = {a, b, c}
// L5 = { W ∈ Σ* | W has a length multiple of 3 }

int lengthMultipleOfThree(char *word) {
    q0:
        if (*word == 'a' || *word == 'b' || *word == 'c') {
            word++;
            goto q1;
        }
        return *word == '\0';

    q1:
        if (*word == 'a' || *word == 'b' || *word == 'c') {
            word++;
            goto q2;
        }
        return 0;

    q2:
        if (*word == 'a' || *word == 'b' || *word == 'c') {
            word++;
            goto q0;
        }
        return 0;

    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("\"%s\" has a length multiple of 3: %d\n", argv[1], lengthMultipleOfThree(argv[1]));
    return 0;
}
