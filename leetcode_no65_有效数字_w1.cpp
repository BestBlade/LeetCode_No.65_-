/* ------------------------------------------------------------------|
有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：

["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
部分无效数字列举如下：

["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。

 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = ".1"
输出：true
 

提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：5.7 MB, 在所有 C++ 提交中击败了96.31%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

bool isNumber(string s) {
    bool sign = 0;
    bool num = 0;
    bool dec = 0;
    int point = 0;
    int exp = 0;
    
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-') {
            //不能出现两个符号
            if (sign) {
                return false;
            }
            //如果符号位在最开始或者紧跟e后，是有效的符号位
            if (i == 0 || s[i - 1] == 'E' || s[i - 1] == 'e') {
                sign = 1;
            }
            //符号不能出现在其他位置
            else {
                return false;
            }
        }
        else if (s[i] == '.') {
            //点不能在e之后，并且只能存在一个点
            if (exp || point) {
                return false;
            }
            point = 1;
        }
        else if (s[i] == 'e' || s[i] == 'E') {
            //如果存在一个e或者e前的数不是一个有效的整数或者小数时，错误
            if (exp || (num == 0 && dec == 0)) {
                return false;
            }
            //否则就是有效的e，允许后面出现符号和整数
            //因此重置符号位，整数位，小数位状态，将e的标识符写为1
            else {
                sign = 0;
                num = 0;
                dec = 0;
                exp = 1;
            }
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            //如果有小数点，当前数字就是小数位，小数位有效
            if (point) {
                dec = 1;
            }
            //否则就是整数位，整数位有效
            else {
                num = 1;
            }
        }
        else {
            //其他字符直接返回
            return false;
        }
    }
    //返回是否构成了有效的整数或者小数
    return num || dec;
}

int main() {
    string s = "3.";
    isNumber(s);
}