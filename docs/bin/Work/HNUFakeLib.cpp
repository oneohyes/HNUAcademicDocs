#include<bits/stdc++.h>
using namespace std;

void Load();//����ͼ����ĵ�
void Signin();//�û���¼
//void UsrInput();//ȫ�ֵĶ����


class Lib{
	Book *books;
	Root *roots;
	void load();//��������
	void run();
}HNU;

class Book{
private:
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* ����ĸ,�������/������� */
	string Divider[3];
}
/*����һ��������*/
/*
�Ѿ���testOne.cpp�����غ���
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
";//ʹ��c++11 Raw string ����������ʱ������ת�塣
}

void Lib::run(){
	Load();
	system('cls');
	cout << R"Welcome to HNUFakeLibrary!
";

/*
Ϊ����ʹ�����ܹ�ͬʱӵ�оֲ����ܺ�ȫ�ֹ��ܿ��»�Ҫ
��һ�����컺�����ˣ�
�����Ƚ���ȫ�ֹ��������м����ؼ��֣���������ɹ���ִ����Ӧ��ȫ�ֹ���(�� BackToMenu, LogOut ��)
Ȼ���ٽ��뵱ǰ���ڵľֲ���������ʵ�ֹ��ܡ�
*/

}


int main(){
	HNU.run();
	return 0;
}