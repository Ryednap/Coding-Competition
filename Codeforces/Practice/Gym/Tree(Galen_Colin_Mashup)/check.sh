for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
     ./G < int > out1
     ./brute < int > out2
     diff -w out1 out2 || break
    #diff -w <(./G < int) <(./brute < int) || break
done
