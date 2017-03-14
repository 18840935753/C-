

#include <iostream>
using namespace std;

// C++中，结构体就是类
struct Date {
    int year;
    int month;
    int day;
    void show() {
        cout << year << '-' << month << '-' << day << endl;
    }
};

// 相当于再创建一个对象
void fa(Date d) {
    d.year++;
};

// 虽然相当于创建了一个新指针 但是指向的还是同一块内存空间
void fb(Date *d) {
    d->year++;
    // 或: (*d).year++;
};

// 返回一个对象
Date fc() {
    Date d;
    return d;
};

// 返回一个空指针
Date* fd() {
    return nullptr;
}

int main() {
    // 通过创建一个结构体对象, 对象在栈里(系统自动分配)
    Date d;
    d.year = 2015;
    d.month = 1;
    d.day = 8;
    d.show();
    
    // OC里面对象在堆区 指针对象在栈里（备注: OC里面的CG开头的都是C++里面的东西, 如CGPoint point = ....  是直接在栈里面开辟空间, point.x = 1000, 这不是OC里面的Set方法，而是C++里面的访问成员变量）
    
    
    // 该对象在堆区 自己开辟空间
    // Date *p = new Date;
    
    
    fa(d);
    cout << d.year << endl;
    fb(&d);
    cout << d.year << endl;
};



