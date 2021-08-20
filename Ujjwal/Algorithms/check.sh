for ((i = 0; ; i++)); do
	./Test $i > in
	(time ./SqrtDecomposition < in > out)
	./trivial < in > out2
	cmp --silent out out2 || (echo "The files are diff" && break)
done
