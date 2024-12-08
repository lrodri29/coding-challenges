#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int num_entries = 1000;

int main() {
    std::vector<int> l, r;
    for (int i = 0; i < num_entries; i++) {
        int x, y;
        std::cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int sum = 0;
    for (int i = 0; i < num_entries; i++) {
        sum += abs(l[i] - r[i]);
    }
    printf("Sum: %d\n", sum);
    return sum;
}