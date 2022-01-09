#include<bits/stdc++.h>
#include "Read.cpp"
#include "manage.cpp"
using namespace std;
const int maxn = 100010;

/*Books*/
Book book[maxn];
bool check[maxn];
int cntb;
/*Users*/
User usr[maxn];
int cntu;
/*
class User{
	friend void Sign(int &uid);
}
*/
/*Managers*/
Manager man[maxn];
int cntm;

void Loadin(){
	cout << "Loading" << endl;
	//freopen("intest.txt", "r", stdin);//´ÓÎÄ¼þintest¶ÁÈë
	//²ÉÓÃifstreamÄ£Ê½
	/*loadbook*/
	ifstream infile;
	infile.open("intest.txt");
	while(infile >> book[cntb]){
		check[cntb] = 1;
		cntb ++;
	}
	infile.close();
	/*loadusr*/
	infile.open("userbin.txt");
	while(infile >> usr[cntu]){
		cntu ++;
	}
	infile.close();
	/*loadman*/
	infile.open("manager.txt");
	while(infile >> manager[cntm]){
		cntm ++;
	}
	infile.close();
}

void Hello(){
	cout << "Hello HNUFakeLib!" << endl;
	cout << "Please sign in to continue!" << endl;
}

bool Sign(int &uid){//µÇÂ¼
	bool flag = 0;
	string s, code;
	while(cin >> s){
		if(s == ":return")return;
		cin >> code;
		for(int i = 0; i < cntu; i ++){
			if(usr[i].Userin(s, code)){
				uid = i;
				break;
			}
		}
	}
	cout << "Hello " << s << endl;
	return flag;
}

void Loadout(){
	ofstream outfile;
	/*book*/
	outfile.open("Book.out");
	for(int i = 0; i < cntb; i ++){
		if(check[i])outfile << book[i];
	}
	outfile.close();
	/*user*/
	outfile.open("User.out");
	for(int i = 0; i < cntu; i ++){
		outfile << usr[i];
	}
	outfile.close();
	/*manager*/
	outfile.open("Manager.out");
	for(int i = 0; i < cntm; i ++){
		outfile << man[i];
	}
	outfile.close();
}

void Manuout(){
	cout << R"
1.Search
2.GetUserLog
3.ChangeKey
ÈôÒª½èÊéÇëÏÈÊ¹ÓÃSearch
	";
}

void run(){
	Hello();//»¶Ó­
	int uid;
	bool Man = Sign(uid);//µÇÂ¼
	string s;
	while(cin >> s){
		Manuout();
		if(s == ":exit")return;
		if(s == "Search"){
			RootSearch();//
		}else if(s == "GetUserLog"){
			usr[uid].GetUserLog();
		}else if(s == "ChangeKey"){
			usr[uid].ChangeKey();
		}
		if(Man == 1){
			cout << "¹ÜÀíÔ±¹¦ÄÜ:" << endl;
			if(s == "addAccount"){
				man[uid].addAccount();
			}else if(s == "deleteAccount"){
				man[uid].deleteAccount();
			}else if(s == "changeBook"){
				man[uid].changeBook();
			}else if(s == "addBook"){
				man[uid].addBook();
			}else if(s == "deleteBook"){
				man[uid].deleteBook();
			}
			/*
			1.get_Num
			2.addAccount
			3.deleteAccount
			4.changeBook
			5.addBook
			6.deleteBook
			*/
		}
	}
}


int main(){
	loadin();
	//cout << book[3] << endl;
	run();
	Loadout();
	return 0;
}