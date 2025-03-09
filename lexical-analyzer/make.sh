VALGRIND=false
if [ "$1" == "--valgrind" ]; then
    VALGRIND=true
    shift
fi

if [ -z "$1" ]; then
    echo "Usage: $0 [--valgrind] <input_string>"
    exit 1
fi

gcc mini-lexical-analyzer.c -Wall -g -O3 -o mini-lexical-analyzer

if [ "$VALGRIND" = true ]; then
    echo "Running Valgrind..."
    valgrind -v ./mini-lexical-analyzer "$1"

    echo "Running Program..."
fi

./mini-lexical-analyzer "$1"

rm -if mini-lexical-analyzer
