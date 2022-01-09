/*
初步测试图书馆的各种查找功能
*/
#include<bits/stdc++.h>
using namespace std;


class Book{
private:
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* 首字母,数字组合/数字组合 */
	string Divider[3];
public:
	void SetDivider(const string &&_Divider){
		Divider[0] = _Divider.substr(0, i);//从 0 到 i - 1
		Divider[1] = _Divider.substr(i + 1);//从i + 1到字符串末尾
	}
	Book(){}
	Book(const string &&_title, const string &&_writer, const string &&_ISBN){
		title = _title, writer = _writer, ISBN = _ISBN;
	};
	//~Book(){}因为没有指针就用默认的析构
};


template<class T>//链表
struct node{
	T u;
	*T next;
};

class Lib{//图书馆功能
private:
	//Book *books;//数组结构图书
	Book *head;//链表结构图书头
public:
	//Lib(){};
	void load(){}
	void run(){};
};

void Lib::load(){//读入数据，

}

/*
功能：
1. 题名精确查找
2. ISBN精确查找
3. 作者，全部查找
4. 三级分类查找
*/

/*
首先尝试全部使用遍历的方式查找
*/

void search(int op, const char *s){
	if(op == 1){//
		
	}
}

void Lib::run(){
	/*首先实现一个全局的读入池*/
	string UsrInput;//用户输入
	int Page = 0;//用户页面状态码，用于标记用户在哪个页面
	while(cin >> UsrInput){//换行触发功能刷新
		search(UserInput);
	}
}

int main(){
	sync_with_stdio(false);//关闭同步提速
	cin.tie(0);
	Lib Test;
	Test.load();
	Test.run();
	return 0;
}