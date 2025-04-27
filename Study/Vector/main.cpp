#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 可動態擴充的陣列
    vector<int> a;

    // 可以透過push_back()加入元素
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    // 透過for loop遍歷
    cout << "for Loop:" << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    // 透過for-each遍歷
    cout << "for-each:" << endl;
    for (int item : a){
        cout << item << " ";
    }
    cout << endl;

    // 可以透過pop_back()移除最後一個元素
    a.pop_back();   // 此行會移除30

    cout << "befor pop_back():" << endl;
    for (int item : a) { cout << item << " "; }

    // 檢查是否為空
    cout << endl << a.empty();
    
    // 清空所有元素
    a.clear();
    cout << endl << a.empty();

    return 0;
}

