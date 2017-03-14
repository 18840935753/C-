//
//  main.cpp
//  LessonTwo
//
//  Created by kang chao on 2017/2/28.
//  Copyright © 2017年 kang chao. All rights reserved.
//

#include <iostream>
using namespace std;

// 引用传递
void fa(int &r) {
    r++;
}
// 地址传递
void fb(int *p) {
    (*p)++;
}
// 值传递
void fc(int i) {
    i++;
}

// 借助第三个变量改变两个值
void swap1(int *a, int *b) {
    int p = (*a);
    (*a) = (*b);
    (*b) = p;
}

// 不借助第三个变量改变两个值
void swap2(int *n, int *m) {
//    (*n) = (*m)-(*n);
//    (*m) = (*m)-(*n);
//    (*n) = (*n)+(*m);
    
    // 异或操作
    (*n) = (*m)^(*n);
    (*m) = (*m)^(*n);
    (*n) = (*m)^(*n);
}

// 返回int类型的引用
int& fd(int &r) {
    r++;
    return r;
}

void ff(const int &r) {
    // 常量在这里面就不能改变
}

int& fe() {
    int x = 100;
    // 永远不要返回局部变量的引用, 无意义
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int x = 100;
    fa(x);
    cout << x << endl;
    fb(&x);
    cout << x << endl;
    fc(x);
    cout << x << endl;
    
    
    int a = 5;
    int b = 3;
    swap1(&a, &b);
    cout << a << endl;
    cout << b << endl;
    
    int n = 5;
    int m = 3;
    swap1(&n, &m);
    cout << n << endl;
    cout << m << endl;
    
    // 返回int类型的引用
    x = 200;
    int& r2 = fd(x);
    cout << r2 << endl;
    r2++;
    cout << x << endl;
    
    // 参数是引用类型
    fa(x);
    // 如果要引用常量只能使用常引用，即前面加上const
    const int &r5 = 500;
    ff(r5);
    
    return 0;
}
