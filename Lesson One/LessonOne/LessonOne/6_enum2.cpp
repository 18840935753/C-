#include <iostream>

using namespace std;

// C++99
enum ButtonType {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

// C++11 类型枚举  因为之前的枚举如果有多个枚举  里面变量名不能相同
enum class ButtonType2 {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};


struct UIButton {
    int tag;
    void touch() {
        cout << "tag值为 " << tag << " 的Button被点中" << endl;
    }
};

void touchButton(UIButton sender) {
    sender.touch();
    switch (sender.tag) {
        case UP:
            cout << "向上移动" << endl;
            break;
        case DOWN:
            cout << "向下移动" << endl;
            break;
        case LEFT:
            cout << "向左移动" << endl;
            break;
        default:
            cout << "向右移动" << endl;
            break;
    }
}

int main() {
    
    UIButton button1;
    button1.tag = UP;
    UIButton button2;
    button2.tag = DOWN;
    UIButton button3;
    button3.tag = LEFT;
    UIButton button4;
    button4.tag = RIGHT;
    
    touchButton(button2);
    
    // 类型枚举的使用方式
    ButtonType2::UP;
    cout << int(ButtonType2::UP) << endl;
    
    return 0;
};
