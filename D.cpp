#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<bool> is_prime(100001,true);
void init() {
        is_prime[0] = false;
        is_prime[1] = false;
        is_prime[2] = true;
        for(unsigned i=2;i<=100000;++i) {
            if(is_prime[i]) {
                for(unsigned j=2;i*j<=100000;++j) {
                    is_prime[i*j] = false;
                }
            }
        }
}
bool is_real_prime(unsigned n) {
    string s = to_string(n);
    reverse(s.begin(),s.end());
    return is_prime[n] && is_prime[stoi(s)];
}
int main() {
    init();
    unsigned m,n;
    cin >> m >> n;
    bool already_find_one = false;
    for(unsigned i=m;i<=n;++i) {
        if(is_real_prime(i)) {
            if(already_find_one)
                    cout << ',';
            else
                    already_find_one = true;
            cout << i;
        }
    }
    if(!already_find_one) {
        cout << "No";
    }
    return 0;
}
