// instead of using 1e9 for a big number, -1e9 for small number, it is better
// to use something from std library, like numeric_limits

#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "Int max is " << numeric_limits<int>::max() << endl;
    cout << "Int min is " << numeric_limits<int>::min() << endl;
    return 0;
}
