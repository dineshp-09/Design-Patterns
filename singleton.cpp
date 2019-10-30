/*
Singleton design pattern
*/

#include<iostream>

using namespace std;

class Singleton {
  static Singleton *ptr;
  Singleton() {
    cout<<"Object is created..."<<endl;
  }
  public:
    static Singleton *createInstance() {
      if(ptr == NULL){
        ptr = new Singleton();
      } else {
        cout <<"Error: only one object is created"<<endl;
      }
      return ptr;
    }
};

Singleton* Singleton::ptr = NULL;

int main(){
  Singleton *ptr = Singleton::createInstance();
  Singleton *ptr1 = Singleton::createInstance();
  return 0;
}

/*Output
Object is created...
Error: only one object is created
*/
