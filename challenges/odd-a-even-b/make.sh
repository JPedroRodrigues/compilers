if [ -z "$1" ]; then
    echo "Usage: $0 <input_string>"
    exit 1
fi

gcc odd-a-even-b.c -Wall -O3 -g -o odd-a-even-b
./odd-a-even-b "$1"

rm -if odd-a-even-b
