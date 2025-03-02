if [ -z "$1" ]; then
    echo "Usage $0 <input_string>"
    exit 1
fi

gcc a-isnt-first.c -Wall -O3 -g -o a-isnt-first
./a-isnt-first "$1"

rm -if a-isnt-first
