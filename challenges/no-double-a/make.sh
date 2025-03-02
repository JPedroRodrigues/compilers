if [ -z "$1" ]; then
    echo "Usage $0 <input_string>"
    exit 1
fi

gcc no-double-a.c -Wall -O3 -g -o no-double-a
./no-double-a "$1"

rm -if no-double-a
