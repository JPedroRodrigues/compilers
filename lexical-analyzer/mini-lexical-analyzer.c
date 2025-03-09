#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Mini Lexical Analyzer
// It reads:
//
// IDENTIFIER   --> LOWERCASE_LETTER ( LOWERCASE_LETTER | DIGIT )*
// NUMBER       --> DIGIT+ . DIGIT+

// Defining Tokens
// The implementation is a simple enum
typedef enum {
    ERROR,
    IDENTIFIER,
    NUMBER,
    EOS
} Token;

typedef struct {
    Token token;
    int line;
    float attribute_number;
    char attribute_id[16];
} TokenInfo;

int line = 1;
char *strToken[] = { "ERROR", "IDENTIFIER", "NUMBER", "EOS" };
char *input = "var1     12.4   1.23  1000.01\n\r   variavel insana\n\r caracteres\n\n\nv";

TokenInfo read_number();
TokenInfo read_id();
TokenInfo consume();

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error while trying to open \"%s\" file.\n", argv[1]);
        return -1;
    }

    TokenInfo tokenInfo;

    do {
        tokenInfo = consume();

        printf("%03d# %s | ", line, strToken[tokenInfo.token]);

        if (tokenInfo.token == NUMBER) printf("%.3f", tokenInfo.attribute_number);
        else if (tokenInfo.token == IDENTIFIER) printf("%s", tokenInfo.attribute_id);

        printf("\n");
    } while (tokenInfo.token != ERROR && tokenInfo.token != EOS);

    fclose(file);

    // Token token = consume("var1\n\r12.4\n\r");
    // printf("%d\n", read_id("var1\n\r12.4\n\r"));

    // printf("\"%s\" is recognized by the mini lexical analyzer: %d\n", argv[1], mini_lexical_analyzer(argv[1]));
    return 0;
}

TokenInfo read_number() {
    char number[20];
    char *lookahead = input;
    TokenInfo tokenInfo;

    tokenInfo.token = ERROR;

    if (isdigit(*input)) {
        input++;
        goto q1;
    }
    return tokenInfo;

    q1:
        if (isdigit(*input)) {
            input++;
            goto q1;
        } else if (*input == '.') {
            input++;
            goto q2;
        }
        // [other]
        return tokenInfo;

    q2:
        if (isdigit(*input)) {
            input++;
            goto q3;
        }
        // [other]
        return tokenInfo;

    q3:
        if (isdigit(*input)) {
            input++;
            goto q3;
        }
        // [LETTER]
        if (isalpha(*input)) {
            return tokenInfo;
        }

        strncpy(number, lookahead, input - lookahead);
        number[input - lookahead] = '\0';

        tokenInfo.token = NUMBER;
        tokenInfo.attribute_number = atof(number);

        return tokenInfo;  // successfully recognized
}

TokenInfo read_id() {
    TokenInfo tokenInfo;
    char *lookahead = input;
    char identifier[256];

    tokenInfo.token = ERROR;

    if (islower(*input)) {
        input++;
        goto q1;
    }

    return tokenInfo;

    q1:
        if (islower(*input)) {
            input++;
            goto q1;
        }
        if (isdigit(*input)) {
            input++;
            goto q1;
        }
        if (isupper(*input)) {
            return tokenInfo;
        }


        tokenInfo.token = IDENTIFIER;
        strncpy(identifier, lookahead, input - lookahead);
        identifier[input - lookahead] = '\0';
        strcpy(tokenInfo.attribute_id, identifier);

        return tokenInfo;
}

TokenInfo consume() {
    TokenInfo tokenInfo;
    tokenInfo.token = ERROR;

    while (
        *input == ' '   ||
        *input == '\n'  ||
        *input == '\r'  ||
        *input == '\t'
    ) {
        if (*input == '\n') line++;
        input++;
    }

    if (isdigit(*input)) {
        tokenInfo = read_number();
    } else if (islower(*input)) {
        tokenInfo = read_id();
    } else if (*input == '\0') {
        tokenInfo.token = EOS;
    }

    tokenInfo.line = line;
    return tokenInfo;
}
