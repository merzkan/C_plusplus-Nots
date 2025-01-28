/*
//********************* Arrays, Pointers and References************************

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
//-------
//0123

//****************If a class type includes constructor, an array of objects can be initialized.***********************************


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
//---------
//-1
//-2
//-3
//-4

//************************You can also have multidimensional arrays of objects*****************************
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
//----------
//1 2 3 4 5 6 7 8

//******************************************************************

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
//----------------------
//1 2
//3 4
//5 6
//7 8
//9 10
//11 12
//13 14
//15 16

//***************************************************************************
//***************************************************************************

//**********************Using Pointers to Objects****************************

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
//-------------------
//1 2
//3 4
//5 6
//7 8

//************************************The this pointer*************************************************

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
//--------------------
//wrench:$4.95On hand:4

//*******************************************************************************
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
//------------------
//wrench:$4.95On hand:4

//*****************************************************************************************
//*********************************Using new and delete************************************

//C++ provides a safer and more convenient way to allocate and free memory compared to malloc() and free() functions. In C++ 
//you can allocate memory using new and release it using delete. These operators takes these general forms
// 
//p*var=new type;
//delete p*var;
//type: Type specifier of the object (or variable).
//p*var: A pointer to the object (or variable).
//•new automatically allocates enough memory to hold an object of the specified type.
//You do not need to use sizeof function.
//•new automatically returns a pointer of the specified type.

#include <iostream>
using namespace std;
int main(){
	int *p;
	p = new int;
	if(!p){
		cout << "allocation error" << endl;
		return 1;
	}
	*p=1000;
	cout<<"Here is integer at p:"<<*p<<endl;
	delete p;
	return 0;
}
//---------------------------
//Here is integer at p:1000
//*****************************Here is an example that allocates an object dynamically**************


#include <iostream>
using namespace std;
class samp{
	private: int a,b;
	public:
		int set_ab(int i,int j){
			a=i;
			b=j;
		}
		int get_product(){
			return a*b;
		}
};
int main(){
	samp *p;
	p=new samp;
	if(!p){
		cout <<"Allocation error"<<endl;
		return 1;
	}
	p->set_ab(4,5);
	cout<<"product is:"<<p->get_product()<<endl;
	delete p;
	return 0;
}
//---------------
//product is:20

//****************************************************************************
//More about New and Delete
//p-var=new type (initial value);  //You can give dynamically allocated object an initial value by using this form.
//p-var=new type[size];  //To dynamically allocate a one dimensional array, use this form of new.
//delete [] p-var; //To delate dynamically allocated array,  use this form of delete

#include <iostream>
using namespace std;
int main(){
	int *p;
	p=new int[5];
	if(!p){
		cout <<"Allocation error"<<endl;
 		return 1;
	}
	for (int i=0;i<5;i++){
		p[i]=i;
	}
	for (int i=0;i<5;i++){
		cout<<"Here is integer at p["<<i<<"]:"<<p[i]<<endl;
	}
	delete []p;
	return 0;
}
//---------------
//Here is integer at p[0]:0
//Here is integer at p[1]:1
//Here is integer at p[2]:2
//Here is integer at p[3]:3
//Here is integer at p[4]:4

//*********************The program creates a dynamic array of objects.**********************


#include <iostream>
using namespace std;
class samp{
	private: int a,b;
	public:
		int set_ab(int i,int j){
			a=i;
			b=j;
		}
		int get_product(){
			return a*b;
		}
};
int main(){
	samp *p;
	int i;
	p=new samp[10];
	if(!p){
		cout <<"Allocation error"<<endl;
		return 1;
	}

	for (int i=0;i<10;i++){
		p[i].set_ab(i,i);
	}
	for (int i=0;i<10;i++){
		cout<<"product["<<i<<"]:"<<p[i].get_product()<<endl;
	}
	delete p;
	return 0;
}
//----------------------
//product[0]:0
//product[1]:1
//product[2]:4
//product[3]:9
//product[4]:16
//product[5]:25
//product[6]:36
//product[7]:49
//product[8]:64
//product[9]:81

//**********************REFERENCES**********************************************
//******************************************************************************
C++'ta, işaretçi (pointer) ile ilgili bir özellik bulunmaktadır: referans (reference). 
Bir referans, bir işaretçi (pointer) değildir. Bir referans, bir değişken için başka bir isim gibi davranan, 
dolaylı olarak bir işaretçi gibi çalışan bir yapıdır. Bir referansın üç farklı şekilde kullanılabileceği vardır.
1.bir referans fonksiyona aktarılabilir. 
2.bir fonksiyon tarafından bir referans döndürülebilir.
3.bağımsız bir referans oluşturulabilir.
*****************Pointer Kullanımı (C tarzı):**********
#include <iostream>
using namespace std;
void f(int *n);
int main(){
	int i=0;
	f(&i);
	cout <<"here is i's new value:" <<i<<endl;
	return 0;
}
void f(int *n){
	*n=100;
}
//---------
//here is i's new value:100

//****************The same program in C++****Reference Kullanım******************

#include <iostream>
using namespace std;
void f(int &n);
int main(){
	int i = 0;
	f(i);
	cout<<"here is's new value:"<<i<<endl;
	return 0;
}
void f(int &n){
	n = 100;
}
//------------
//here is's new value:100

//*************Passing References to Functions****************************
//Bir nesneyi referansla geçtiğinizde, nesnenin bir kopyası oluşturulmaz. 
//Bunun yerine, fonksiyon doğrudan orijinal nesne üzerinde işlem yapar. 

//Nesne bir kopya oluşturulmadan fonksiyona geçildiği için, fonksiyon sonunda orijinal nesne üzerinde işlem yapılır.
//BU yüzden yıkıcı (destructor) fonksiyonu çağrılmaz.


#include <iostream>
using namespace std;
class myclass{
	private:
		int who;
	public:
		myclass(int n){
			who=n;
			cout<<"constructing the object "<<who<<endl;
		}
		~myclass(){
			cout<<"destructing the object "<<who<<endl;
		}
		int id(){
			return who;
		}
};
void f(myclass o){
	cout<<"received "<<o.id()<<endl;
}
int main(){
	myclass x(1);
	f(x);
	return 0;
}
//-----------------------
//constructing the object 1
//received 1
//destructing the object 1
//destructing the object 1

//***************************The object is passed by reference*****************************


//Referansla geçirme, orijinal nesne üzerinden işlem yapıldığı için constructor yalnızca bir kez çalışır, 
destructor da yalnızca bir kez çalışır.
#include <iostream>
using namespace std;
class myclass{
	private:
		int who;
	public:
		myclass(int n){
			who=n;
			cout<<"constructing the object "<<who<<endl;
		}
		~myclass(){
			cout<<"destructing the object "<<who<<endl;
		}
		int id(){
			return who;
		}
};
void f(myclass &o){
	cout<<"received "<<o.id()<<endl;
}
int main(){
	myclass x(1);
	f(x);
	return 0;
}
//--------------------------
//constructing the object 1
//received 1
//destructing the object 1
//******************************Returning References**************************
Bir fonksiyon bir referans döndürebilir.
Referans döndürmek, özellikle bazı operatörleri aşırı yüklerken oldukça faydalı olabilir. 
Ayrıca, bir fonksiyonun bir atama ifadesinin sol tarafında kullanılmasını sağlamak için de kullanılabilir.

#include <iostream>
using namespace std;
int &f();
int x;
int main(){
	f()=100;//f() fonksiyonu çağrıldığında, f() fonksiyonu x değişkeninin referansını döndürür.
	//f() = 100; ifadesi, aslında x = 100; işlemi ile aynı şeydir. Bu işlem, x değişkenine 100 değerini atar.
	cout<<x<<endl;
	return 0;
}
int &f(){
	return x;
}
//********************************************
int &f()             
{
    int x;              
    return x;             
}                       

//Bir int referansı döndürür.
//x, bir yerel değişkendir.
//x, f() fonksiyonuna özgüdür ve f() fonksiyonu döndüğünde kapsam dışı kalacaktır.
//Bu, f() tarafından döndürülen referansın aslında geçersiz olduğu anlamına gelir.

/************************************************

#include <iostream>
using namespace std;
class array{
	int size;
	char *p;
	public:
		array(int num);
		~array(){
			delete [] p;
		}
		char &put(int i);
		char get(int i);
};
array::array(int num){
	p=new char [num];
	if(!p){
		cout << "allocation error."<<endl;
		exit(1);
	}
	size =num;
}
char &array::put(int i){
	if(i<0 || i>=size){
		cout<<"sınır hatası"<<endl;exit(1);
	}
	return p[i];
}
char array::get(int i){
	if(i<0||i>=size){
		cout<<"bounds error"<<endl;exit(1);
	}
	return p[i];
}
int main(){
	array a(10);
	a.put(3)='X';
	a.put(2)='R';
	cout <<a.get(3)<<" "<<a.get(2)<<endl;
	a.put(11)='!';
	return 0;
}
//************************Bağımsız Referanslar ve Kısıtlamalar***************

//Bağımsız referans, bir değişkenin başka bir ismi olan referans değişkenidir. 
//Bağımsız bir referans, tanımlandığında başlatılmalıdır.
//
//Kısıtlamalar:
//Bir referansı başka bir referansa atayamazsınız.
//Bir referansın adresini alamazsınız.
//Referanslardan diziler oluşturamazsınız.
//Bir bit-alanını (bit-field) referans alamazsınız.
//Referanslar, sınıf üyeleri, dönüş değerleri veya fonksiyon parametreleri hariç olmak üzere başlatılmadan kullanılamaz.


//ref = 100;: ref, x'in referansı olduğu için, ref'e 100 değeri atandığında, aslında x'e 100 değeri atanmış oluyor. Yani x = 100 oldu.
//cout << x << " " << ref << endl;: Hem x hem de ref aynı değişkene (yani x) işaret ediyor. Bu yüzden hem x hem de ref 100 değerini taşıyor.

#include <iostream>
using namespace std;

int main(){
	int x;
	int &ref=x;
	x=10;
	ref=100;
	cout<<x<<" "<<ref<<endl;
	return 0;
}
//----------------------
//100 100
//********************************Chapter 5 Function Overloading*********************************
//***********************************************************************************************


#include <iostream>
using namespace std;

class myclass{
	private:
		int x;
	public:
		myclass(){
			x=0;
		}
		myclass(int n){
			x=n;
		}
		int getx(){
			return x;
		}
};
int main(){
	myclass object_1(10);
	myclass object_2;
	cout<<"object_1:"<<object_1.getx()<<endl;
	cout<<"object_2:"<<object_2.getx()<<endl;
	return 0;
}
//-----------------
//object_1:10
//object_2:0
//***************************************************

#include <iostream>
using namespace std;

class myclass{
	private:
		int x;
	public:
		myclass(){
			x=0;
		}
		myclass(int n){
			x=n;
		}
		int getx(){
			return x;
		}
};
int main(){
	myclass object_1[10];
	myclass object_2[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++){
		cout<<"object_1["<<i<<"]:"<<object_1[i].getx()<<" "<<endl;
		cout<<"object_2["<<i<<"]:"<<object_2[i].getx()<<" "<<endl;
		cout<<endl;
	}
	return 0;	
}
//-------------
//object_1[0]:0 
//object_2[0]:1 
//
//object_1[1]:0 
//object_2[1]:2 
//
//object_1[2]:0 
//object_2[2]:3 
//
//object_1[3]:0 
//object_2[3]:4 
//
//object_1[4]:0 
//object_2[4]:5 
//
//object_1[5]:0 
//object_2[5]:6 
//
//object_1[6]:0 
//object_2[6]:7 
//
//object_1[7]:0 
//object_2[7]:8 
//
//object_1[8]:0 
//object_2[8]:9 
//
//object_1[9]:0 
//object_2[9]:10 

//*******************************************************************

#include <iostream>
#include <cstdio> // sscanf için gerekli
using namespace std;
class date{
	int day,month,year;
public:
	date(const char *str);
	date(int m,int d,int y){
		day=d;
		month=m;
		year=y;
	}
	void show(){
		cout<<month<<'/'<<day<<'/'<<year<<endl;
	}
};
date::date(const char *str){
	sscanf(str,"%d/%d/%d",&month,&day,&year);
}

int main(){
	date sdate("8/23/2010");
	date idate(8,23,2010);
	sdate.show();
	idate.show();
    return 0;
}
//-------------
//8/23/2010
//8/23/2010
//************************************************************************

#include <iostream>
using namespace std;
class myclass{
	private:
		int x;
	public:
		myclass(){
			x=0;
		}
		myclass(int n){
			x=n;
		}
		int getx(){
			return x;
		}
		void setx(int n){
			x=n;
		}
};
int main(){
	myclass *p;
	myclass object_1(10);
	p=new myclass[10];
	if(!p){
		cout<<"allocation error"<<endl;
		return 1;
	}
	for(int i=0;i<10;i++){
		p[i]=object_1;
	}
	for(int i=0;i<10;i++){
		cout<<"p["<<i<<"]:"<<p[i].getx()<<" "<<endl;
	}
	delete []p;
	return 0;
}
//------------------
//p[0]:10 
//p[1]:10 
//p[2]:10 
//p[3]:10 
//p[4]:10 
//p[5]:10 
//p[6]:10 
//p[7]:10 
//p[8]:10 
//p[9]:10 
//*********************************************************

//*********************************Creating and Using a Copy Constructor**************************
//************************************************************************************************

//Bir Kopya Kurucu Oluşturmak ve Kullanmak:
//Bir nesne bir fonksiyona geçirildiğinde veya bir fonksiyondan döndürüldüğünde sorunlar ortaya çıkabilir.
//Bu sorunları önlemenin bir yolu, bir kopya kurucu (copy constructor) tanımlamaktır.
//Bir nesne bir fonksiyona geçirildiğinde, o nesnenin bit-seviyesinde (tam olarak aynı) bir kopyası yapılır 
//ve bu kopya, fonksiyon parametresine atanır.
//Ancak, bazı durumlarda bu birebir kopya istenmeyen durumlara yol açabilir.
//Örneğin, eğer nesne dinamik olarak tahsis edilmiş bir belleği (pointer ile) içeriyorsa yapılan kopya da aynı belleği işaret eder.
//Bu nedenle, eğer bu kopya belleğin içeriğini değiştirirse, orijinal nesnenin belleği de değişir.
---------------------------------------------------------------------------------------
//Sonuç:
//Kopya Kurucu: Özellikle dinamik bellek kullanan sınıflarda, nesneleri güvenli şekilde kopyalamak için gereklidir.
//Deep Copy: Kopya kurucunun en yaygın kullanım şeklidir. Bellek paylaşım sorunlarını önler.
//Varsayılan Kopya: Sadece basit veri türleri içeren sınıflar için güvenlidir. Ancak, dinamik bellek kullanıyorsanız, mutlaka bir kopya kurucu tanımlamanız gerekir.
---------------------------------------------------------------------------------------
//Kopya Kurucusu, Aşağıdaki Üç Durumda (Otomatik Olarak) Çağrılır:
//1.Bir nesne başka bir nesneyi başlatmak için kullanıldığında (declaration - bildirimde).
MyClass obj1(10);  // Parametreli constructor çağrılır
MyClass obj2 = obj1;  // Copy constructor çağrılır
---------------------------------------------------------------------------------------
//2.Bir nesne bir fonksiyona parametre olarak geçirildiğinde.
void printObject(MyClass obj) {
   obj.show();
}

MyClass obj1(5);
printObject(obj1);  // Copy constructor çağrılır
---------------------------------------------------------------------------------------
//3.Bir fonksiyon tarafından döndürülecek geçici bir nesne oluşturulduğunda
MyClass createObject() {
    MyClass temp(20);
    return temp;  // Copy constructor çağrılır
}

MyClass obj1 = createObject();  // createObject() fonksiyonu tarafından döndürülen nesne kopyalanır
---------------------------------------------------------------------------------------
Kopya Kurucusunun En Yaygın Formu Şu Şekildedir:

classname (const classname &obj)
{ // Kurucu gövdesi. }

//Burada obj, başka bir nesneyle başlatılan nesnenin referansıdır. 
//Örneğin, myclass adlı bir sınıf olduğunu ve y adlı bir myclass nesnesi bulunduğunu varsayalım.
//Aşağıdaki ifadeler, myclass kopya kurucusunu çağıracaktır:
//myclass x = y;  // y, açıkça x'i başlatıyor.
//func1(y);        // y, parametre olarak geçirilmiş.
//z = func2();     // z, döndürülen nesneyi alıyor.
//İlk iki durumda, y nesnesine bir referans kopya kurucusuna gönderilecektir. Üçüncü durumda ise, func2() tarafından döndürülen nesneye bir referans gönderilecektir.

//example: (copy constructor)) /////yanlıs


#include <iostream>
#include <cstdlib>
using namespace std;
class array{
	int size;
	int *p;
	public:
		array(int sz){ //constructor
			p=new int[sz];
			if(!p){
				exit(1);
			}
			size =sz;
			cout<<"using 'normal' constructor"<<endl;
		}
		~array(){
			delete[]p;
		}
		array(const array &ob1);//copy conctructor

		int get(int i){
			return p[i];
		}
		void put(int i,int j){
			if(i>=0 && i<size){
				p[i]=j;
			}
		}
};
array::array(const array &a){
	int i;
	size=a.size;
	p=new int[a.size];
	if(!p){
		cout<<"allocation error"<<endl;
		exit(1);
	}
	for(int i=0;i<a.size;i++){
		p[i]=a.p[i];
		cout<<"using copy constructor"<<endl;
	}
}

int main(){
	array num(10);
	array num_1(20);
	for(int i=0;i<num.size;i++){
		num.put(i,i);
	}
	for(int i=0;i<num.size;i++){
		cout<<num.get(i)<<endl;
	}
	array x=num;
	for(int i=0;i<10;i++){
		cout<<x.get(i);
	}
	num_1=num;
	return 0;
}
/**********************************************************************
//incorrect

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype{
private:
	char *p;
public:
	strtype(char s);
	~strtype(){
		delete []p;
	}
	char *get(){
		return p;
	}
};

strtype::strtype(char *s){
	int l;
	l=strlen(s)+1;
	p=new char [l];
	if(!p){
		cout<<"allocation error"<<endl;
		exit(1);
	}
	strcpy(p,s);
}
void show(strtype x){
	char *s;
	s=x.get();
	cout<<s<<endl;
}

int main(){
	strtype a("Hello"),b("There");
	show(a);
	show(b);
	return 0;
}


//*********************************************
//correct

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype{
private:
	char *p;
public:
	strtype(const char* s);
	strtype(const strtype &o);
	~strtype(){
		delete[]p;
	}
	char* get() const {
		return p;
	}
};

strtype::strtype(const char *s){
	int l;
	l =strlen(s)+1;
	p=new char[l];
	if(!p){
		cout<<"allocation error"<<endl;
		exit(1);
	}
	strcpy(p,s);
}

strtype::strtype(const strtype &o){
	int l;
	l=strlen(o.p)+1;
	p=new char[l];
	if(!p){
		cout<<"allocation error"<<endl;
		exit(1);
	}
	strcpy(p,o.p);
}
void show(const strtype &x){
	char *s;
	s=x.get();
	cout<<s<<endl;
}

int main(){
	strtype a("Hello"),b("There");
	show(a);
	show(b);
	return 0;
}
//-----
//Hello
//There
//*********************************Using Default Arguments****************************************
//************************************************************************************************

//C++'ın fonksiyon aşırı yüklemesiyle ilgili bir özelliği vardır.
//Bu özelliğe varsayılan argüman denir ve fonksiyon çağrıldığında karşılık gelen bir argüman belirtilmediğinde 
//bir parametreye varsayılan bir değer vermenize olanak tanır.
//Varsayılan argümanları kullanmak, esasen fonksiyon aşırı yüklemesinin kısaltılmış halidir.

#include <iostream>
using namespace std;

void f(int a=0, int b=0){
    cout << "a:" << a << ", b:" << b << endl;
}

int main(){
    f();
    f(10);
    f(10, 20);
    return 0;
}
//-----------
//a:0, b:0
//a:10, b:0
//a:10, b:20
/***********************************************************************

#include <iostream>
using namespace std;
class myclass{
	private:
		int x;
	public:
		myclass(int n=0){
			x=n;
		}
		int getx(){
			return x;
		}
};

int main(){
	myclass o1(10);
	myclass o2;
	cout<<"o1:"<<o1.getx()<<endl;
	cout<<"o2:"<<o2.getx()<<endl;
}

//-----
//o1:10
//o2:0

//****************************Overloading and Ambiguity****************************
//*********************************************************************************

//Fonksiyonları aşırı yüklediğinizde, programınızabelirsizlik katmak mümkündür.

//Aşırı yüklemeden kaynaklanan belirsizlik, tür dönüşümü, referans parametreleri 
//ve varsayılan argümanlar yoluyla katılabilir.

//Programınızın hatasız derlenmesi için belirsizlikkaldırılmalıdır


#include <iostream>
using namespace std;
float f(float i){
	return i/2.0;
}
double f(double i){
	return i/3.0;
}
int main(){
	float x=10.09;
	double y=10.09;
	cout<<f(x)<<endl;//unambiguous
	cout<<f(y)<<endl;//unambiguous
	cout<<f(10)<<endl;//ambiguous, convert 10 to double or float.
	return 0;
}
//****************************************************************************


#include <iostream>
using namespace std;
void f(unsigned char c){
	cout<<c<<endl;
}
void f(char c){
	cout<<c<<endl;
}
int main(){
	f('c');//unambiguous
	f(86); ambiguous. Which f() is called
	return 0
}
//****************************************************************************


#include <iostream>
using namespace std;
int f(int a,int b){
 	return a+b;
}
int f(int a,int &b){
 	return a-b;
}
int main(){
	int x=1,y=2;
	cout<<f(x,y);
	return 0;
}
//Belirsiz. Hangi f() çağrılacak?

**********************Finding the Address of an Overloaded Function******************
*************************************************************************************
//C dilinde bir fonksiyonun adresini almak basittir;
//bir fonksiyon ismi işaretçi türüne atanabilir.
//Ancak C++ dilinde, bir fonksiyonun aşırı yüklenmesi (overloading) nedeniyle, hangi fonksiyonun adresinin alındığını belirlemek daha karmaşıktır.
//Çünkü C++'ta aynı isimde farklı parametre türlerine sahip birden fazla fonksiyon olabilir. 
//Bu durumda, işaretçiye hangi fonksiyon türünün atanacağı işaretçinin nasıl tanımlandığına bağlıdır.
//C dilinde fonksiyonlar aşırı yüklenemezken, C++'ta aynı fonksiyon adıyla farklı parametre türlerine sahip birden fazla fonksiyon tanımlanabilir.
//Bu nedenle, işaretçiyi tanımlarken türünü doğru belirtmek önemlidir.
//Bu sayede, hangi fonksiyonun adresinin işaretçiye atanacağı belirlenir.

//Example: Illustrate assigned function pointers to overloaded functions.
#include <iostream>
using namespace std;
void space(int count){
	for(;count;count--){
		cout<<' ';
	}		
	cout<<"end"<<endl;
}
void space(int count,char ch){
	for(;count;count--){
		cout<<ch;
	}
	cout<<"end"<<endl;
}

int main(){
	void(*fp1)(int);
	void(*fp2)(int,char);
	fp1=space;
	fp2=space;
	fp1(22);
	fp2(30,'x');
	return 0;
}
//-------
//                      end
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxend
*/