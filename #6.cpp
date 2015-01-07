#include <iostream>

using namespace std;

string convert(string s, int nRows) {
        string result = "";
        if (nRows == 1) return s;
        for (int i = 0; i < nRows; i++){
            if (i == 0)
            {
                for (int j = i; j < s.length(); j += 2 * (nRows - 1)){
                    result += s[j];
                }                 
            }else
            // result += "\n";
            if (i == nRows - 1)
            {
                for (int j = i; j < s.length(); j += 2 * (nRows - 1)){
                    result += s[j];
                } 
            }else{
                // result += "\n";
                int temp = 2 * (nRows - i - 1);
                int j = i;
                while (j < s.length()){
                    result += s[j];
                    j += temp;
                    temp = 2 * (nRows - 1) - temp;
                }
                // for (int j = i; j < s.length(); j += 2 * (nRows - 1) - temp){
                //     result += s[j];
                //     if (j + temp < s.length())
                //     {                    
                //         temp = 2 * (nRows - 1) - temp;
                //     }
                // } 
            }
            // result += "\n";
        }
        return result;
    }

int main(){
	cout << convert("ABCDEFGH", 4) << endl;
    // PAHNAPLSIIGYIR
	return 0;
}