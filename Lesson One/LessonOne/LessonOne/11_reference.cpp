#include <iostream>
using namespace std;

int main() {
    int x = 200;
    // 引用其实就是别名, 也是引用的变量的本身
    int &r = x;
    
    x += 200;
    cout << r << endl;
    r += 100;
    cout << x << endl;
    
    int y = 300;
    r = y; // 赋值
    y += 200;
    cout << y << endl;
    cout << r << endl;
    
    // 引用在创建的时候就必须引用一个变量
    // 引用一旦创建就不能引用新的变量(永远不能), 而指针可以更改指向的对象
    int &r2 = x;
    r2 = y;
    
    return 0;
}
