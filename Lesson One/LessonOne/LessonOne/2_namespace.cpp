#include <iostream>

namespace hero {
    const char* name = "nihao";
    void show() {
        std::cout << "nihao come" << std::endl;
    }
}

namespace enemy {
    const char* name = "haha";
    void show() {
        std::cout << "haha come" << std::endl;
    }
}

// 该变量存储在:全局区
//const char* name = "shenme";

// 在方法里面都是在栈区存储, 在堆区一般需要开辟空间(new)
int main() {
//    std::cout << hero::name << std::endl;
//    std::cout << enemy::name << std::endl;
//    std::cout << name << std::endl;
    
    // 使用声明 省略命名空间
    // using std::cout;
//    using namespace std;
    
//    cout << "12345" << endl;
//    string str = "......";
//    cout << str << endl;
    
    using namespace std;
    using namespace hero;
    
    cout << name << endl;
    show();
    
    cout << enemy::name << endl;
    enemy::show();
    
    return 0;
}
