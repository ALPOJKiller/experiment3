#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<bool> is_prime(100001, true);

/**
 * 筛法，初始化素数表
 */
void init() {
    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;
    for (unsigned i = 2; i <= 100000 / 2; ++i) {
        if (is_prime[i]) {
            //将i*j标记为非素数
            for (unsigned j = 2; i * j <= 100000; ++j) {
                is_prime[i * j] = false;
            }
        }
    }
}

/**
 * 判断是否是真素数
 * @param n 要判断的数
 * @return 是真素数返回true，否则返回false
 */
bool is_real_prime(unsigned n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return is_prime[n] && is_prime[stoi(s)];
}

int main() {
    init();
    unsigned m, n;
    cin >> m >> n;
    // 判断是否找到了素数
    bool already_find_one = false;
    for (unsigned i = m; i <= n; ++i) {
        if (is_real_prime(i)) {
            if (already_find_one)            //already_find_one为true表示前面已经找到过素数
                cout << ',';            //故应该输出逗号
            else                            //否则就是第一次找到素数
                already_find_one = true;//更新already_find_one，不输出逗号
            cout << i;
        }
    }
    if (!already_find_one) {
        cout << "No";
    }
    return 0;
}
