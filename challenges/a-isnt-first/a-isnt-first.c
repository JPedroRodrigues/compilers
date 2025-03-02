#include <stdio.h>

// Considering Σ = {a, b, c}
// L6 = { W ∈ Σ* | W does not start with a }

int startsWithA(char *word) {
    if (*word == 'a') {
        return 0;
    }

    q1:
        if (*word == 'a' || *word == 'b' || *word == 'c') {
            word++;
            goto q1;
        }
        return *word == '\0';

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    printf("\"%s\" does not start with \"a\": %d\n", argv[1], startsWithA(argv[1]));
    return 0;
}
