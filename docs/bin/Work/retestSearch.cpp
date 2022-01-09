#include<bits/stdc++.h>
#include "Read.cpp"
using namespace std;
void RootSearch(const int &op, Book *Data);
void StepSearch(Book *Data);
template<class T>
struct node{//链表
	T *u;
	node *next;
};

int cnt = 0;
Book book[10];
bool check[10];//标记有效数据
/*
功能：
1. 题名精确查找
2. ISBN精确查找
3. 作者，全部查找
4. 三级分类查找
*/

void Search(){
	string op;
	while(cin >> op){
		if(op == ":return")return;
		RootSearch(op[0], book);
	}
}

void RootSearch(const char op, Book *Data){//从默认数据库当中搜索
	//默认搜索路径为Data
	string s;//匹配串
	if('1' <= op && op <= '3'){
		cin >> s;
		for(int i = 0; i <= cnt; i ++){
			if(*Data[i].P[op - '1'] == s){
				Data[i].Print();
			}
		}
	}else if(op == '4'){
		StepSearch(Data);
	}
}

inline void StepSearch(Book *Data){
	string op;//级数
	string s;
	while(cin >> op){
		if(op == ":return")return;
		cin >> s;
		int now = op[0] - '1';
		for(int i = 0; i <= cnt; i ++){
			if(Data[i].Divider[now] == s){
				Data[i].Print();
			}
		}
	}
}

void load(){
	//freopen("intest.txt", "r", stdin);//从文件intest读入
	//采用ifstream模式
	ifstream infile;
	infile.open("intest.txt");
	while(infile >> book[cnt]){
		cnt ++;
	}
	//fclose(stdin);
}

int main(){
	load();
	//freopen("con", "r", stdin);//重定向到控制台
	//失败了
	/* test */
	cout << book[3] << endl;
	char op;
	cin >> op;
	RootSearch(op, book);

	return 0;
}
