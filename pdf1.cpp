/*
#include <iostream>
using namespace std;

class MyClass {
// private:
//   int a;   // If “a”’ is defined as a public member, “a”‘ can be accessible outside of the object.
 public:
    int a;                // Doğru bir şekilde tanımlandı
    void set_a(int num);  // Fonksiyonun deklarasyonu
    int get_a();          // Fonksiyonun deklarasyonu
};

void MyClass::set_a(int num) {
    a = num;  // a değişkenine değer atandı
}

int MyClass::get_a() {
    return a;  // a değişkeni döndürüldü
}

int main() {
    MyClass object_1, object_2;  // MyClass sınıfından iki nesne oluşturuldu

    object_1.set_a(15);          // object_1'in a değişkenine 15 atandı
    object_2.set_a(22);          // object_2'nin a değişkenine 22 atandı

    cout << "The value of a in object_1: " << object_1.get_a() << endl;
    cout << "The value of a in object_2: " << object_2.get_a() << endl;

    return 0;
}
-----------------------------
The value of a in object_1: 15
The value of a in object_2: 22

*****************************************************************************************************

#include <iostream>
 using namespace std;
 class myclass {
 public:
    int a;
 };

 int main(){
 myclass object_1,object_2;
 object_1.a=15;object_2.a=22;
 cout<<" The value of a in object_1 : "<<object_1.a<<endl;
 cout<<" The value of a in object_1 : "<<object_2.a<<endl;
 return 0;
 }
 -------------------------------
 The value of a in object_1 : 15
 The value of a in object_1 : 22

*****************************************************************************************************

#include <iostream>
 using namespace std;
 int main(){
 bool outcome;
 if(outcome) cout<<"true";
 else cout<<"false";
 return 0;
}
-------
false

*****************************************************************************************************

 #include <iostream>
 using namespace std;
 int abs1(int n);
 long abs1(long n);
 double abs1(double n);
 int main(){
    int x=5;
    long y=10; 
    double z=20.12;
    cout <<"integer number:"<<abs1(x)<<endl;
    cout<<"long integer number:"<<abs1(y) << endl;
    cout<<"double (reel) number :"<<abs1(z)<<endl;
    return 0;
 }
 //variable = (condition) ? expressionTrue : expressionFalse;
 int abs1(int n){
 return n<0 ? -n:n;
 }

 long int abs1(long int n){
 return n<0 ? -n:n;
 }
 
 double abs1(double n){
 return n<0 ? -n:n;
 }
------------------------
integer number:5
long integer number:10
double (reel) number :20.12

*****************************************************************************************************

//Neden const Gerekli?
//C++ string sabitleri (örneğin "8/23/2010") derleme zamanında bellekte sabit olarak saklanır. Bu sabitler değiştirilemez.
//char* ise değiştirilebilir bir karakter dizisini temsil eder. String sabitini char* olarak kullanmak, değiştirilemez bir şeyi değiştirilebilir bir yere koymaya çalışmak gibi algılanır.
//const char* ile, fonksiyona string sabiti geçirirken onun değiştirilmeyeceğini belirtmiş oluruz, böylece uyarı kalkar.
#include <iostream>
using namespace std;
void date(const char *date);
void date(int month,int day,int year);

int main(){
    date("8/23/2010");
    date(8,23,2010);
    return 0;
}

void date(const char *date){
    cout << "date:" << date << endl;
}

void date(int month,int day,int year){
    cout << "date:" << month << "/" << day << "/"  << year << endl;
}
--------------
date:8/23/2010
date:8/23/2010

*****************************************************************************************************

#include <iostream>
using namespace std;
void f1(int a);
void f1(int a, int b);
int main(){
f1(10);
f1(3,7);
return 0;
}
void f1(int a){
cout<<"one argument :"<<a<<endl;
}
void f1(int a,int b){
cout << "The first parameter :" << a << "The second parameter :" << b;
}
-------------------------------------------
one argument :10
The first parameter :3The second parameter :7


*******************Chapter 2 Introducing Classes*********************************************************
*********************************************************************************************************
 
#include <iostream>
using namespace std;
class myclass{
    private:
        int a; //private alanda 'a' adında bir değişken tanımlanıyor (sadece sınıf içinde erişilebilir)
    public:
        myclass();//constructor 
        ~myclass();//destructor
        void set_a(int num); // 'a' değişkenine değer atayan fonksiyon
        int get_a(); // 'a' değişkeninin değerini döndüren fonksiyon
};

void myclass::set_a(int num){
    a=num;
}
int myclass::get_a(){
    return a;
}

myclass::myclass(){ //Constructor tanımı (Nesne oluşturulduğunda çalışır)
    cout << "In constructor " << endl;
}
myclass::~myclass(){ // Destructor tanımı (Nesne yok edilmeden önce çalışır)
    cout << "In destructor" << endl;
}
int main(){
    myclass object_1,object_2;
    object_1.set_a(15);
    object_2.set_a(22);
    return 0;// Program sonlanır ve destructor çağrılır
}
----------------
//In constructor
//In constructor
//In destructor
//In destructor

*****************************************************************************************************

//Bu kod, C++'ta dinamik bellek kullanımını, constructor ve destructor kavramlarını, pointerlarla string manipülasyonunu ve bellek yönetimini öğretir.
//Ayrıca, malloc() ve free() gibi C tarzı bellek yönetim fonksiyonlarının C++'ta nasıl kullanılacağını gösterir.

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define size 255

class strtype{
private:
    char *p; //Dinamik bellekten ayrılan stringi tutan pointer
    int len; // Stringin uzunluğunu tutacak değişken
    public:
        strtype();//constructor
        ~strtype();//destructor
        void set(const char *ptr); // Stringi atamak için fonksiyon  Bu fonksiyon, dışarıdan bir string alır ve bunu p'ye kopyalar.
        void show();  // Stringi ve uzunluğunu göstermek için fonksiyon
};      

strtype::strtype(){
    p = (char *) malloc(size); 
    //malloc fonksiyonu, size kadar baytlık bellek ayırır ve bu belleği p işaretçisine atar.Burada p bir char* türünde olmalı, yani karakter dizisi işaretçisi.
    //malloc fonksiyonu bir void* (boş işaretçi) döndürür, bu da herhangi bir türdeki işaretçiye dönüştürülebilir.
    // Burada (char *) ifadesi, malloc'ın döndürdüğü void* işaretçisini char* türüne dönüştürmek için kullanılır.
    // Bu genellikle, ayırdığınız belleği karakter dizisi gibi kullanmak için yapılır.
    if(!p){ // malloc fonksiyonu, eğer bellek ayıramazsa nullptr döndürür.
        cout << "Allocation Error" << endl; //Bu satır, eğer p işaretçisi nullptr ise (yani bellek ayırılamamışsa), bir hata mesajı yazdırır
        exit(1); // programı sonlandırır
    }
    *p='\0'; // Eğer belleği ayırdıktan sonra p'ye bir değer atamazsak, p bellekten rastgele bir değer alır ve bu da undefined behavior'a yol açabilir. 
             // *p = '\0'; komutu, p'yi geçerli bir null-terminated string'e başlatmak için gereklidir.
             // Yani, bu satırla p'nin başlangıçta boş bir string olarak kabul edilmesini sağlıyoruz. 
             // Bu, ileride p'yi kullanmadan önce güvenli bir başlangıç noktası sağlar.
             // p işaretçisinin işaret ettiği bellek alanına, yani ayrılan ilk bayta null terminatör ('\0') değeri atanır.
             // Bu, karakter dizilerinin sonunu belirtmek için kullanılır. Buradaki amaç, ayrılan belleğin başlangıcına boş bir string yerleştirmektir.
    len=0; // Bu değişken, p'deki stringin uzunluğunu tutar. Ancak başlangıçta herhangi bir stringimiz olmadığı için, uzunluk 0 olmalıdır.
           // len değişkeni, string'in uzunluğunu tutan bir değişken olabilir. Yapıcıda, string'in uzunluğu sıfır olarak başlatılır.
}

strtype::~strtype(){
    cout << "Freening p" << endl ;
    free(p); //bellek kullanıldıktan sonra free(p) ile bu bellek serbest bırakılmalıdır. Aksi takdirde, bellekte sızıntılar meydana gelebilir
}

void strtype::set(const char *ptr){
    if(strlen(ptr) >= size){ // Eğer stringin uzunluğu size değerine eşit veya büyükse, hata mesajı yazdırılır ve program sonlandırılır.
        cout << "String too big";
        exit(1);
    }
    strcpy(p,ptr); // strcpy(p, ptr) komutu, ptr stringindeki tüm karakterleri p'ye kopyalar
    len=strlen(p); // p'deki stringin uzunluğunu len değişkenine atar.

}
void strtype::show(){
    cout << p << "Length of the string is:" << len << endl; //p'deki stringi ekrana yazdırır. len değişkeni, stringin uzunluğunu tutar ve bu da ekrana yazdırılır.
}

int main(){
    strtype s1,s2; // `strtype` sınıfından iki nesne oluşturuluyor
    s1.set("This is a test");// s1 nesnesine bir string atanıyor
    s2.set("I like C++");
    s1.show();//s1 nesnesinin içeriği ve uzunluğu ekrana yazdırılır
    s2.show();
    return 0;
}
---------------
This is a testLength of the string is:14
I like C++Length of the string is:10
Freening p
Freening p

************************Constructors That Take Parameters ************************************************

#include <iostream>
using namespace std;

class myclass{
private:
    int a;
    public:
        myclass(int x); // constructor
        void show();
};

myclass::myclass(int x){
    cout << "constructor" << endl; 
    a=x;
}

void myclass::show(){
    cout << a << endl;
}

int main(){
    myclass object_1(5);
    object_1.show();
    return 0;
}
-----------------
constructor
5
***************************Introducing Inheritance*************************************************

#include <iostream>
using namespace std;

class B{
private:
    int i;
    public:
        void set_i(int n);
        int get_i();
};

class D:public B{
private:
    int j;
    public:
        void set_j(int n);
        int mul();
};

void B::set_i(int n){
    i=n;
}
int B::get_i(){
    return i;
}

void D::set_j(int n){
    j=n;
}

int D::mul(){
    return j*get_i();
}

int main(){
    B ob1;
    D ob2;
    ob1.set_i(10);
    ob2.set_i(20);
    ob2.set_j(30);
    cout << ob1.get_i() << endl;
    cout << ob2.get_i() << endl;
    cout << ob2.mul() << endl;
    return 0;
}
---------
10
20
600

***************************Object Pointers*************************************************

#include <iostream>
using namespace std;

class myclass{
private:
    int a;
public:
    myclass(int x); // constructor
    int get();
};

myclass::myclass(int x){
    a=x;
}

myclass::get(){
    return a;
}

int main(){
    myclass ob_1(125);
    myclass *p;
    p = &ob_1;
    cout << "Value using Object:" << ob_1.get() << endl;
    cout << "Value using poineter:" << p->get() << endl;
    return 0;
}
--------
Value using Object:125
Value using poineter:125

********************Classes, Structures, and Union are Related*************************************************

#include <iostream>
#include <cstring>
using namespace std;
struct st_type{
    st_type(double b,const char *n); // constructor
    void show();
    private:
    double balance;
    char name[40];
};

st_type::st_type(double b,const char *n){
    balance = b;
    strcpy(name,n);
}

void st_type::show(){
    cout << "Name:" << name << endl;
    cout << "Balance:" << balance << endl;
}

int main(){
    st_type account_1(125,"Ahmet");
    st_type account_2(250,"Ayse");
    account_1.show();
    account_2.show();
    return 0;
}
------------
Name:Ahmet
Balance:125
Name:Ayse
Balance:250

********************************Union***************************************************
Özet: Union Ne İşe Yarar?
Bellek tasarrufu sağlamak için kullanılır.
Aynı anda yalnızca bir üyenin değerinin anlamlı olduğu durumlarda faydalıdır.
Donanım kontrolü, protokol yönetimi veya veri yorumlama gibi düşük seviyeli uygulamalarda yaygın olarak kullanılır.
Union'ın Özellikleri
1.Bellek Paylaşımı:
Bir union’ın tüm üyeleri aynı anda bellekte yer kaplamaz.
Union'ın bellekte kapladığı alan, en büyük veri türüne sahip üyesinin boyutuna eşittir.

2.Sınıf Özellikleri:
C++’ta union, aslında bir sınıf türü gibi davranır ve içine hem veri üyeleri hem de fonksiyon üyeleri eklenebilir.

3.Erişim Seviyeleri (Varsayılan Public):
Struct ve union'larda, üyeler varsayılan olarak publictir. Ancak erişim seviyesi private veya protected olarak da değiştirilebilir.

4.Yapıcı ve Yıkıcı (Constructor & Destructor):
Bir union, yapıcı (constructor) ve yıkıcı (destructor) fonksiyonlara sahip olabilir. Ancak bunların kullanımı sınırlıdır (örneğin, nesne üyesi içeremez).


// Union'da tüm üyeler aynı bellek alanını paylaşır.
//union Example {
    int x;     // 4 byte
    float y;   // 4 byte   Bu örnekte, x ve y aynı bellek alanını paylaşır. Eğer x'i değiştirirseniz, y'nin değeri de etkilenir.
//};


****************************************Union*************************************************

//Bu kodun amacı:
//Union'ın aynı bellek alanını paylaşan üyeler arasında nasıl çalıştığını göstermek.
//Bellek paylaşımı yüzünden bir üyenin değerinin değişmesi, diğer üyelerin değerlerini anlamsız hale getirir.


#include <iostream>
using namespace std;
union union_x{
    int x;
    double y;
    void show_data();
};

void union_x::show_data(){
    cout << "The value of x:" << x << endl;
    cout << "the value of y " << y << endl;
}

int main(){
    union_x union_1;
    union_1.x=15;
    union_1.show_data();
    union_1.y=20;
    union_1.show_data();
    return 0;
}
------------------
The value of x:15  //x'in değeri doğrudur çünkü x = 15 atanmıştır.
the value of y 1.78028e-307 //y, aynı belleği paylaştığı için bellek alanındaki veriyi rastgele bir şekilde yorumlar.
The value of x:0 //x, aynı belleği paylaştığı için önceki değerini kaybetmiştir ve anlamsız bir sonuç verir.
the value of y 20 //y'nin değeri doğrudur çünkü y = 20 atanmıştır.

*********************************(anonymous union)********************************************************

#include <iostream>
using namespace std;

int main(){
    union{
    int i;
    char ch[4];
    };
    i=10;
    cout << "The value of i:" << i << "The value of ch:" << ch << endl;
    ch[0]='x';
    cout << "The value of i:" << i << "The value of ch:" << ch << endl;
    return 0;
}
-----------
The value of i:10The value of ch:

The value of i:120The value of ch:x

***********************************In-Line Functions*************************************************
//Inline Fonksiyon Nedir?
//Tanımı: inline anahtar kelimesi kullanılarak tanımlanan fonksiyonlardır.
//Çalışma Prensibi: Derleyici, bu fonksiyonun kodunu çağrıldığı yere kopyalamaya çalışır.
//Bu mekanizma, özellikle küçük ve sık kullanılan fonksiyonlarda performansı artırabilir.


#include <iostream>
using namespace std;
inline int even(int x){
    if(!(x%2)){
        cout << x << "is an even number" << endl;
    }
    else{
        cout << x << "is an odd number" << endl;
    }
}

int main(){
    int i;
    i=5;
    even(i);
    i=6;
    even(i);
    return 0;
}
-------------------
5is an odd number
6is an even number

*************************************Automatic In-Lining********************************************

#include <iostream>
using namespace std;
class samp{
private:
    int i,j;
public:
    samp(int a,int b);
    void divisible(){
        if(!(i%j)){
            cout << i << "divisible by" << j << endl;
        }
        else{
            cout << i <<"is not divisible by" << j << endl;
        }
    }
};
samp::samp(int a,int b){
    i=a;
    j=b;
}

int main(){
    samp ob_1(10,2),ob_2(10,3);
    ob_1.divisible();
    ob_2.divisible();
    return 0;
}
-------------------
10divisible by2
10is not divisible by3

********************************Chapter 3 A Closer Look at Classes******************************************************
************************************************************************************************************************

#include <iostream>
using namespace std;
class myclass{
private:
    int a,b;
    public:
        void set(int i ,int j){
            a=i;
            b=j;
        }
        void show(){
            cout << a << " " << b << endl;
        }
};

int main(){
    myclass ob_1,ob_2;
    ob_1.set(10,4);
    ob_2=ob_1;  //assign ob_1 to ob_2
    ob_1.show(),
    ob_2.show();

    return 0;
}
------------
10 4
10 4

*******************************************************************************************************

//This program contains an error)
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype{
private:
    char *p;
    int len;
public:
    double y;
    void set(const char *ptr,double x);
    strtype(const char *ptr);
    ~strtype();
    void show();
};

strtype::strtype(const char *ptr){
    len=strlen(ptr);
    p = (char *) malloc(len+1);
    if(!p){
        cout << "Allocation error" << endl;
        exit(1);
    }
    strcpy(p,ptr);
}

strtype::~strtype(){
    cout << "freeing p. The value of y is:" << y << endl;
    free(p);
}

void strtype::show(){
    cout << p << "The length of the string is:" << len << "The value of y is:" << y << endl;
 }

void strtype::set(const char *ptr,double x){
    y=x;
    if(strlen(ptr)>=len){
        len = strlen(ptr)+1;
        free(p);
        p = (char *) malloc(len);
        if(!p){
            cout << "Allocation error" << endl;
            exit(1);
        }
    }
    len = strlen(ptr) + 1;
    strcpy(p,ptr);
}


int main(){
    strtype s1,s2;
    s1.set("This is a test");
    s2.set("I like C++");
    s1.show();
    s2.show();
    s2=s1; //This generates an error
    s1.show();
    s2.show();
    return 0;
}
//After assigning s1 to s2, both s1’s p and s2’s p will point to the
//same memory. Thus, when these objects are destroyed, the
// memory pointed to by s1’s p is freed twice and the memory
// originally pointed to by s2’ p is not freed at all

******************Passing Objects to Functions********By-Value *******************************************************
//Bu program, değerle iletimin (by value) bir nesnenin kopyasının oluşturulmasına neden olduğunu ve
//fonksiyon içinde yapılan değişikliklerin orijinal nesneyi etkilemediğini gösterir.
// a etkilenmedi

#include <iostream>
using namespace std;

class samp{
private:
    int i;
public:
    samp(int n){
        i=n;
    }
    void set_i(int n){
        i=n;
    }
    int get_i(){
        return i;
    }
};

void sqrt_it(samp o){
    o.set_i(o.get_i()*o.get_i());
    cout << "The value of a(in function sqrt_it()):" << o.get_i() << endl;
}

int main(){
    samp a(10); //  samp a(10); satırı ile bir samp nesnesi oluşturulur ve değeri 10 olarak atanır.
    sqrt_it(a); // fonksiyonu çağrılır. Bu durumda a nesnesinin bir kopyası fonksiyona geçirilir (by value). Yani, "o" adında yeni bir nesne oluşturulur ve a'nın değeri o'ya kopyalanır.
    cout << "The value of a:" << a.get_i() << endl;
    return 0;
    //sqrt_it fonksiyonu, nesnenin değerini kareler ve bu yeni değeri ekrana yazdırır. Ancak, burada o nesnesi sadece fonksiyona geçici olarak verilmiştir ve fonksiyon bittiğinde yok olur.
    //Bu nedenle a nesnesinin değeri, fonksiyon içinde yapılan değişikliklerden etkilenmez.
}

//Yapıcı fonksiyon (constructor), bir nesne oluşturulurken çağrılır, ancak nesne bir fonksiyona değerle geçildiğinde, kopya yapıcı (copy constructor) çağrılır. Yani, fonksiyona gönderilen nesnenin kopyası oluşturulurken yapıcı fonksiyon değil, kopya yapıcı devreye girer.
//Yapıcı fonksiyon, nesne ilk kez oluşturulduğunda çağrılır ve nesnenin bellekte yer almasını sağlar.
//Kopya yapıcı, bir nesne başka bir nesneye kopyalandığında devreye girer. Bu fonksiyon, orijinal nesnenin tüm değerlerini kopyalanan nesneye aktarır.

//Yapıcı fonksiyon nesne ilk kez yaratıldığında çağrılır.
//Kopya yapıcı fonksiyon bir nesne kopyalandığında çağrılır (değerle geçişte).
//Yıkıcı fonksiyon nesne bellekten silindiğinde çağrılır, fakat sadece kopyalanan nesne için.
---------------------------------------------
The value of a(in function sqrt_it()):100
The value of a:10

*********************************By-Reference*******************************************************
//Eğer orijinal nesne üzerinde değişiklik yapmak isterseniz, nesneyi referansla (by reference) iletmelisiniz. Örneğin:
// a etkilendi
#include <iostream>
using namespace std;
class samp{
private:
    int i;
public:
    samp(int n){
        i=n;
    }
    void set_i(int n){
        i=n;
    }
    int get_i(){
        return i;
    }
};

void sqrt_it(samp *o){
    o->set_i(o->get_i()*o->get_i());
    cout << "i of the object that passed to function by a pointer:" << o->get_i() << endl;
}

int main(){
    samp a(10);
    sqrt_it(&a); //İşaretçi kullanımı, fonksiyon içinde yapılan değişikliklerin orijinal nesneye yansımasına olanak sağlar, çünkü fonksiyona işaretçi ile geçilen nesne orijinal nesneye doğrudan bağlanmıştır.
    cout << "i of the object a:" << a.get_i() << endl;
    return 0;
    //sqrt_it(&a); fonksiyonunda nesne, işaretçi (pointer) olarak fonksiyona gönderiliyor. Bu, nesnenin bellekteki adresini gönderdiği için, fonksiyon nesne üzerinde değişiklik yapabilir.
    //Fonksiyon sonunda, nesne üzerinde yapılan değişiklikler doğrudan a nesnesini etkiler.
}

//Bir nesnenin bir kopyası bir fonksiyona geçirildiğinde yapıldığında, bu yeni bir nesnenin var olduğu anlamına gelir. 
//Bir nesnenin bir kopyası bir fonksiyon çağrısında kullanılmak üzere yapıldığında, oluşturucu fonksiyon çağrılmaz.
//Ancak, fonksiyon sonlandığında ve kopya yok edildiğinde, yıkıcı fonksiyon çağrılır.
----------------------------------------------------------
i of the object that passed to function by a pointer:100
i of the object a:100
*************************************************************************************************
yapıcı fonksiyon yalnızca nesne oluşturulurken çağrılır 
//Farklılıklar (By Value vs. By Reference):
//By value kullanıldığında, fonksiyon içinde bir kopya nesne oluşturulur ve orijinal nesne etkilenmez. Bu durumda kopya yapıcı çağrılır, ve fonksiyon bittiğinde yıkıcı çağrılır.
//By reference kullanıldığında, orijinal nesne üzerinde işlem yapılır ve kopya yapıcı çağrılmaz. Ayrıca, nesne fonksiyon sonlandığında yıkıcı fonksiyon bir kez çağrılır.

*************************************************************************************************

#include <iostream>
using namespace std;

class samp{
private:
    int i;
    public:
        samp(int n){
            i = n;
            cout << "Constructing Object" << endl;
        }
        ~samp(){
            cout << "Destructing Object" << endl;
        }
        int get_i(){
            return i;
        }
};

int sqrt_it(samp o){
    return (o.get_i()*o.get_i());
}

int main(){
    samp a(10);
    cout << sqrt_it(a) << endl;
    return 0;
}
//Fonksiyon bitiminde, sqrt_it fonksiyonuna gönderilen kopya nesne (o) yok edilir. Bu sırada yıkıcı fonksiyon çağrılır ve ekrana "Destructing Object" yazdırılır.
//Program bittiğinde, main() fonksiyonu sonlandığında orijinal nesne (a) da yok edilir ve yıkıcı fonksiyon bir kez daha çağrılır.
-----------------
Constructing Object
100
Destructing Object
Destructing Object

*************************************************************************************************
//extra
#include <iostream>
using namespace std;

class samp{
private:
    int i;
    public:
        samp(int n){
            i = n;
            cout << "Constructing Object" << endl;
        }
        ~samp(){
            cout << "Destructing Object" << endl;
        }
        int get_i(){
            return i;
        }
};

int sqrt_it(samp *o){
    return (o->get_i()*o->get_i());
}

int main(){
    samp a(10);
    cout << sqrt_it(&a) << endl;
    return 0;
}
-------------------
Constructing Object
100
Destructing Object

*****************************Returning Objects from Functions***************************************

#include <cstring> 
#include <iostream>
using namespace std;
class samp{
    private:
        char s[80];
    public:
        void show(){
            cout << s << endl;
        }
        void set(char *str){
            strcpy(s,str);
        }
};

samp input(){
    char s[80];
    samp str;
    cout << "enter a string:";
    cin >> s;
    str.set(s);
    return str;
}

int main(){
    samp ob_1;
    ob_1=input();//This causes an error.
    ob_1.show();
    return 0;
}

*************************************************************************************************

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class samp{
private:
    char *s;
public:
    samp(){
        if(s){
            free(s);
            cout << "Freeing s" << endl;
        }
    }
    void show(){
        cout << s << endl;
    }
    void set(char *str);
};

void samp::set(char *str){
    s = (char *) malloc(strlen(str)+1);
    if(!s){
        cout << "Allocation error" << endl;
        exit(1);
    }
    strcpy(s,str);
}

samp input(){
    char s[80];
    samp str;
    cout << "Enter a string:";
    cin >> s;
    str.set(s);
    return str;
}

int main(){
    samp ob_1;
    ob_1=input();
    ob_1.show();
    return 0;
}
------------------
Freeing s
Freeing s
Enter a string:hello
hello

**********************************Friend functions*******************************************

//Arkadaş fonksiyonlar, bir sınıfın özel üyelerine dışarıdan erişilmesi gerektiğinde kullanılır.
//Bu kod, bir fonksiyonun bir sınıfın özel üyelerine nasıl erişebileceğini ve bu erişimin nasıl kontrol edildiğini gösteriyor.
//Sınıfın Üyesi Değildir: Ancak, sınıfın tüm üyelerine erişebilir.
//Miras Alınmaz: Arkadaş fonksiyonlar, sınıf türetilse bile miras alınmaz.
//Birden Fazla Sınıfa Dost Olabilir: Tek bir arkadaş fonksiyon, birden fazla sınıfla dost olarak tanımlanabilir.
//friend fonksiyonlar sınıfın dışında tanımlanır.

#include <iostream>
using namespace std;

class myclass{
private:
    int n,d;
public:
    myclass(int i,int j){
        n=i;
        d=j;
    }
    friend isfactor(myclass ob1);
};

int isfactor(myclass ob1){
    if(ob1.n%ob1.d){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    myclass ob_1(10,2),ob_2(10,3);
    if (isfactor(ob_1)){
        cout << "2 is a factor of 10" << endl;
    }else{
        cout << "2 is not a factor of 10" << endl;
    }

    if (isfactor(ob_2)){
        cout << "3 is a factor of 10" << endl;
    }else{
        cout << "3 is not a factor of 10" << endl;
    }

    return 0;
}
--------------------------
2 is not a factor of 10
3 is a factor of 10
*/


