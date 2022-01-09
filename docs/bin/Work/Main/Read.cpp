/*
用于测试重载自定义类的输入输出
大成功！
*/
#include<bits/stdc++.h>
using namespace std;

class Book{
public:
	int uid;
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* 首字母,数字组合/数字组合 */
	string Divider[3];//更改了策略,分级比较符变为D1,D12,D123
	//方便直接抽级查询
	//string &P[3] = {title, writer, ISBN};//变量别名，方便按状态码访问
	string *P[3];//尝试使用指针...
	bool flag;
	Book(){//默认构造将指针数组定向到元素方便顺序访问
		//P[3] = {&title, &writer, &ISBN};
		flag = false;
		P[0] = &title, P[1] = &writer, P[2] = &ISBN;
	};
	Book(const Book &t){//更改了指针的拷贝
		flag = t.flag;
		P[0] = &title, P[1] = &writer, P[2] = &ISBN;
		title = t.title, writer = t.writer, ISBN = t.ISBN;
		for(int i = 0; i < 3; i ++)Divider[i] = t.Divider[i];
	}
	bool SetDivider(const string &s){
		Divider[0] = s;
		bool flag = 0;
		for(int i = 0; i < (int)Divider[0].size(); i ++){//分解3级分类
			if(Divider[0][i] == '/'){
				Divider[1] = Divider[0].substr(1, i - 1);//从 0 到 i - 1
				Divider[2] = Divider[0].substr(i + 1);//从i + 1到字符串末尾
				Divider[0] = Divider[0].substr(0, 1);//首字
				Divider[1] = Divider[0] + Divider[1];//D2变为D12
				Divider[2] = Divider[1] + Divider[2];//D3变为D123
				flag = 1;
				break;
			}
		}
		return flag;
	}
	template<class I>
	friend I& operator >>(I& in, Book& book);
	template<class O>
	friend O& operator <<(O& out, const Book& book);
	//friend void test(const int &op);
	void Print(){//查找到之后输出书的全部信息
		cout << "<<" << title << ">>" << endl;
		cout << "Writer: " << writer << endl;
		cout << "ISBN: " << ISBN << endl;
	}//也可以直接使用 cout << 输出数据
};

/* 重载多个输入流 */
template<class I>
I& operator >>(I& in, Book& book){
	book.flag = true;//激活
	in >> book.title >> book.ISBN >> book.writer >> book.Divider[0];
	in.ignore(1024, '\n');//忽略行末所有字符
	for(int i = 0; i < (int)book.Divider[0].size(); i ++){//分解3级分类
		if(book.Divider[0][i] == '/'){
			book.Divider[1] = book.Divider[0].substr(1, i - 1);//从 0 到 i - 1
			book.Divider[2] = book.Divider[0].substr(i + 1);//从i + 1到字符串末尾
			book.Divider[0] = book.Divider[0].substr(0, 1);//首字
			book.Divider[1] = book.Divider[0] + book.Divider[1];//D2变为D12
			book.Divider[2] = book.Divider[1] + book.Divider[2];//D3变为D123
			break;
		}
	}
	return in;
}
/* 重载多输入输入流 */
template<class I>
I& operator >>(I& in, Book* book){
	while(in >> *book){
		book ++;
	}
	return in;
}

/* 重载输出流 */
template<class O>
O& operator <<(O& out, const Book& book){
	out << book.title << ' ';//在考虑要不要使用换行，因为book.txt里面使用的是空格，但是好像也没有什么影响。
	out << book.ISBN << ' ';//有个细节就是从book.txt读入的时候末尾有一个 1 ，不知道是不是为了方便作为了标识符。
	out << book.writer << ' ';//应该没什么影响吧，主要怕 in.ignore(1024, '\n'); 这一行出问题
	out << book.Divider[1] << '/';
	out << book.Divider[2].substr(book.Divider[1].size()) << '\n';//还原数据格式
	return out;
}
/* 重载多输出输出流 */
/*
呃呃，发现好像并不是很容易，真要重载的话可能需要在数据末尾添加结束标志(结束符)。
而且需要多输出的时候并不是很多，需要的话直接按需求用循环代替吧。
template<class O>
O& operator <<(O& out, Book* book){	}
*/


/*
int main(){
	freopen("intest.txt", "r", stdin);//从文件intest读入
	Book book[10];
	cin >> book;
	cout << book[3] << endl;
	//cout << "我是GBK!" << endl;
	return  0;
}

*/