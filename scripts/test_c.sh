red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

echo ""
echo "=================================="
echo "Running tests for C implementation"
echo "=================================="

cd ../c/

gcc qnode.c queue.c hash.c lru.c
if [ $? -eq 0 ]; then
    echo "${green}Compilation OK${reset}"
    ./a.out # > out
    python ../scripts/checker.py out result
else
    echo "${red}Compilation FAIL${reset}"
    exit 1
fi
