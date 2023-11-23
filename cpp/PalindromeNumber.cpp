class Solution {
public:
    bool isPalindrome(int x) {
        //xが負の場合は回文にはならない
        if (x < 0){
            return false;
        }
        //xの桁を反転させる
        int original = x;
        int64_t reverse = 0;
        while (x > 0){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }
        //originalと反転させたreverseが一致すればTrue
        return original == reverse;
    }
};