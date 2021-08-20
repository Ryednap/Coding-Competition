red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


#execution
for((i = 0; ; ++i)); do
	./gen $i > in;
	./b < in > out1;
done
