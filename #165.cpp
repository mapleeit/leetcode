#include <iostream>
#include <vector>

using namespace std;
// My first stupid solution which cost too much memory to be accepted;

// int compareVersion(string version1, string version2) {
// 	vector<string> str1;
// 	vector<string> str2;
// 	auto pos1 = version1.begin(),
// 		 pos2 = version2.begin();
// 	for(auto it = version1.begin();it != version1.end();it++){
// 		if (*it == '.')
// 		{
// 			str1.push_back(version1.substr(pos1 - version1.begin(), it - pos1));
// 			pos1 = it + 1;
// 		}
// 		if (it == version1.end() - 1)
// 		{
// 			str1.push_back(version1.substr(pos1 - version1.begin(), it - pos1 + 1));
// 		}
// 	}
// 	for(auto it = version2.begin();it != version2.end();it++){
// 		if (*it == '.')
// 		{
// 			str2.push_back(version2.substr(pos2 - version2.begin(), it - pos2));
// 			pos2 = it + 1;
// 		}
// 		if (it == version2.end() - 1)
// 		{
// 			str2.push_back(version2.substr(pos2 - version2.begin(), it - pos2 + 1));
// 		}
// 	}
// 	int length = str1.size() > str2.size() ? str1.size() : str2.size();
// 	if (str1.size() > str2.size())
// 	{
// 		for (int i = 0; i <= length - str2.size(); ++i)
// 		{
// 			str2.push_back("0");
// 		}
// 	}else{
// 		for (int i = 0; i <= length - str1.size(); ++i)
// 		{
// 			str1.push_back("0");
// 		}
// 	}
// 	cout << "str1:" << str1.size() << endl;
// 	for(auto it = str1.begin(); it != str1.end();it++){
// 		cout << *it << endl;
// 	}
// 	cout << "str2:" << str2.size() << endl;
// 	for(auto it = str2.begin(); it != str2.end();it++){
// 		cout << *it << endl;
// 	}

// 	for (int i = 0; i < length; ++i)
// 	{
// 		if(stoi(str1[i]) > stoi(str2[i])){
// 			return 1;
// 		}else if (stoi(str1[i]) < stoi(str2[i]))
// 		{
// 			return -1;
// 		}
// 	}
// 	return 0;
// }


// My second solution which I'm quite proud of.
// takes 4ms
// recursion
int compareVersion(string version1, string version2){
	cout << endl;
	int i = 0,
		j = 0,
		n1 = 0,
		n2 = 0;
	while(version1[i] && version1[i] != '.'){
		n1 *= 10;
		n1 += (version1[i++] - '0');
		
	}
	if (version1[i] == '.') 
		version1 = version1.substr(i + 1);
	else
		version1 = "0";
	cout << n1 << endl;
	cout << version1 << endl;
	while(version2[j] && version2[j] != '.'){
		n2 *= 10;
		n2 += (version2[j++] - '0');
	}
	if (version2[j] == '.') 
		version2 = version2.substr(j + 1);
	else
		version2 = "0";
	cout << n2 << endl;
	cout << version2 << endl;

	if ( n1 > n2)
	{
		return 1;
	}else if ( n1 < n2)
	{
		return -1;
	}else if (!(version1 == "0" && version2 == "0") && n1 == n2)
	{
		return compareVersion(version1, version2);
	}else
	return 0;
}

int main(){
	// cout << compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000", "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000");
	cout << compareVersion("01.0.0.0", "1.0.0.0.11");
	return 0;
}