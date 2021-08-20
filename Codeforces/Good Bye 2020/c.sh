for((i = 1; ; ++i)); do
    echo $i
    ./Gen $i > bin
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./a < bin) <(./brute < bin) || break
done
