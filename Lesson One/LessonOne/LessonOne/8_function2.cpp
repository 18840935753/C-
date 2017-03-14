#include <iostream>
using namespace std;

// 重载和重写 区别:
// 完全是两个不同的概念：
// 重载: 方法名相同，参数列表不同 (两个方法都存在)
// 重写: 必须依赖于继承, 子类覆盖父类的方法 (覆盖后 只有一个方法)，之所以重写，更多的是使用多态(例如: 猫吃鱼，狗吃肉，都是吃，只不过吃的方式不同)

// 在OC里面接口就是协议，在其他语言中，习惯将协议叫成接口
// 在OC里面没有代理这个词，都是委托。代理是在JAVA里面的叫法

void fa(char ch) {
    cout << "char ch" << endl;
};
void fa(short s) {
    cout << "short s" << endl;
};
void fa(int i) {
    cout << "int i" << endl;
};
void fa(long l) {
    cout << "long l" << endl;
};
void fa(float f) {
    cout << "float f" << endl;
};
void fa(double d) {
    cout << "double d" << endl;
};

int main() {
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    
    fa(c);fa(s);fa(i);fa(l);fa(f);fa(d);
}
