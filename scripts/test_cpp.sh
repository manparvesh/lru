red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

echo "===================================="
echo "Running tests for C++ implementation"
echo "===================================="

cd ../cpp/

g++ -std=c++11 lru.cpp
if [ $? -eq 0 ]; then
    echo "${green}Compilation OK${reset}"
    ./a.out < in > out
    python ../scripts/checker.py out result
else
    echo "${red}Compilation FAIL${reset}"
    exit 1
fi
