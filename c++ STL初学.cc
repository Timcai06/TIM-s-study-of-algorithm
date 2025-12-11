#include <iostream>
#include <vector> //动态数组
#include <set>    //集合，集合里的元素各不相同，且元素会按照从小到大排列
#include <map>    //键值对，自动将所有的键值对按照键从大到小排序(依照ASCII码排序)
#include <stack>  //栈
#include <queue>  //队列
using namespace std;

int main (){
    //————————STL-vector————————//
    //创建vector类型数组的3种方式
    vector <int> arr;
    vector <int> brr(10,2);//初始化数组大小为10，每一个元素为2
    vector <int> crr(10);//初始化数组大小为10，且每一个元素为0
                         /*类似如下操作:vector <int> arr;
                                      arr.resize(10);
                         */
    cout << arr.size() <<endl;
    //分配数组大小
    arr.resize(10); 
    cout << arr.size() <<endl;
    //输入数据，同c语言
    for (int i = 0 ; i < 10 ; i++){
        arr[i] = i;
    }
    for (int i = 0 ; i < 10 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    //在末尾添加新的数据,数组大小自动改变
    arr.push_back(101);
    cout << arr[10] << " " << arr.size() << endl;
    //迭代器————不论数组大小，自动遍历数组 (在 c++ 11 的环境下执行)
    for (auto p = brr.begin() ; p != brr.end() ; p++){
        cout << *p << " ";
    }
    cout << endl << endl;


    //————————STL-set————————//
    set <int> s;
    //插入元素
    s.insert(1);
    s.insert(1011);
    s.insert(5);
    s.insert(3);
    for (auto p = s.begin() ; p != s.end() ; p++){
        cout << *p << " ";
    }
    cout << endl;
    cout << (s.find(10) != s.end()) << endl; //输出一个bool值，集合里有想要查找的元素输出1，反之输出0
    cout << (s.find(1) != s.end()) << endl;
    //删除元素
    s.erase(1);
    cout << (s.find(1) != s.end()) << endl;


    //————————STL-map————————//
    map <string,int> m;
    m["hello"] = 66;
    m["world"] = 3;
    cout << "hello:" << m["hello"] << endl;
    cout << "world:" << m["world"] << endl;
    for (auto p = m.begin() ; p != m.end() ; p++){
        cout << p->first << " : " << p->second << endl;
    }
    //获取长度
    cout << "map的长度为: " << m.size() << endl;
    m["crtnb"] = 5;
    cout << "map的长度为: " << m.size() << endl << endl;


    //————————STL-stack————————//
    stack <int> sta;
    //压栈
    sta.push(1);
    sta.push(199);
    cout << sta.top() << endl;
    cout << "栈的长度为: " << sta.size() << endl;
    //出栈
    sta.pop();
    cout << sta.top() << endl;
    cout << "栈的长度为: " << sta.size() << endl << endl;

    for (int i = 0 ; i < 10 ; i++){
        sta.push(i);
    }
    

    //————————STL-queue————————//
    queue <int> que;
    //入队
    for (int i = 0 ; i < 10 ; i++){
        que.push(i);
    }
    //队首出队
    que.pop();
    //访问队首、队尾
    cout << que.front() << endl;
    
    que.pop();
    cout << que.front() << endl;
    cout << que.back() << endl;
    cout << "此时队列的长度为: " << que.size() << endl;

    que.push(100);
    cout << que.back() << endl;
    cout << "此时队列的长度为: " << que.size() << endl;

    return 0;
}
