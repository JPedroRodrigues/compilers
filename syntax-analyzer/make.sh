VALGRIND=false

if [ "$1" == "--valgrind" ]; then
    VALGRIND=true
    shift
fi

if [ -z "$1" ]; then
    echo "Usage $0 [--valgrind] <input_string>"
    exit 1
fi

gcc syntax-analyzer.c -Wall -g -O3 -o syntax-analyzer

if [ "$VALGRIND" == true ]; then
    echo "Running Valgrind..."
    valgrind -v ./syntax-analyzer "$1"

    echo "Running Program..."
fi

./syntax-analyzer "$1"

rm -if syntax-analyzer
