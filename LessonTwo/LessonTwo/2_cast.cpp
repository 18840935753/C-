#include <iostream>
using namespace std;

int main() {
    
    // 1. static_cast<类型>()
    // 转换时做静态检查，即在编译时进行
    // void*到其他指针的转换
    
    double d = 3.14;
    int x = static_cast<int>(d);
    cout << x << endl;
    void *pc = new long(12345);
    long *pl = static_cast<long*>(pc);
    cout << *pl << endl;
    
    // static_cast 在转换时会做类型检查，如果不合理拒绝操作
    // double *pd = static_cast<double*>(pl);
    
    // 2. reinterprect_cast<类型>()
    // 允许强转任何类型的指针
    // 把整数强转成指针，指针强转成整数
    // 通俗来讲: reinterpret_cast 类型转换比较强悍，你想转它就帮你转，但是不对结果负责
    
    // 含义是 用double类型的值去解释long型的空间
    double *pd = reinterpret_cast<double*>(pl);
    cout << *pd << endl;
    
    // 3. const_cast<类型>()
    // 去掉vc限制
    
    // 如果想改掉用const修饰的常量，
    // const int a = 200;
    
    // 这样处理的话 const修饰的指针无法改变指向的值
    // const int *pa = &a;
    
    // 编译器在这里发现 a 是const类型，它就认为 a 不可修改，所以在下面只要出现 a 它都会去用200来替换。
    // volatitle 告诉编译器该 const 类型变量，有可能进行修改，在使用时去内存中查找真实数据。
    // 所有内存中的东西都是可以修改的，const只不过是C++的语法不允许修改，但是我们可以跳过C++的语法，对内存中的东西进行修改
    volatile const int a = 200;
    int *pa = const_cast<int*>(&a);
    *pa = 300;
    cout << "a=" << a << endl;
    cout << "pa=" << *pa << endl;
    
    
    
    
    return 0;
}
