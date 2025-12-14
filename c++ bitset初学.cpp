#include <iostream>
#include <bitset>
using namespace std;

int main (){
    bitset<5> a;     //初始化一个五位二进制数，且初始化为0
    bitset<5> b(18); //初始化一个五位二进制数，切初始化为18
    bitset<8> c("1101");//初始化一个五位二进制数，括号内填入二进制字符串

    //从二进制高位到低位依次输出
    cout << b << endl;
    cout << c << endl;

    //从二进制低位到高位依次输出
    //b[0]——>二进制数的最低位
    for (int i = 0 ; i < b.size() ; i++){
        cout << b[i] << " ";
    }
    cout << endl;

    //bool值类型判断
    cout << "是否有1: " << b.any() << endl;
    cout << "是否不存在1: " << b.none() << endl;
    cout << "下标为i的元素是不是1: " << b.test(0) << endl;

    cout << "1的个数: " << b.count() << endl;
    cout << "b中元素的个数: " << b.size() << endl;
    
    //取反(0->1 或者 1->0)
    b.flip();
    cout << b << endl;
    b.flip(0);
    cout << b << endl;

    //将二进制转化为十进制
    unsigned long aaa = b.to_ulong();
    cout << aaa << endl;

    //清零操作
    b.reset(0);
    b.reset(/*————i————*/);//第i位清零
    aaa = b.to_ulong();
    cout << aaa << endl;

    return 0;
}
