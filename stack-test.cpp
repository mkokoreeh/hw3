#include "stack.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    Stack<int> list;
    int itemF = 7;
    int itemL = 2;
    cout  << "Should be True: " << list.empty() << endl;
    list.push(itemF);
    cout << "Pushed! " << endl;
    cout << "Size: " << list.size() << endl;
    cout <<  "Should be False: " << list.empty() << endl;
    list.pop();
    cout << "Popped! " << endl;
    cout << "Should be True: " << list.empty() << endl;
    cout << list.size() << endl;
    list.push(itemL);
    list.push(itemF);
    cout << "Pushed Twice! " << endl;
    cout << "Size: " << list.size() << endl;
    cout << "Top Value: " << list.top() << endl;
}