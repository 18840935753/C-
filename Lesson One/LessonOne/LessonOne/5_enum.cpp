#include <iostream>
using namespace std;

enum HeroState {
    Stand,
    Move,
    Attack,
    Die
};

// 匿名枚举 相当于创建了三个变量
enum {
    INDEX,
    INDEX2,
    INDEX3
};
// 👆相当于
//const int INDEX = 0;
//const int INDEX2 = 1;
//const int INDEX3 = 2;


void logic(HeroState state) {
    switch (state) {
        case Stand:
            cout << "stand" << endl;
            break;
        case Move:
            cout << "move" << endl;
            break;
        case Attack:
            cout << "attack" << endl;
            break;
        default:
            cout << "die" << endl;
            break;
    }
}

int main() {
    HeroState state;
    state = Stand;
    logic(state);
    state = Move;
    logic(state);
    
    
    int x = Stand;
    cout << x << endl;
    
    // 直接给int值不可以,因为C++类型检测严格
    // state = 0;
    state = (HeroState)0;
    
    return 0;
}
