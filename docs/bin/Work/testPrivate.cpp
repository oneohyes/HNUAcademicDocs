/*
≥…‘±∑√Œ ≤‚ ‘
*/
#include<bits/stdc++.h>
using namespace std;
class Fu{
private:
	int x;
	int y;
	int *z[2];
public:
	void input(int _x, int _y){
		x = _x, y = _y;
	}
	Fu(){
		z[0] = &x, z[1] = &y;
	}
	Fu(const Fu &t){
		x = t.x, y = t.y;
	}
	friend void fuckout();
	friend void fuckoff();
}e;

struct node{
	Fu *u;
}f;

void fuckout(){
	Fu t = e;
	cout << t.x <<" "<< t.y << endl;
	cout << *t.z[0] << " " << *t.z[1] << endl;
}

void fuckoff(){
	f.u = &e;
	Fu *tmp = &e;
	cout << *(tmp -> z[0]) << endl;
}

int main(){
	int a, b;
	cin >> a >> b;
	e.input(a, b);
	fuckout();
	fuckoff();


	return 0;
}