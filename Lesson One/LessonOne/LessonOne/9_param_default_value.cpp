#include <iostream>
using namespace std;

//C++中参数可以给默认值, 默认值只能从右向左给(也就是 最后一个有默认值，倒数第二个才会有，以此类推)

void print(int *a, int n, bool isSHow=true) {
    
    cout << &a << endl;
    
    for (int i=0; i<n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

// inline 内联函数，提高函数的调用性能 (不是所有的前面加inline的函数都是内联函数)
// 函数执行，在栈内开辟一个空间，而内联函数不需要开辟空间，而是在调用它的地方，相当于把代码拷贝在调用它的地方
// 函数前加inline，是向编译器申请该函数希望成为内联函数，申请成功的条件是: 函数体中没有过多的代码和复杂逻辑，编译器才会同意这个申请。

inline void print(int x) {
    
}

int main() {
    
    int is[5] = {1,2,3,4,5};
    print(is, 5);
    
    return 0;
}
