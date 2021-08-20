for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in
    ./D < in > out1
    ./D1 < in > out2
     diff -w out1 out2 || break
    #diff -w <(./G < int) <(./brute < int) || break
done
