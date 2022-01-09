#include<bits/stdc++.h>
#include "Read.cpp"
const int maxn = 100010;
using namespace std;
class User{
public://为了方便全用public了
	/*Data*/
	string Name;
	string Code;
	bool flag;//标记是否为有效账户
	bool Manager;//标记是否为管理员

	/*Function*/
	User(){
		Name = "User";
		Code = "123456";
		flag = false;
		Manager = false;
	}
	bool Userin(const string &_Name, const string &_Code){
		if(!flag)return 0;//无数据
		if(Name == _Name && Code == _Code)return true;//登陆成功
	}
	void GetUserLog(){//Todo
		
	}
	void ChangeKey(){
		string NewCode, Confirm;
		cin >> NewCode;
		cout << "请再次输入新密码:" << endl;
		cin >> Confirm;
		if(NewCode == Confirm){
			Code = NewCode;
		}else{
			cout << "输入的密码不匹配!" << endl;
		}
	}
	template<class I>
	friend I& operator >>(I& in, User& user);
	template<class O>
	friend O& operator <<(O& out, const User& user);
	User operator = (const User &another){
		Name = another.Name;
		Code = another.Code;
		flag = another.flag;
		Manager = another.Manager;
		return *this;
	}
};

template<class I>
I& operator >>(I& in, User& user){
	user.flag = true;//激活
	string check;
	in >> user.Name >> user.Code >> check;
	if(check == "admin"){
		user.Manager = 1;
	}
	return in;
}

template<class O>
O& operator <<(O& out, const User& user){
	out << user.Name << ' ';
	out << user.Code << ' ';
	if(user.Manager == 1){
		cout << "admin\n";
	}else{
		cout << "user\n";
	}
	return out;
}

class DataBase{
private:
	Book *book;
	int cntb;//标记最后一位uid
	//标记最后一位uid
public:
	User *usr;
	int cntu;
	DataBase(){
		book = new Book[maxn];
		usr = new User[maxn];
		//man = new Manager[maxn];
	};
	/*Root*/
	void Loadin();
	void Loadout();
	void Run();
	//void Signout();//待定
	/*Manager*/
	void Search();
	void addAccount();
	void deleteAccount();
	void changeBook();
	void addBook();
	void deleteBook();
	/*System*/
	int BookCount(const string &_title);//返回书籍的uid
	int UserCount(const string &_Name);//返回用户的uid
	friend bool Signin();
};

int DataBase::BookCount(const string &_title){
	for(int i = 0; i < cntb; i ++){
		if(book[i].flag == 0)continue;
		if(book[i].title == _title){
			return i;		
		}
	}
	return -1;
}

int DataBase::UserCount(const string &_Name){
	for(int i = 0; i < cntb; i ++){
		if(usr[i].flag == 0)continue;
		if(usr[i].Name == _Name){
			return i;
		}
	}
	return -1;
}

void DataBase::Loadin(){
	cout << "Loading...\n" << endl;
	//采用ifstream模式
	/*loadbook*/
	ifstream infile;
	infile.open("books.txt");
	while(infile >> book[cntb]){
		cntb ++;
	}
	infile.close();
	/*loadusr*/
	infile.open("userbin.txt");
	while(infile >> usr[cntu]){
		cntu ++;
	}
	infile.close();
}
void DataBase::Loadout(){
	ofstream outfile;
	/*book*/
	outfile.open("books.out");
	for(int i = 0; i < cntb; i ++){
		if(book[i].flag)outfile << book[i];
	}
	outfile.close();
	/*user*/
	outfile.open("userbin.out");
	for(int i = 0; i < cntu; i ++){
		outfile << usr[i];
	}
	outfile.close();
}

/*
功能：
1. 题名精确查找
2. ISBN精确查找
3. 作者，全部查找
4. 三级分类查找
5. uid查找
*/
void PrintSearchManu(){
	cout << "功能：\n";
	cout << "1. 题名精确查找\n";
	cout << "2. ISBN精确查找\n";
	cout << "3. 作者，全部查找\n";
	cout << "4. 三级分类查找\n";
	cout << "5. uid查找\n";
}
void RootSearch(const char op, Book *Data, const int cnt);
void DataBase::Search(){
	string op;
	PrintSearchManu();
	while(cin >> op){
		if(op == ":return")return;
		RootSearch(op[0], book, cntb);
		PrintSearchManu();
	}
}
void StepSearch(Book *Data, const int cnt);
void RootSearch(const char op, Book *Data, const int cnt){//从默认数据库当中搜索
	//默认搜索路径为Data
	string s;//匹配串
	if('1' <= op && op <= '3'){
		cout << "输入要查找的关键字:\n";
		cin >> s;
		for(int i = 0; i <= cnt; i ++){
			if(*Data[i].P[op - '1'] == s){
				Data[i].Print();
			}
		}
	}else if(op == '4'){
		StepSearch(Data, cnt);
	}
}

