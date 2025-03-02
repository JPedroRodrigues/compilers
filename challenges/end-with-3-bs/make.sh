if [ -z "$1" ]; then
    echo "Usage: $0 <input_string>"
    exit 1
fi

gcc end-with-3-bs.c -Wall -O3 -g -o 3-bs
./3-bs "$1"

rm -if 3-bs
