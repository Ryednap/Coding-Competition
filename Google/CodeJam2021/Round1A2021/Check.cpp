for ((i = 0; ; ++i)); do
	./Gen $i > in
	./A < in > out1
	./Brute < in > out2
	diff out1 out2 || break

