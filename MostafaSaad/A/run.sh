command="";
if [ $#!=2 ]; then
	command="fsanitize=address";
fi

g++ -std=c++17 "$1.cpp" -o $1 -Wall -Wshadow -O2 -$command -DLOCAL