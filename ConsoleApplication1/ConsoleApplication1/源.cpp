#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*int *foo(int*x, int*y){
	int*z = y;
	y = x;
	cout << *z << " " << *y << endl;
	if (*z < *y)
		return y;
	return z;
}
int bar(int*y, int*x){
	int c;
	c = *x - *y;
	y = foo(&c, x);
	cout << c << " "<<  *y << endl;
	return *y;
	}
int main(){
	int a = 1, b = 10, c;
	foo(&a, &b);
	c = bar(&b, &a);
	cout << c << endl;
	return 0;
	}*/
int main(){
	string s("");
	int x = 0, y = 0, z;
	ifstream fin("a.txt");
	fin >> s;
	while (s != "kkk"){
		fin >> z;
		if (s == "iii"){
			x += z;
			y -= z*z;
		}
		else if (s == "jjj"){
			x -= z;
			y += z*z;
		}
		fin >> s;
	}
	fin.close();
	cout << x << " " << y << endl;
	return 0;
}