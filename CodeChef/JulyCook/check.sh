
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`


#execution
for((i = 0; ; ++i)); do
	./gen $i > in;
	./f < in > out1;
	./brute < in > out2;
	if cmp -s out1 out2; then 
		echo "Case $i ${green}PASSED ${reset}"
	else
		echo "Case $i ${red}FAILED ${reset}"
		break
	fi
done
