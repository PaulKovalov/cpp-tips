// it is sometimes good to reserve space for containers in advance, to avoid copying data when realloc is happening
// the program demonstrates the difference in time between inserting to a reserved container vs non reserved
// The result is especially visible on large numbers. For numbers less then 1e8, reserve doesn't bring significant performance
// improvement though

#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

int main() {
    int N = 100000000;
    /**
     * Vectors example 
     * */
    vector<int> v_reserved, v_not_reserved;
    v_reserved.reserve(N + 1);
    // insert N elements to reserved vector
    auto start_reserved_insert = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        v_reserved.push_back(i);
    }
    auto stop_reserved_insert = high_resolution_clock::now();
    auto reserved_duration = duration_cast<microseconds>(stop_reserved_insert - start_reserved_insert).count();
    cout << "Insertion to a reserved vector took " << reserved_duration << " microseconds" << endl;
    // insert N elements to a regular vector
    auto start_not_reserved_insert = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        v_not_reserved.push_back(i);
    }
    auto stop_not_reserved_insert = high_resolution_clock::now();
    auto not_reserved_duration = duration_cast<microseconds>(stop_not_reserved_insert - start_not_reserved_insert).count();
    cout << "Insertion to a non reserved vectoor took " << not_reserved_duration << " microseconds" << endl;

    /**
     * Strings example
     * */
    string s_reserved, s_not_reserved;
    s_reserved.reserve(N + 1);
    // insert N chars to reserved string
    start_reserved_insert = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        s_reserved += 'a';
    }
    stop_reserved_insert = high_resolution_clock::now();
    reserved_duration = duration_cast<microseconds>(stop_reserved_insert - start_reserved_insert).count();
    cout << "Insertion to a reserved string took " << reserved_duration << " microseconds" << endl;
    // insert N chars to a not reserved string
    start_not_reserved_insert = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        s_not_reserved += 'a';
    }
    stop_not_reserved_insert = high_resolution_clock::now();
    not_reserved_duration = duration_cast<microseconds>(stop_not_reserved_insert - start_not_reserved_insert).count();
    cout << "Insertion to a non reserved string took " << not_reserved_duration << " microseconds" << endl;
    return 0;
}
