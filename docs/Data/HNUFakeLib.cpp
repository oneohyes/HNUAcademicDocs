#include<bits/stdc++.h>
using namespace std;

void Load();//加载图书馆文档
void Signin();//用户登录
void UsrInput();//全局的读入池


class Lib{
	Book *books;
	Root *roots;
	void load();//读入数据
	void run();
}HNU;

class Book{
private:
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* 首字母,数字组合/数字组合  */
	string Divider[3];
}
/*重载一下输入流*/
/*
已经在testOne.cpp中重载好了
ifstream >>
ofstream <<
*/

class Root{
	string Name;
	string Key;
	void AddUsr(){
		
	}
}

class Usr{
	string Name;
	string Key;

}

void Lib::Load(){//
	cout<<R"Loading...";
	ifstream BookFile;
	BookFile.open("book.txt", ios::in);
	BookFile >> 

}

void Signin(){
cout<<R"Please sign in to continue...
UsrName:
";
}

void Lib::run(){
	Load();
	system('cls');
	cout << R"Welcome to HNUFakeLibrary!
";

	/*
为了能使运行能够同时拥有局部功能和全局功能恐怕还要
造一个人造缓冲区了：
输入先进入全局功能区进行检索关键字，如果检索成功就执行相应的全局功能(如 BackToMenu, LogOut 等)
然后再进入当前所在的局部功能区，实现功能。
	*/	

}


int main(){
	HNU.run();
	return 0;
}