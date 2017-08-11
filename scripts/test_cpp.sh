red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

echo "===================================="
echo "Running tests for C++ implementation"
echo "===================================="

g++ -std=c++11 ../cpp/lru.cpp
if [ $? -eq 0 ]; then
    echo "${green}Compilation OK${reset}"
    ../cpp/a.out < ../cpp/in > ../cpp/out
    python checker.py ../cpp/out ../cpp/result
else
    echo "${red}Compilation FAIL${reset}"
    exit 1
fi
