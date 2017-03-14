#include <iostream>
using namespace std;

// 联合中所有变量 都共享同一块内存地址
union MyUnion {
    int x;
    int y;
    char cs[4];
};

// 匿名联合
union {
    int a;
    int b;
};
a = 1

// “联合”与“结构”有一些相似之处。但两者有本质上的不同。在结构中各成员有各自的内存空间， 一个结构变量的总长度是各成员长度之和（空结构除外，同时不考虑边界调整）。而在“联合”中，各成员共享一段内存空间， 一个联合变量的长度等于各成员中最长的长度。应该说明的是， 这里所谓的共享不是指把多个成员同时装入一个联合变量内， 而是指该联合变量可被赋予任一成员值，但每次只能赋一种值， 赋入新值则冲去旧值。

int main() {
    MyUnion myUnion;
    myUnion.x = 0x41424344;
    cout << myUnion.y << endl;
    // myUnion.y += 300;
    cout << myUnion.x << endl;
    cout << myUnion.cs << endl;
    
    return 0;
};
