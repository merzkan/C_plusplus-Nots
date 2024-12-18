/*
********************* Arrays, Pointers and References************************

#include <iostream>
using namespace std;

class samp{
private:
	int a;
public:
	void set_a(int n){
		a=n;
	}
	int get_a(){
		return a;
	}
};


int main(){
samp object_1[4];
int i;
for(i=0;i<4;i++){
	object_1[i].set_a(i);
}
for(i=0;i<4;i++){
	cout << object_1[i].get_a();
}

	return 0;
}
-------
0123

****************If a class type includes constructor, an array of objects can be initialized.***********************************


#include <iostream>
using namespace std;

class samp{
private:
	int a;
public:
	samp(int n){
		a=n;
	}
	int get_a(){
		return a;
	}
};

int main(){
	samp object_1[4] = {-1,-2,-3,-4};
	int i;
	for(i=0;i<4;i++){
		cout << object_1[i].get_a()<< " " << endl;
	}
	return 0;
}
---------
-1
-2
-3
-4

************************You can also have multidimensional arrays of objects*****************************
//When initializing an array of objects whose constructor
// takes more than one argument, you must use the
// alternative form of initialization

// Eğer bir sınıfın constructor'ı birden fazla argüman alıyorsa ve o sınıfın nesnelerinden oluşan bir dizi oluşturmak istiyorsanız,
 bu nesne dizisini başlatmak için alternatif başlatma yöntemi kullanmanız gerekir.


#include <iostream>
using namespace std;

class samp{
private:
	int a;
public:
	samp(int n){
		a=n;
	}
	int get_a(){
		return a;
	}
};


int main(){
	samp object_1[4][2]={1,2,3,4,5,6,7,8};
	int i;
	for(i=0;i<4;i++){
		cout<< object_1[i][0].get_a() << " ";
		cout<< object_1[i][1].get_a() << " ";
	}
	return 0;
}
----------
1 2 3 4 5 6 7 8

******************************************************************

#include <iostream>
using namespace std;

class samp{
private:
	int a,b;
public:
	samp(int n,int m){
		a=n;
		b=m;
	}
	int get_a(){
		return a;
	}
	int get_b(){
		return b;
	}
};

int main(){
	samp object_1[4][2]={samp(1,2),samp(3,4),
	samp(5,6),samp(7,8),
	samp(9,10),samp(11,12),
	samp(13,14),samp(15,16)};
int i;
for(i=0;i<4;i++){
	cout << object_1[i][0].get_a() << " "; 
	cout << object_1[i][0].get_b() << " " << endl;
	cout << object_1[i][1].get_a() << " "; 
	cout << object_1[i][1].get_b() << " " << endl;
}
cout << endl;
return 0;
}
----------------------
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16

***************************************************************************
***************************************************************************

**********************Using Pointers to Objects****************************

//Objects can be accessed via pointers. Pointer arithmetic using 
//an object is the same as it is for any other data type.

#include <iostream>
using namespace std;

class samp{
private:
	int a,b;
public:
	samp(int n ,int m){
		a = n ;
		b = m;
	}

	int get_a(){
		return a;
	}

	int get_b(){
		return b;
	}
};


int main(){
	samp object_1[4] =  {samp(1,2),samp(3,4),samp(5,6),samp(7,8)};
	int i ;
	samp *p;
	p = object_1; // Get starting address of array.  // Dizinin başlangıç adresini 'p' işaretçisine atar

	for(i=0;i<4;i++){
		cout << p->get_a() << " ";   // 'p' işaretçisinin işaret ettiği nesnenin 'a' değerini yazdırır
		cout << p->get_b() << " " << endl;  // 'p' işaretçisinin işaret ettiği nesnenin 'b' değerini yazdırır
		p++; // //Advance to next object   // 'p' işaretçisini bir sonraki nesneye ilerletir
	}

	cout << endl;

	return 0;
}
-------------------
1 2
3 4
5 6
7 8

************************************The this pointer*************************************************

//C++'ta özel bir işaretçi olan this bulunmaktadır. this işaretçisi, bir üye fonksiyonu çağrıldığında otomatik olarak o fonksiyona geçirilir ve çağrıyı yapan nesneyi işaret eder.
//C++ contains a special pointer that is called this. this is a pointer that is automatically passed to any member 
//function when it is called, and it is a pointer to the object that generates the call

//Eğer this kullanılmazsa, parametre ismi ile üye değişkeni arasında karışıklık olabilir. Örneğin

//void setValue(int value) {
//    value = value;} // Burada parametre kendi kendine atanır, üye değişken etkilenmez.

// bunu çözmek için

//void setValue(int value) {
 //   this->value = value;} // Üye değişkene parametre değeri atanır.

//summary:
//this, bir nesneye işaret eden özel bir işaretçidir.
//Bir üye fonksiyon çağrıldığında, çağrıyı yapan nesneyi belirtir.
//Özellikle üye değişkenler ile parametrelerin isimleri çakıştığında kullanılır.

#include <iostream>
#include <cstring>
using namespace std;

class inventory{
private:
	char item[20];
	double cost;
	int on_hand;
public:
	inventory(const char *i,double c, int o){
		strcpy(item,i);
		cost = c;
		on_hand = o;
	}

	void show();
};


void inventory::show(){
	cout << item << ":$" << cost << "On hand:" << on_hand << endl;
}

int main(){
	inventory object_1("wrench",4.95,4);
	object_1.show();
	return 0;
};
--------------------
wrench:$4.95On hand:4

*******************************************************************************
//this Olmadan Çalışabilir mi?
//Evet, this işaretçisi bu durumda kullanılmasa da kod doğru çalışır, çünkü parametre isimleri (i, c, o) ile üye değişkenlerin isimleri (item, cost, on_hand) farklıdır. 
//Derleyici bu farklılığı kolayca anlayabilir.

//Ne Zaman this Gerekir?
//Parametre isimleri ile üye değişken isimleri aynı olduğunda:

//Sonuç
//Bu durumda this kullanılmasa da olur.
//Ancak, kullanıldığında kodun netliği artar, hangi değişkenin parametre ve hangi değişkenin üye olduğu açıkça belli olur.
//Kodun okunabilirliği ve gelecekteki hata önleme açısından this kullanımı genelde tercih edilir.

#include <iostream>
#include <cstring>
using namespace std;

class inventory{
private:
	char item[20];
	double cost;
	int on_hand;
public:
	inventory(const char *i,double c, int o){
		strcpy(this->item,i);
		this->cost = c;
		this->on_hand = o;
	}
	void show();
};


void inventory::show(){
	cout << this->item << ":$" << this->cost << "On hand:" << this->on_hand << endl;
}

int main(){
	inventory object_1("wrench",4.95,4);
	object_1.show();
	return 0;
}
------------------
wrench:$4.95On hand:4

*****************************************************************************************
*/
