g++ -std=c++17 -Wshadow -Wall "$1.cpp" -o "$1" -g -fsanitize=address -fsanitize=undefined  -DLOCAL -D_GLIBCXX_DEBUG

    
