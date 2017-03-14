#include <iostream>
using namespace std;

// 如果不传参数  编译器会自动在(void)里加个void
void fa() {
    
}


// 方法重载: 方法名相同，参数列表不同(类型不用, 参数个数不用, 顺序不同)，
// 那么该两个函数就形成了重载的关系
int addExp(int heroExp, int addExp) {
    return heroExp+addExp;
}

// 告诉编译器，该函数按C的方式处理
// extern "C"

int addExp(int heroExp, double addExpPer) {
    return heroExp*(1+addExpPer);
}

int main() {
    int herpExp = 1000;
    cout << addExp(herpExp, 100) << endl;
    cout << addExp(herpExp, 0.5) << endl;
}
