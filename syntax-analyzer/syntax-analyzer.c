#include <stdio.h>
#include <stdlib.h>

// Given a production:
// E ::= a | b | +EE | *EE

// Lexical
char *buffer;

// Syntactic
char lookahead;

void consume(char atom);
void E();

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return -1;
    }

    buffer = argv[1];
    printf("Word: \"%s\"\n", buffer);

    lookahead = *buffer++;

    E();
    consume('\0');

    return 0;
}

void E() {
    switch(lookahead) {
        case '+':
            consume('+');
            E(); E();
            break;

        case '*':
            consume('*');
            E(); E();
            break;

        case 'a':
        case 'b':
            consume(lookahead);
            break;

        default:
            exit(-1);
    }
}

void consume(char atom) {
    if (lookahead == atom) {
        lookahead = *buffer++;  // get_token
    } else {
        printf("Syntax Error: [%c] expected. Found [%c] instead\n", atom, lookahead);
        exit(1);
    }
}
