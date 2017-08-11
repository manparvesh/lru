red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

g++ lru.cpp
if [ $? -eq 0 ]; then
    echo "${green}Compilation OK${reset}"
    ./a.out < in > out
    python checker.py out result
else
    echo "${red}Compilation FAIL${reset}"
fi
