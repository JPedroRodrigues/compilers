if [ -z "$1" ]; then
	echo "Usage: $0 <input_string>"
	exit 1
fi

gcc odd-a.c -Wall -g -O3 -o odd-a
./odd-a "$1"

rm -if odd-a

