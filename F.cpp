#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// 等级对应的字符
const char level_char[] = {'D', 'C', 'B', 'A', 'S'};

/**
 * 计算等级
 * @param win 胜负情况序列
 * @return 最终等级对应的字符
 */
char caculate_level(vector<bool> win) {
    int level_score = 0;                            //当前等级的积分
    unsigned level = 0;                             //当前等级
    bool in_set_level = false;                      //是否在定级赛状态
    unsigned set_level_win = 0;                     //定级赛胜利次数
    unsigned set_level_count = 0;                   //定级赛已打场数
    for (auto w:win) {
        if (in_set_level) {                         //定级赛状态
            ++set_level_count;
            set_level_win += (unsigned) w;
            if (set_level_count == 2) {             //已打两场
                if (set_level_win == 0) {           //连输
                    level_score = 60;
                    set_level_count = 0;
                    in_set_level = false;
                } else if (set_level_win == 2) {    //连赢
                    ++level;
                    level_score = 0;
                    set_level_count = 0;
                    set_level_win = 0;
                    in_set_level = false;
                }
            }
            if (set_level_count == 3) {             //已打三场
                if (set_level_win >= 2) {           //两胜
                    ++level;
                    level_score = 0;
                    set_level_count = 0;
                    set_level_win = 0;
                } else {                            //少于两胜
                    level_score = 60;
                    set_level_count = 0;
                    set_level_win = 0;
                }
                in_set_level = false;
            }
        } else {                                    //普通状态
            if (w) {
                level_score += 10;
            } else {
                level_score -= 5;
                if (level_score < 0)                //防止减过0
                    level_score = 0;
            }
            if (level_score >= 100) {               //注意此处用>=而非==，因为可能会出现105分的情况（11场10胜）
                in_set_level = true;
            }
        }
    }
    if (level > 4)                                  //4级以上返回4级
        level = 4;
    return level_char[level];                       //返回对应字符
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
