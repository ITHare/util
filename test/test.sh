echo "EXPECT -Wsign-compare WARNINGS in the next compile" 
g++ -std=c++1z -lstdc++ -Wall -Wextra -Wno-missing-braces -DWARNINGS_EXPECTED -o test test.cpp
if [ ! $? -eq 0 ]; then
  exit 1
fi
./test
if [ ! $? -eq 0 ]; then
  exit 1
fi
echo "NO warnings expected in this one" 
g++ -std=c++1z -lstdc++ -Wall -Wextra -Wno-missing-braces -Werror -o test test.cpp
if [ ! $? -eq 0 ]; then
  exit 1
fi
./test
if [ ! $? -eq 0 ]; then
  exit 1
fi
echo "OK"
