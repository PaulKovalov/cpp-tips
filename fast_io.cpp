#include <iostream>
using namespace std;

// code that speed up read/write to standard IO
static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
};

int main() {
    cout << "Some very fast output here" << endl; 
    return 0;
}
