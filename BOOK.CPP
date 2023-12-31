#include <iostream>
#include <string>
using namespace std;
//创建Book类
class Book {
private:
    string bookname;
    double price;
    int number;

public:
    //默认构造函数
     Book() {
        bookname = "";
        price = 0.0;
        number = 0;
    }
     Book(string name, double p, int num) {
        bookname = name;
        price = p;
        number = num;
    }
    //显示图书
    void Display() {
        cout << "图书名称: " << bookname << endl;
        cout << "价格:     " << price << endl;
        cout << "库存数量: " << number << endl;
    }
    //借阅图书
    void Borrow() {
        if (number <= 0) {
            cout << "该图书已借完！" << endl;
        }
        else {
            number--;
            cout << "成功借阅图书！当前库存数量: " << number << endl;
        }
    }
    //归还图书
    void Restore() {
        number++;
        cout << "成功归还图书！当前库存数量: " << number << endl;
    }
};

int main() {
    // 创建多个图书对象
    int size;
    cout << "请输入书库容量: ";
    cin >> size;//输入书库容量
    Book* books = new Book[size];  
    string name;
    double price;
    int num;
    for (int i = 0; i < size; i++) {
        cout << "请输入图书"<<i+1<<"的名称、价格、数量: ";
        cin >> name >> price >> num;

        books[i] = Book(name, price, num); // 输入数据到每个Book对象中
    }
    cout << "图书录入成功！" << endl;

    // 图书管理系统
    int choice;
    while (true) {
        cout << "1. 显示图书" << endl;
        cout << "2. 借阅图书" << endl;
        cout << "3. 归还图书" << endl;
        cout << "请选择操作序号: ";

        cin >> choice;
        //判断操作序号
        switch (choice) {
        case 1: {
            // 显示所有图书
            cout << "存书情况：" << endl;
            for (int i = 0; i < size; i++) {
                cout << "图书" << i + 1 << ":" << endl;
                books[i].Display();
                cout << endl;
            }
        }break;
        case 2: {
            // 借阅图书
            int index;
            cout << "请输入要借阅的图书序号: ";
            cin >> index;

            // 检查序号是否合法
            if (index >= 1 && index <= size) {
                books[index - 1].Borrow();
            }
            else {
                cout << "输入的图书序号无效！" << endl;
            }
            cout << endl;
        }break;
        case 3: {
            // 归还图书
            int index;
            cout << "请输入要归还的图书序号: ";
            cin >> index;

            // 检查序号是否合法
            if (index >= 1 && index <= size) {
                books[index - 1].Restore();
            }
            else {
                cout << "输入的图书序号无效！" << endl;
            }
            cout << endl;
        }break;
            cout << endl;
        }
    }while (choice != 3);

    system("pause");//停止窗口
    return 0;
}
