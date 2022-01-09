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
	cout << "�����û���:\n";
	while(cin >> op){
		if(op == ":return")return 0;
		if((uid = Lib.UserCount(op)) == -1){
			cout << "���û�������,����������\n";
			cout << "�����û���:\n";
			continue;
		}
		cout << "��������:\n";
		while(cin >> op){
			if(op != Lib.usr[uid].Code){
				cout << "�������!\n";
			}else{
				cout << "��ӭ " << Lib.usr[uid].Name << '\n';
				return Lib.usr[uid].Manager;
			}
			cout << "��������:\n";
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
	cout << "���� :return ���˳��������\n";
}

void Run(){
	string op;
	Hello();
	int Signed = Signin();
	while(!Signed){
		 cout << "�˳���(Y/N)" << endl;
		 cin >> op;
		 if(op == "Y"){
		 	cout << "See you!\n";
		 	return ;
		 }
		 cout << "���µ�¼" << endl;
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
	Lib.Loadin();//��Ĭ�����ݼ���
	Run();
	Lib.Loadout();//��Ĭ�����ݼ���
	return 0;
}
