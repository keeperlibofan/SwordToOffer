#include <iostream>
#include "src/13_movingCount/movingCount.cpp"

using namespace std;
int main() {
    auto a = 0;
    a = Solution::movingCount(0, 10, 10);
    cout << a;
    return a;
}
