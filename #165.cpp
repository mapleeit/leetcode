#include <iostream>
#include <vector>

using namespace std;

int compareVersion(string version1, string version2) {
	vector<string> str1;
	vector<string> str2;
	auto pos1 = version1.begin(),
		 pos2 = version2.begin();
	for(auto it = version1.begin();it != version1.end();it++){
		if (*it == '.')
		{
			str1.push_back(version1.substr(pos1 - version1.begin(), it - pos1));
			pos1 = it + 1;
		}
		if (it == version1.end() - 1)
		{
			str1.push_back(version1.substr(pos1 - version1.begin(), it - pos1 + 1));
		}
	}
	for(auto it = version2.begin();it != version2.end();it++){
		if (*it == '.')
		{
			str2.push_back(version2.substr(pos2 - version2.begin(), it - pos2));
			pos2 = it + 1;
		}
		if (it == version2.end() - 1)
		{
			str2.push_back(version2.substr(pos2 - version2.begin(), it - pos2 + 1));
		}
	}
	int length = str1.size() > str2.size() ? str1.size() : str2.size();
	if (str1.size() > str2.size())
	{
		for (int i = 0; i <= length - str2.size(); ++i)
		{
			str2.push_back("0");
		}
	}else{
		for (int i = 0; i <= length - str1.size(); ++i)
		{
			str1.push_back("0");
		}
	}
	cout << "str1:" << str1.size() << endl;
	for(auto it = str1.begin(); it != str1.end();it++){
		cout << *it << endl;
	}
	cout << "str2:" << str2.size() << endl;
	for(auto it = str2.begin(); it != str2.end();it++){
		cout << *it << endl;
	}
	// cout << "compare : "<< endl;
	// cout << str1[0].compare(str2[0]) << endl;
	// cout << "str1:" << str1[1] << "str2:" << str2[1] << str1[1].compare(str2[1]) << endl;
	// cout << str1[2].compare(str2[2]) << endl;
	// cout << str1[3].compare(str2[3]) << endl;

	for (int i = 0; i < length; ++i)
	{
		if(stoi(str1[i]) > stoi(str2[i])){
			return 1;
		}else if (stoi(str1[i]) < stoi(str2[i]))
		{
			return -1;
		}
	}
	return 0;
}

int main(){
	cout << compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000", "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000");
	return 0;
}