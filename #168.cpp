// 折腾一下午没搞出来，结果人家一行代码把我给虐了，知识水平还是得提高啊！
class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26  + 'A');
    }
};