inline void StepSearch(Book *Data, const int cnt){
	string op;//级数
	string s;
	cout << "输入级数:1/2/3\n";
	while(cin >> op){
		if(op == ":return")return;
		cout << "输入要查找的关键字:\n";
		cin >> s;
		int now = op[0] - '1';
		for(int i = 0; i <= cnt; i ++){
			if(Data[i].Divider[now] == s){
				Data[i].Print();
			}
		}
	}
}


void DataBase::addAccount(){
	string op;
	cout << "输入要添加的用户名:\n" << endl;//加入提示Todo
	while(cin >> op){
		if(op == ":return")return;
		User Add;
		while(1){
			if(this -> UserCount(op) == -1){//查询是否重名
				break;
			}else{
				cout << "用户名已被占用,请重新输入用户名:\n";
				cin >> op;
			}
		}
		Add.Name = op;//设置账号
		cout << "设置初始密码:\n";
		cin >> op;
		Add.Code = op;//设置密码
		cout << "Is this OK?(Y/N) \n";
		cin >> op;
		if(op == "Y"){
			Add.flag = true;//激活账户
			usr[cntu] = Add, cntu ++;
		}else{
			cout << "取消新建账户\n";
			continue;
		}
		cout << "输入要添加的用户名:\n" << endl;//加入提示Todo
	}
}

void DataBase::deleteAccount(){//按用户名删除
	string op;
	int uid = -1;
	cout << "note\n" << endl;//加入提示
	while(cin >> op){
		if(op == ":return")return;
		if((uid = (this -> UserCount(op))) == -1){
			cout << "该用户不存在\n" ;
			continue;
		}
		string tmp = op;
		cout << op << '\n';
		cout << "再次输入确认删除\n";
		cin >> op;
		if(op == tmp){
			usr[uid].flag = false;
			cout << "已删除\n";
			break;
		}
		cout << "提示\n" << endl;//加入提示
	}
}

void DataBase::addBook(){
	string op;
	/*加入提示*/
	cout << "设置标题:\n";
	while(cin >> op){
		if(op == ":return")return;
		Book Add;
		Add.title = op;//设置标题
		cout << "设置作者\n";
		cin >> op;
		Add.writer = op;//设置作者
		cout << "设置ISBN\n";
		cin >> op;
		Add.ISBN = op;//设置ISBN
		cout << "设置分级: 格式:A123/123\n";
		cin >> op;
		Add.SetDivider(op);//设置分级
		cout << "Is this OK?(Y/N) \n";
		cin >> op;
		if(op == "Y"){
			Add.flag = true;//激活
			book[cntb] = Add, cntb ++;
		}else{
			cout << "取消新建书目\n";
			continue;
		}
		cout << "note\n" << endl;//加入提示Todo
	}
}

void DataBase::changeBook(){//修改书籍,首先要查询书籍
	/*
	仅支持根据标题修改
	仅支持对书籍整体进行重新写
	*/
	string op;
	int uid = -1;
	cout << "note\n" << endl;//加入提示
	while(cin >> op){
		if(op == ":return")return;
		if((uid = (this -> BookCount(op))) == -1){
			cout << "该书籍不存在\n";
			continue;
		}
		cout << "你是说这本书？\n";
		book[uid].Print();
		if(op == ":return")return;
		Book Add;
		cout << book[uid].title << '\n' << "修改为\n";
		cin >> op;
		Add.title = op;//设置标题
		cout << book[uid].writer << '\n' << "修改为\n"; 
		cin >> op;
		Add.writer = op;//设置作者
		cout << book[uid].ISBN << '\n' << "修改为\n";
		cin >> op;
		Add.ISBN = op;//设置ISBN
		cout << book[uid].Divider[2] << '\n' << "修改为\n";
		cin >> op;
		Add.SetDivider(op);//设置分级
		cout << "Is this OK?(Y/N) \n";
		cin >> op;
		if(op == "Y"){
			Add.flag = true;//激活账户
			book[uid] = Add;
		}else{
			cout << "取消修改书目\n";
			continue;
		}
		cout << "note\n" << endl;//加入提示
	}
}

void DataBase::deleteBook(){
	/*
	仅支持根据标题修改
	*/
	string op;
	int uid = -1;
	cout << "提示\n" << endl;//加入提示
	while(cin >> op){
		if(op == ":return")return;
		if((uid = (this -> BookCount(op))) == -1){
			cout << "该书籍不存在\n";
			continue;
		}
		string tmp = op;
		cout << op << '\n';
		cout << "再次输入确认删除\n";
		cin >> op;
		if(op == tmp){
			book[uid].flag = false;
			cout << "已删除\n";
			break;
		}
		cout << "提示\n" << endl;//加入提示
	}
}
