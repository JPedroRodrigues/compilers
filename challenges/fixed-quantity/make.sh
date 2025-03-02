if [ -z "$1" ]; then
    echo "Usage $0 <input_string>"
    exit 1
fi

gcc fixed-quantity.c -Wall -O3 -g -o fixed-quantity
./fixed-quantity "$1"

rm -if fixed-quantity
