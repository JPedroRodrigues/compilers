if [ -z "$1" ]; then
    echo "Usage $0 <input_string>"
    exit 1
fi

gcc length-multiple-of-3.c -Wall -O3 -g -o length-multiple-of-3
./length-multiple-of-3 "$1"

rm -if length-multiple-of-3
