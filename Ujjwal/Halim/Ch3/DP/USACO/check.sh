for ((i = 0; ;i++)); do
    ./gen $i > in
    ./Brute < in > out1
    ./Brute < in > out2
    diff out1 out2
    echo "Test Case ${i} Passed"
done;