if [ -z "$1" ]; then
    echo "Usage $0 <input_string>"
    exit 1
fi

gcc double-sufix.c -Wall -O3 -g -o double-sufix
./double-sufix "$1"

rm -if double-sufix
