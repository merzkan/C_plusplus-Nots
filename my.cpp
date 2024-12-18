
/*
**************************C++ Classes/Objects**************************************************
#include <iostream>
using namespace std;

class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}
--------------
15
Some text

************************C++ Classes/Objects********************************************

#include <iostream>
using namespace std;

class car{
  public:
    string brand;
    string model;
    int year;
};
int main() {
  car carobj1;
  carobj1.brand="BMW";
  carobj1.model="X5";
  carobj1.year=199;

  car carobj2;
  carobj2.brand="ford";
  carobj2.model="mustang";
  carobj2.year=1969;


  cout << carobj1.brand << " " << carobj1.model << " " << carobj1.year << "\n";
  cout << carobj2.brand << " " << carobj2.model << " " << carobj2.year << "\n";

  return 0;
}
----------------
BMW X5 199
ford mustang 1969

******************************C++ Class Methods*************************************************

#include <iostream>
using namespace std;
class MyClass {        // The class
  public:              // Access specifier
    void myMethod() {  // Method/function defined inside the class
      cout << "Hello World!";
    }
};

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
-----------------
Hello World!

***************************C++ Class Methods*************************************************

#include <iostream>
using namespace std;

class MyClass {         // The class
  public:               // Access specifier
    void myMethod();    // Method/function declaration
};

// Method/function definition outside the class
void MyClass::myMethod() {
  cout << "Hello World!";
}

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
-----------
Hello World!

***********************C++ Class Methods***********************************************

#include <iostream>
using namespace std;

class Car{
public:
  int speed(int maxSpeed);
};
 
int Car::speed(int maxSpeed){
  return maxSpeed;
}
int main(){
  Car myobj;
  cout << myobj.speed(200);
  return 0 ;
}
---------------
200

***************************C++ Constructors**************************************************

#include <iostream>
using namespace std;

class MyClass {     // The class
  public:           // Access specifier
    MyClass() {     // Constructor
      cout << "Hello World!";
    }
};

int main() {
  MyClass myObj;    // Create an object of MyClass (this will call the constructor)
  return 0;
}
----------
Hello World!

***************************C++ Constructors**************************************************

#include <iostream>
using namespace std;

class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z) {  // Constructor with parameters
      brand = x;
      model = y;
      year = z;
    }
};

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}
-------------------
BMW X5 1999
Ford Mustang 1969

***************************C++ Constructors**************************************************

#include <iostream>
using namespace std;

class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z); // Constructor declaration
};

// Constructor definition outside the class
Car::Car(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}
-----------------
BMW X5 1999
Ford Mustang 1969

**************************C++ Access Specifiers**********************************************
class MyClass {  // The class
  public:        // Access specifier
    // class members goes here
};
--------------------------------------
class MyClass {
  public:    // Public access specifier
    int x;   // Public attribute
  private:   // Private access specifier
    int y;   // Private attribute
};

int main() {
  MyClass myObj;
  myObj.x = 25;  // Allowed (public)
  myObj.y = 50;  // Not allowed (private)
  return 0;
}
error: y is private
-----------------------------------------
class MyClass {
  int x;   // Private attribute
  int y;   // Private attribute
};
----------------------------------------
*****************************C++ Encapsulation****************************************************
#include <iostream>
using namespace std;

class Employee {
  private:
    int salary;

  public:
    void setSalary(int s) {
      salary = s;
    }
    int getSalary() {
      return salary;
    }
};

int main() {
  Employee myObj;
  myObj.setSalary(50000);
  cout << myObj.getSalary();
  return 0;
}
---------------------
50000
***************************C++ Inheritance********************************************************
*/  