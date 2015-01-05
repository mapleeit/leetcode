#include <iostream>

class Solution {
public:
    int singleNumber(int A[], int n) {
        int r = 0;
        for (int i = 0; i < n; ++i)
        {
        	r ^= A[i]; // 按位异或
        }
        return r;
    }
};

Solution sol;

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 1, 2, 3, 4, 4, 5, 3};
	int result = sol.singleNumber(arr, 9);
	printf("%d\n", result);
	return 0;
}