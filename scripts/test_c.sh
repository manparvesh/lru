red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

echo ""
echo "=================================="
echo "Running tests for C implementation"
echo "=================================="

gcc ../c/lru.c
if [ $? -eq 0 ]; then
    echo "${green}Compilation OK${reset}"
    ../c/a.out < ../c/in > ../c/out
    python checker.py ../c/out ../c/result
else
    echo "${red}Compilation FAIL${reset}"
    exit 1
fi
