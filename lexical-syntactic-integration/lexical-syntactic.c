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
    SUM,
    MULTI,
    EOS
} Token;

typedef struct {
    Token token;
    int line;
    float attribute_number;
    char attribute_id[16];
} TokenInfo;

int line = 1;
char *strToken[] = { "ERROR", "IDENTIFIER", "NUMBER", "+", "*", "EOS" };
char *input = "+ * 1.2 var1 1.0";

// Syntactic
Token lookahead;
TokenInfo token_info;

void consume(Token token);
void E();
TokenInfo read_number();
TokenInfo read_id();
TokenInfo get_token();

int main(int argc, char **argv) {
    printf("Analyzing \"%s\"\n", input);

    token_info = get_token();
    lookahead = token_info.token;

    E();
    consume(EOS);

    printf("End of Lexical-Sinctatic Analysis\n");
    return 0;
}

TokenInfo read_number() {
    char number[20];
    char *lookahead_number = input;
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

        strncpy(number, lookahead_number, input - lookahead_number);
        number[input - lookahead_number] = '\0';

        tokenInfo.token = NUMBER;
        tokenInfo.attribute_number = atof(number);

        return tokenInfo;  // successfully recognized
}

TokenInfo read_id() {
    TokenInfo tokenInfo;
    char *lookahead_id = input;
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
        strncpy(identifier, lookahead_id, input - lookahead_id);
        identifier[input - lookahead_id] = '\0';
        strcpy(tokenInfo.attribute_id, identifier);

        return tokenInfo;
}

TokenInfo get_token() {
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
        input++;
        tokenInfo.token = EOS;
    } else if (*input == '+') {
        input++;
        tokenInfo.token = SUM;
    } else if (*input == '*') {
        input++;
        tokenInfo.token = MULTI;
    }

    tokenInfo.line = line;
    return tokenInfo;
}

// Given a production:
// E ::= a | b | +EE | *EE

void E() {
    switch(lookahead) {
        case SUM:
            consume(SUM);
            E(); E();
            break;

        case MULTI:
        consume(MULTI);
            E(); E();
            break;

        case IDENTIFIER:
        case NUMBER:
            consume(lookahead);
            break;

        default:
            exit(-1);
    }
}

void consume(Token token) {
    if (lookahead == token) {
        token_info = get_token();
        lookahead = token_info.token;  // get_token
    } else {
        printf("Syntax Error: [%s] expected. Found [%s] instead\n", strToken[token], strToken[lookahead]);
        exit(1);
    }
}
