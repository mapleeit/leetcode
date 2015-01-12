// first idea, but can't be accepted because of the enormous memory cost
class MinStack {
private:
    std::stack<int> myStack;
    long min;
public:
    void push(int x) {
        if(myStack.empty()){
            myStack.push(0);
            min = x;
        }else{
            myStack.push(x - min);
            if(x - min < 0){
                min = x;
            }
        }
    }

    void pop() {
        if(myStack.empty())
            ;
        else{
            if(myStack.top() < 0){
                min = min - myStack.top();
                myStack.pop();
            }else{
                myStack.pop();
            }
        }
    }

    int top() {
        if(myStack.top() < 0){
            return min - myStack.top();
        }else{
            return min + myStack.top();
        }
    }

    int getMin() {
        return min;
    }
};


// second idea
// #include <iostream>

// using namespace std;

// int main(){
//     cout << std::numeric_limits<int>::max();
//     return 0;
// }

class MinStack {
private:
    std::stack<int> myStack;
    int min = std::numeric_limits<int>::max();
public:
    void push(int x) {
        if(x <= min){
            myStack.push(min);
            min = x;
            myStack.push(x);
        }else{
            myStack.push(x);
        }
    }

    void pop() {
        if(myStack.empty())
            ;
        else{
            if(myStack.top() == min){
                myStack.pop();
                min = myStack.top();
                myStack.pop();
            }else{
                myStack.pop();
            }
            if(myStack.empty()){
                min = std::numeric_limits<int>::max();
            }
        }
    }

    int top() {
        return myStack.top();
    }

    int getMin() {
        return min;
    }
};