red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
blue=$(tput setaf 32);

g++ "gen.cpp" -o "gen" -Wall -O2 -fsanitize=address -DLOCAL
g++ "brute.cpp" -o "brute" -Wall -O2 -fsanitize=address -DLOCAL

#execution
for((i = 0; ; ++i)); do
	./gen  > in;
	./b < in > out1;
	./brute < in > out2;
	if cmp -s out1 out2; then 
		echo "Case $i ${green}PASSED ${reset}"
	else
		echo "Case $i ${red}FAILED ${reset}"
		echo "${blue}Input: ${reset}"
		cat in

		echo "${blue}Output: ${reset}"
		cat out1

		echo "${blue}Expected: ${reset}"
		cat out2
		break
	fi
done
