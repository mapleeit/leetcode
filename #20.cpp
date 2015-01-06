// #include <iostream>
// #include <vector>
// #include <stack>


// using namespace std;

// void pringStack(stack<char> Stack){
// 	int size = Stack.size();
// 	for(int i = 0; i < size; i++){
// 		cout << Stack.top();
// 		Stack.pop();
// 	}	
// 	cout << size << endl;
// }

// int main(){
// 	stack<char> myStack;

// 	string s = "]";
// 	int i = 0;
// 	if (s[0] == ']')
// 		printf("wrong!!\n");
// 	for(auto it = s.begin(); it != s.end(); it++){
// 		if (*it == '[' || *it == '{' || *it == '(')
// 		{
// 			myStack.push(*it);
// 			pringStack(myStack);
// 		}else if (*it == ']'&& !myStack.empty() && myStack.top() == '[')
// 		{
// 			myStack.pop();
// 			pringStack(myStack);
// 		}else if (*it == '}'&& !myStack.empty() && myStack.top() == '{')
// 		{
// 			myStack.pop();
// 			pringStack(myStack);
// 		}else if (*it == ')'&& !myStack.empty() && myStack.top() == '(')
// 		{
// 			myStack.pop();
// 			pringStack(myStack);
// 		}
// 		i ++;
// 	}
// 	cout << i;
// 	if (myStack.empty())
// 	{
// 		printf("right\n");
// 	}else printf("wrong\n");
	
// }

class Solution {
public:
    bool isValid(string s) {
       std::stack<char> myStack;
       for(auto it = s.begin(); it != s.end();it++){
           if (*it == '(' || *it =='[' || *it == '{'){
               myStack.push(*it);
           }else if (*it == ')'){
               if (myStack.empty())return false;
               else if(myStack.top() == '('){
                   myStack.pop();    
               }else return false;
               
           }else if (*it == '}'){
               if (myStack.empty())return false;
               else if(myStack.top() == '{'){
                   myStack.pop();    
               }else return false;
           }else if (*it == ']'){
               if (myStack.empty())return false;
               else if(myStack.top() == '['){
                   myStack.pop();    
               }else return false;
           }
           
       }
       if (myStack.empty()) return true;
       else return false;
    }
};