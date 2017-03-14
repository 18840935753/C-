#include <iostream>
using namespace std;

struct Date {
    
    Date() {
        cout << "Date()" << endl;
    }
    
    ~Date() { 
        cout << "~Date()" << endl;
    }
    
    int y, m, d;
    void show() {
        cout << y << '-' << m << '-' << d << endl;
    }
};

// 全局区的变量在程序开始运行时，就创建出来，在程序结束时销毁(换句话说，在程序运行一半的时候，如果你想把全局区内存销毁，是不可能的)
int a = 10; // 全局区: 因为没在方法里开辟栈的空间，也没有new在堆里开辟空间
Date d;     // 全局区: 因为没在方法里开辟栈的空间，也没有new在堆里开辟空间

// oc的MRC引用计数相比于C++的delete要好一些, 在多人开发中，很难去辨别其他人是否需要该对象，是否需要delete(delete对象的时候慎用), 所以很多时候C++也会去使用一套引用计数机制
void fa() {
    Date d; // 栈
    
    Date *p = new Date; // 堆
    p->y = 2015;
    delete p;
    // C99
    // p = NULL;
    // C11
    p = nullptr;
}

int main() {
    cout << "1------------------>" << endl;
    fa();
    cout << "2------------------>" << endl;
    Date d2;
    cout << "3------------------>" << endl;
    
    // 创建三个Date对象
    Date *pd2 = new Date[3];
    
    // 释放数组
    delete[] pd2;
    cout << "4------------------>" << endl;
    
    // 99%的情况new都是在堆中开辟空间
    int *pi = new int;
    int *pi1 = new int[5];
    
    // 在堆中开辟一块int型空间，并且用10给这块空间进行初始化
    int *pi2 = new int(10);
    cout << *pi2 << endl;
    delete pi2;
    pi2 = nullptr;
    
    cout << "5------------------>" << endl;
    // 栈中开辟1024个char型的空间
    char buf[1024];
    
    // 定位分配，在制定内存中开辟空间(只有指定分配，会在new的时候，在制定的内存中，开辟内存空间)
    // 这里开辟的空间不需要delete，因为开辟的空间在栈里面，在函数走完，会自动delete。
    int *pi3 = new(buf) int(12345);
    cout << "6------------------>" << endl;
    cout << *pi3 << endl;
    
    return 0;
}






