#include <iostream>
using namespace std;

// 创建对象时，分配内存空间的大小是由该类的成员变量决定
struct Date {
    // 1.可以查查 这里成员变量类型不同所占的内存大小，
    // 如char.double.int这些类型组成(参考C中的对齐补齐)
    // 2.成员变量地址是相对对象的地址，也就是year的地址永远都是0
    int year;
    int month;
    int day;
    // 方法不占任何内存，方法在创建完都是放在代码区的，方法名是个函数指针。
    void show() {
        cout << year << ' ' << month << ' ' << day << endl;
    }
};

// 如果传入的是数组，则*ds是传入数组的首地址
void print(Date *ds, int n, int Date::*pd) {
    for (int i=0; i<n; i++) {
        cout << ds[i].*pd << endl;
    }
}

int main() {
    int name;
    // 获取name地址
    int *p1 = &name;
    
    // 获取成员变量地址
    int Date:: *py = &Date::year;
    int Date:: *pm = &Date::month;
    int Date:: *pd = &Date::day;
    
    // cout拒绝输出成员变量的地址
    // 之所以打印出来的是1，是表示这里确实是个地址
//    cout << py << endl;
//    cout << pm << endl;
//    cout << pd << endl;
    
    // 但是C++完全兼容C，所以我们可以使用C的打印函数
    printf("py = %p\n", py);
    printf("py = %p\n", pm);
    printf("py = %p\n", pd);
    
    // 查询对象所占的内存空间
//    Date d;
//    cout << sizeof(d) << endl;
    
    // 首先明确: 下面这个对象d创建在栈内
    Date d;
    d.year = 2015;
    // 通过成员变量指针进行赋值
    // .* 是一个运算符，不可以分开(可以这样理解: *py就是成员变量本身year，d.*py也就是d.year)
    d.*py = 3000;
    cout << d.year << endl;
    d.*pm = 1;
    d.*pd = 9;
    d.show();
    
    // 首先明确: 下面这个对象创建在堆内
    Date *pd2 = new Date;
    // 个人理解：指针访问成员变量需要使用->
    // 下两行同上原理, ->* 也是一个运算符，不可分开
    pd2->year = 2015;
    pd2->*py = 3000;
    
    cout << "============" << endl;
    Date ds[5] = {{2011,1,9},{2012,2,3},{2013,4,6},{2014,7,8},{2015,10,2}};
    print(ds, 5, &Date::year);
    
    return 0;
}


// a.成员指针是一种相对地址
// b.结构体中的成员(包括变量和函数)的相对地址获取方式
//     &结构类型名::成员
// c.声明成员指针变量
//     成员类型 结构类型名::*指针变量名
// d.通过成员指针访问结构成员
//     结构变量 .* 指针变量名
//     结构地址 ->* 指针变量名
