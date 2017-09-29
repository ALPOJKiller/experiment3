#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const char level_char[] = {'D','C','B','A','S'};
char caculate_level(vector<bool> win) {
	int level_score = 0;
	unsigned level = 0;
	bool in_set_level = false;
	unsigned set_level_win = 0;
	unsigned set_level_count = 0;
	for(auto w:win) {
		//cout << w << ' ';
		if(in_set_level) {
			++set_level_count;
			set_level_win += (unsigned)w;
			//cout << "W" <<set_level_win << ' ';
			if(set_level_count == 2) {
				if(set_level_win == 0) {
					//cout << "Fail2 ";
					level_score = 60;
					set_level_count = 0;
					in_set_level = false;
					//cout << "Fail ";
				} else if(set_level_win == 2) {
					//cout << "Win 2 ";
					++ level;
					level_score = 0;
					set_level_count = 0;
					set_level_win = 0;
					in_set_level = false;
					//cout << "Success ";
				}
			}
			if(set_level_count == 3) {
				if(set_level_win >= 2) {
					//cout << "3Win2 ";
					++ level;
					level_score = 0;
          set_level_count = 0;
          set_level_win = 0;
					//cout << "Success ";
				} else {
					//cout << "3Fail2 ";
					level_score = 60;
					set_level_count = 0;
					set_level_win = 0;
					////cout << "Fail ";
				}
				in_set_level = false;
			}
		}
		else {
			if(w) {
				level_score += 10;
			} else {
				level_score -= 5;
				if(level_score < 0)
					level_score = 0;
			}
			if(level_score >= 100) {
				in_set_level = true;
				////cout << "Jinji";
			}
		}
	}
	if(level > 4)
		level = 4;
	return level_char[level];
}
using namespace std;
int main() {
	unsigned n;
	while (cin >> n) {
		std::vector<bool> v;
		for (unsigned i = 0; i < n; ++i) {
			bool pass;
			cin >> pass;
			v.push_back(pass);
		}
		cout << caculate_level(v) << endl;
	}
	return 0;
}
