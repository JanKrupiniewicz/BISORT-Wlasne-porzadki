#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> showSteps;
    deque<int> shelf(n);
    deque<int> sortedShelf(n);

    deque<int> order(n);
    deque<int> steps;

    for (int i = 0; i < n; i++) {
        cin >> shelf[i];
        sortedShelf[i] = shelf[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }

    int step = 0;
    while (step != n) {
        cin >> step;
        showSteps.insert(step);
    }
    
    sort(sortedShelf.rbegin(), sortedShelf.rend());

    unordered_map<int, int> indexMap;
    for (int i = 0; i < sortedShelf.size(); i++) {
        indexMap[shelf[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int kthMax = order[i] - 1;
        int kthMaxNS = indexMap[sortedShelf[kthMax]];

        int kHash1 = sortedShelf[kthMax];
        int kHash2 = shelf[n - i - 1];

        swap(shelf[kthMaxNS], shelf[n - i - 1]);
        swap(indexMap[kHash1], indexMap[kHash2]);

        sortedShelf.erase(sortedShelf.begin() + kthMax);

        if (showSteps.find(i + 1) != showSteps.end()) {
            for (int i = 0; i < n; i++) {
                cout << shelf[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}