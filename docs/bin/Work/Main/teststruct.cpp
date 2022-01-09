#include<bits/stdc++.h>
#include "Read.cpp"
const int maxn = 100010;
using namespace std;
class User{
public://Ϊ�˷���ȫ��public��
	/*Data*/
	string Name;
	string Code;
	bool flag;//����Ƿ�Ϊ��Ч�˻�
	bool Manager;//����Ƿ�Ϊ����Ա

	/*Function*/
	User(){
		Name = "User";
		Code = "123456";
		flag = false;
		Manager = false;
	}
	bool Userin(const string &_Name, const string &_Code){
		if(!flag)return 0;//������
		if(Name == _Name && Code == _Code)return true;//��½�ɹ�
	}
	void GetUserLog(){//Todo
		
	}
	void ChangeKey(){
		string NewCode, Confirm;
		cin >> NewCode;
		cout << "���ٴ�����������:" << endl;
		cin >> Confirm;
		if(NewCode == Confirm){
			Code = NewCode;
		}else{
			cout << "��������벻ƥ��!" << endl;
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
	user.flag = true;//����
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
	int cntb;//������һλuid
	//������һλuid
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
	//void Signout();//����
	/*Manager*/
	void Search();
	void addAccount();
	void deleteAccount();
	void changeBook();
	void addBook();
	void deleteBook();
	/*System*/
	int BookCount(const string &_title);//�����鼮��uid
	int UserCount(const string &_Name);//�����û���uid
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
	//����ifstreamģʽ
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
���ܣ�
1. ������ȷ����
2. ISBN��ȷ����
3. ���ߣ�ȫ������
4. �����������
5. uid����
*/
void PrintSearchManu(){
	cout << "���ܣ�\n";
	cout << "1. ������ȷ����\n";
	cout << "2. ISBN��ȷ����\n";
	cout << "3. ���ߣ�ȫ������\n";
	cout << "4. �����������\n";
	cout << "5. uid����\n";
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
void RootSearch(const char op, Book *Data, const int cnt){//��Ĭ�����ݿ⵱������
	//Ĭ������·��ΪData
	string s;//ƥ�䴮
	if('1' <= op && op <= '3'){
		cout << "����Ҫ���ҵĹؼ���:\n";
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
	string op;//����
	string s;
	cout << "���뼶��:1/2/3\n";
	while(cin >> op){
		if(op == ":return")return;
		cout << "����Ҫ���ҵĹؼ���:\n";
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
	cout << "����Ҫ��ӵ��û���:\n" << endl;//������ʾTodo
	while(cin >> op){
		if(op == ":return")return;
		User Add;
		while(1){
			if(this -> UserCount(op) == -1){//��ѯ�Ƿ�����
				break;
			}else{
				cout << "�û����ѱ�ռ��,�����������û���:\n";
				cin >> op;
			}
		}
		Add.Name = op;//�����˺�
		cout << "���ó�ʼ����:\n";
		cin >> op;
		Add.Code = op;//��������
		cout << "Is this OK?(Y/N) \n";
		cin >> op;
		if(op == "Y"){
			Add.flag = true;//�����˻�
			usr[cntu] = Add, cntu ++;
		}else{
			cout << "ȡ���½��˻�\n";
			continue;
		}
		cout << "����Ҫ��ӵ��û���:\n" << endl;//������ʾTodo
	}
}

void DataBase::deleteAccount(){//���û���ɾ��
	string op;
	int uid = -1;
	cout << "note\n" << endl;//������ʾ
	while(cin >> op){
		if(op == ":return")return;
		if((uid = (this -> UserCount(op))) == -1){
			cout << "���û�������\n" ;
			continue;
		}
		string tmp = op;
		cout << op << '\n';
		cout << "�ٴ�����ȷ��ɾ��\n";
		cin >> op;
		if(op == tmp){
			usr[uid].flag = false;
			cout << "��ɾ��\n";
			break;
		}
		cout << "��ʾ\n" << endl;//������ʾ
	}
}

void DataBase::addBook(){
	string op;
	/*������ʾ*/
	cout << "���ñ���:\n";
	while(cin >> op){
		if(op == ":return")return;
		Book Add;
		Add.title = op;//���ñ���
		cout << "��������\n";
		cin >> op;
		Add.writer = op;//��������
		cout << "����ISBN\n";
		cin >> op;
		Add.ISBN = op;//����ISBN
		cout << "���÷ּ�: ��ʽ:A123/123\n";
		cin >> op;
		Add.SetDivider(op);//���÷ּ�
		cout << "Is this OK?(Y/N) \n";
		cin >> op;
		if(op == "Y"){
			Add.flag = true;//����
			book[cntb] = Add, cntb ++;
		}else{
			cout << "ȡ���½���Ŀ\n";
			continue;
		}
		cout << "note\n" << endl;//������ʾTodo
	}
}

void DataBase::changeBook(){//�޸��鼮,����Ҫ��ѯ�鼮
	/*
	��֧�ָ��ݱ����޸�
	��֧�ֶ��鼮�����������д
	*/
	string op;
	int uid = -1;
	cout << "note\n" << endl;//������ʾ
	while(cin >> op){
		if(op == ":return")return;
		if((uid = (this -> BookCount(op))) == -1){
			cout << "���鼮������\n";
			continue;
		}
		cout << "����˵�Ȿ�飿\n";
		book[uid].Print();
		if(op == ":return")return;
		Book Add;
		cout << book[uid].title << '\n' << "�޸�Ϊ\n";
		cin >> op;
		Add.title = op;//���ñ���
		cout << book[uid].writer << '\n' << "�޸�Ϊ\n"; 
		cin >> op;
		Add.writer = op;//��������
		cout << book[uid].ISBN << '\n' << "�޸�Ϊ\n";
		cin >> op;
		Add.ISBN = op;//����ISBN
		cout << book[uid].Divider[2] << '\n' << "�޸�Ϊ\n";
		cin >> op;
		Add.SetDivider(op);//���÷ּ�
		cout << "Is this OK?(Y/N) \n";
		cin >> op;
		if(op == "Y"){
			Add.flag = true;//�����˻�
			book[uid] = Add;
		}else{
			cout << "ȡ���޸���Ŀ\n";
			continue;
		}
		cout << "note\n" << endl;//������ʾ
	}
}

void DataBase::deleteBook(){
	/*
	��֧�ָ��ݱ����޸�
	*/
	string op;
	int uid = -1;
	cout << "��ʾ\n" << endl;//������ʾ
	while(cin >> op){
		if(op == ":return")return;
		if((uid = (this -> BookCount(op))) == -1){
			cout << "���鼮������\n";
			continue;
		}
		string tmp = op;
		cout << op << '\n';
		cout << "�ٴ�����ȷ��ɾ��\n";
		cin >> op;
		if(op == tmp){
			book[uid].flag = false;
			cout << "��ɾ��\n";
			break;
		}
		cout << "��ʾ\n" << endl;//������ʾ
	}
}
