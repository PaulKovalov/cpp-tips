#include <iostream>
#include <string>

using namespace std;

bool isStringPrefixOfAnother(string &str, string &prefix) {
    // O(prefix) time complexity, O(1) space complexity, uses traits::compare
    return str.compare(0, prefix.size(), prefix) == 0;
}

int main() {
    string str, prefix;
    cin >> str >> prefix;
    cout << isStringPrefixOfAnother(str, prefix) << endl;
    
    return 0;
}
