class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        unsigned sLength = s.size();
        char dict[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        for(auto c : s){
            int value = searchDict(c, dict, 26);
            result += value * mathPower(26, sLength - 1);
            sLength--;
        }
        return result;
    }
    int searchDict(char c, char arr[], int length){
        int result;
        for (int i = 0; i < length; i++){
            if(arr[i] == c){
                result =  i + 1;
            }else{
                result = result ? result : 0;
            }
        }
        return result;
    }
    int mathPower(int base, int iterationTime){
        int result = 1;
        for(int i = 0; i < iterationTime; i++){
            result = result * base;
        }
        return result;
    }
};