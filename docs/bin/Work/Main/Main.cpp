#include "teststruct.cpp"
#include<bits/stdc++.h>
using namespace std;
DataBase Lib;
User use;
void Hello(){
	cout << "Hello HNUFakeLib!" << endl;
	cout << "Please sign in to continue!" << endl;
}
bool Signin(){
	string op;
	int uid = -1;
	cout << "输入用户名:\n";
	while(cin >> op){
		if(op == ":return")return 0;
		if((uid = Lib.UserCount(op)) == -1){
			cout << "该用户不存在,请重新输入\n";
			cout << "输入用户名:\n";
			continue;
		}
		cout << "输入密码:\n";
		while(cin >> op){
			if(op != Lib.usr[uid].Code){
				cout << "密码错误!\n";
			}else{
				cout << "欢迎 " << Lib.usr[uid].Name << '\n';
				return Lib.usr[uid].Manager;
			}
			cout << "输入密码:\n";
		}
	}
	return 0;
}

void Menuout(int Signed){
	cout << "----MENU----\n";
	cout << "<<User>>" << endl;
	cout << "Search\n";
	cout << "GetUserLog\n";
	cout << "ChangeKey\n";
	if(Signed){
		cout << "<<Manager>>" << endl;
		cout << "addAccount\n";
		cout << "deleteAccount\n";
		cout << "changeBook\n";
		cout << "addBook\n";
		cout << "deleteBook\n";
	}
	cout << "输入 :return 可退出任意界面\n";
}

void Run(){
	string op;
	Hello();
	int Signed = Signin();
	while(!Signed){
		 cout << "退出？(Y/N)" << endl;
		 cin >> op;
		 if(op == "Y"){
		 	cout << "See you!\n";
		 	return ;
		 }
		 cout << "重新登录" << endl;
		 Signed = Signin();
	}
	Menuout(Signed);
	while(cin >> op){
		if(op == ":return")return;
		if(op == "Search"){
            Lib.Search();
		}else if(op == "GetUserLog"){
            use.GetUserLog();
		}else if(op == "ChangeKey"){
			use.ChangeKey();
		}
		if(Signed){
			if(op == "addAccount"){
				Lib.addAccount();         
			}else if(op == "deleteAccount"){
				Lib.deleteAccount();
			}else if(op == "changeBook"){
				Lib.changeBook();
			}else if(op == "addBook"){
				Lib.addBook();
            }else if(op == "deleteBook"){
			    Lib.deleteBook();
			}
		}
		Menuout(Signed);
	}
}

int main(){
	Lib.Loadin();//从默认数据加载
	Run();
	Lib.Loadout();//从默认数据加载
	return 0;
}
