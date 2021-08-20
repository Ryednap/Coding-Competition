for ((i = 0; ; i++)); do 
	./gen $i $i > in
	./c < in > out1
	./brute < in > out2
	diff out1 out2 || break;
	echo "$i Passed"
done 
