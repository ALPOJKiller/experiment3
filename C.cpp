#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 将两个vector逐项相乘
 * @param v1 其中一个vector
 * @param v2 另一个vector
 * @return 相乘的结果
 */
vector<int> product(const vector<int> &v1, const vector<int> &v2) {
    vector<int> result;
    for (auto it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end(); ++it1, ++it2) {
        result.push_back(*it1 * (*it2));
    }
    return result;
}

int main() {
    unsigned n;
    cin >> n;
    vector<int> v1, v2;
    for (unsigned i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v1.push_back(v);
    }
    for (unsigned i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v2.push_back(v);
    }
    auto p = product(v1, v2);
    cout << accumulate(p.begin(), p.end(), 0);
    return 0;
}

