#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int num_entries = 1000;

int main() {

    std::vector<int> l, r;

    // For every entry in the input file, create 
    // append a our left and right arrays
    for (int i = 0; i < num_entries; i++) {
        int x, y;
        std::cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
    }
    
    // Sort the arrays
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    // Record in a map the number of times a number 
    // on the right column is repeated
    std::map<int, int> frequency;
    for (int i = 0; i < num_entries; i++) {
        frequency[r[i]]++;
    }

    int sum = 0;
    for (int i = 0; i < num_entries; i++) {
        // For every time a number on the left 
        // is seen on right, multiply that number by
        // the number of times it was seen on the right
        sum += l[i]*frequency[l[i]];
    }
    printf("Sum: %d\n", sum);
    return sum;
}