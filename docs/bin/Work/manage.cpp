#include<bits/stdc++.h>
using namespace std;
class Manager{
private:
	int num;//用户人数 
	int bnum;
	string mcode;//管理员密码 
	string mid="东方之星";//管理员账号 
	bool flag=false;
public:
	void ManagerCode(string &s)
	{
		mcode="123456";
		mcode = s;
	}
	bool Managerin(string &s1,string &s2)//账号登陆 
	{
		if(s1==mid&&s2==mcode)flag=true;
		return flag;
	}
    void addAccount() //添加学校用户默认账号和密码 
	{
		User *user;
		int addNum = 0;//添加数量 
		cin >> addNum;
		if (addNum <= 0) {
			
			cin >> addNum;
		}
		int newSize = this->num + addNum;//新空间人数=原来记录的人数+现在加入的人数
		//开辟新空间
		User** newSpace = new User * [newSize];

		//将原来空间下的数据，拷贝到新空间下
		if (this->array != NULL) {
			for (int i = 0; i < this->num; i++) {
				newSpace[i] = this->array[i];
			}
		}
		//添加新数据
		for (int j = 0; j < addNum; j++) {
		     string id;
		     cin>>id;
		     string code="123456";
		     user=new User(id,code);
		     newSpace[this->num+j]=user;
		 }
		//释放原有的空间
		delete[]this->array;
		//更改新空间的指向
		this->array = newSpace;
		//更新新的职工人数
		this->num = newSize;
    }
    void deleteAccount() {
		string id;
		cin >> id;
		int index; 
		if(index>0)
		{
			//用数据前移，对指定元素进行删除！
			for (int i = index; i < this->num - 1; i++) {
				this->array[i] = this->array[i + 1];
			}
			this->num--;//更新数组中记录的人员个数
		}
	}
	void changeBook()
	{
		
	    string s;//匹配文本
	    cin >> s;//读入匹配文本
	    Book book[10];
	    cin >> book;
		node<Book> now = Head;
		while(){//顺序遍历链表
			if(now.u -> title == s)
			{
				now.u=book[10]; 
				break;
			}
			if(now.next -> u == Head.u)
			{
			    now.u=book[10]; 
			    break;
			}
		}
	}
    void addBook() //添加学校用户默认账号和密码
	{
		Book *book;
		int addNumbook = 0;//添加数量 
		cin >> addNumbook;
		if (addNumbook <= 0) {
			
			cin >> addNumbook;
		}
		int Size = this->bnum + addNumbook;//新空间书=原来记录的书+现在加入的书 
		//开辟新空间
		Book** Space = new Book * [Size];

		//将原来空间下的数据，拷贝到新空间下
		if (this->books != NULL) {
			for (int i = 0; i < this->bnum; i++) {
				Space[i] = this->books[i];
			}
		}
		//添加新数据
		for (int j = 0; j < addNumbook; j++) {
		     Book book1[10];
	         cin >> book1;
		     //book=new Book();
		     book=book1;
		     Space[this->bnum+j]=book;
		 }
		//释放原有的空间
		delete[]this->books;
		//更改新空间的指向
		this->books = Space;
		//更新书本数 
		this->bnum = Size;
		
    }
    void deleteBook() {
		string s;
		cin >> s;
		int bindex; 
		if(bindex>0){
			//用数据前移，对指定元素进行删除！
			for (int i = bindex; i < this->bnum - 1; i++) {
				this->books[i] = this->books[i + 1];
			}
			this->bnum--;//更新数组中记录的人员个数
		}
	}
};
class User{
	string code;//用户密码 
	string id="blabla";//用户账号 
	bool bflag=false;
	void UserCode(string &s)
	{
		code="123456";
		strcpy(code,s);
		
	}
	bool Userin(string &s1,string &s2)//账号登陆 
	{
		if(s1==id&&s2==code)bflag=true;
		return bflag;
	}
	friend void Sign(int &uid);
};
