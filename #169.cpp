// my stupid solution, though in my computer, it runs well. But can't be accepted;
// I use hash;

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int hashFunc(int n, int size){
	return size == 0 ? -1 : n % size;
}

int molAdd(int origin, int limit){
	return origin + 1 > limit ? (origin + 1) % limit : origin + 1;
}
void addHashELe(int n,int hashVal,int size,vector<int> &numberRecord){
	int halfSize = floor(size / 2);
	if (n == numberRecord[hashVal + halfSize] || numberRecord[hashVal + halfSize] == 0)
	{
		numberRecord[hashVal]++;
		numberRecord[hashVal + halfSize] = n;
	}else{
		// numberRecord[hashVal]++;
		// numberRecord[hashVal + halfSize] = n;
		addHashELe(n, molAdd(hashVal, halfSize), size, numberRecord);
	}
}

int majorityElement(vector<int> &num){
	int size = num.size();
	if (size == 1)
	{
		return num[0];
	}
	size = size % 2 == 0 ? size : size + 1;
	vector<int> numberRecord(size, 0);
	for(auto it = num.begin(); it != num.end(); it++){
		addHashELe(*it, hashFunc(*it, floor(size / 2)),size,numberRecord);
	}
	for(auto it = numberRecord.begin(); it != numberRecord.begin() + size / 2;it++){
		if (*it > floor(size / 2))
		{
			return *(it + size / 2);
		}
	}
	return -1;
}

int main(){
	vector<int> test;
	test.push_back(-1);
	test.push_back(1);
	test.push_back(1);
	test.push_back(1);
	test.push_back(2);
	test.push_back(1);
	// test.push_back(4);
	// test.push_back(4);
	for (auto it = test.begin(); it != test.end(); it++){
		cout << *it;
	}
	cout << endl;
	cout << majorityElement(test) << endl;
	// cout << majorityElement(test) << endl;
	return 0;
}

// this is a awesome solution that is very wonderful !
// o(1) memmory
// core method : The idea is to arrange the numbers in an order that no two successive numbers are same until all the remaining numbers are the same. Therefore, the last number will be the answer.
int majorityElement(vector<int> &num) {
    for (int i = 1, j = 1; j < num.size(); i++){
        if (num[i] == num[i - 1]){
            while (j < num.size() && num[j] == num[i]){
                j++;
            }
            if (j < num.size()){
                num[i] ^= num[j] ^= num[i] ^= num[j];
            }
        }else{
            j++;
        }
    }
    return num[num.size() - 1];
}