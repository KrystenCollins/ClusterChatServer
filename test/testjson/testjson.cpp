#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// json序列化示例1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "Hello, how are you?";

    string sendBuf = js.dump();
    cout << sendBuf.c_str() << endl;
    return sendBuf;
}

// json序列化示例2
string func2()
{
    json js;
    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "Hello world";
    js["msg"]["liu shuo"] = "Hello C++";
    // 等同语句
    // js["msg"] = {{"zhang san", "Hello world"}, {"liu shuo", "Hello C++"}};
    // cout << js << endl;
    return js.dump();
}

// json序列化示例3
string func3()
{
    json js;

    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(8);

    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({4, "bbssaaa"});
    m.insert({5, "你好"});
    m.insert({1, "hello world"});

    js["path"] = m;
    return js.dump();
}

int main()
{

    // string recvBuf = func1();
    // // 数据的反序列化： json字符串 --> 反序列化 数据对象（看作容器，方便访问）
    // json jsbuf = json::parse(recvBuf);
    // cout << jsbuf["msg_type"] << endl;
    // cout << jsbuf["from"] << endl;
    // cout << jsbuf["to"] << endl;
    // cout << jsbuf["msg"] << endl;

    // string recvBuf = func2();
    // json jsbuf = json::parse(recvBuf);
    // cout << jsbuf["id"] << endl;
    // auto arr = jsbuf["id"];
    // cout << arr[2] << endl;

    // auto msgjs = jsbuf["msg"];
    // cout << msgjs["zhang san"] << endl;
    // cout << msgjs["liu shuo"] << endl;

    string recvBuf = func3();
    json jsbuf = json::parse(recvBuf);

    vector<int> vec = jsbuf["list"]; // js对象里的数据类型，直接放入vector容器当中
    for (int &v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymap = jsbuf["path"];
    for (auto &p : mymap)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    return 0;
}