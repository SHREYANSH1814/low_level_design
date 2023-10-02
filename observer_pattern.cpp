// Basically in this we have to develop a design in which observer observe any product on any changein product observer get notified
// real lif in e commerce when we added a product in a cart when it is available the user get notified
#include<bits/stdc++.h>
using namespace std;

class observer{   // interface class for observer
    public:
    virtual void getNotified(class observable * obj)=0;
};
class observable{  
    public:
    int id;// interface calss of observable
  vector<observer *>observer_list;
  virtual  void add_observer(observer * o1)=0;
  virtual void notify_observer()=0;
  virtual void change()=0;
};



class observer1:public observer{
    public:
    void getNotified(observable * obj){
        cout<<obj->id<<endl;
    }

};
class observable1:public observable
 {
    public:
    observable1(int id){
        this->id=id;
    }
    void add_observer(observer * o1){
        observer_list.push_back(o1);
         return;
    }
    void notify_observer(){
        for(auto i:observer_list){
            i->getNotified(this);
        }
        return;
    }
     void change(){
        cout<<"hello";
        notify_observer();
     }   

    
};
int main(){
    observer1 c1,c2,c3;
    observable1 p1(1),p2(2),p3(3);
    p1.add_observer(&c1);
    p1.add_observer(&c2);
    p2.add_observer(&c3);
    p2.add_observer(&c1);
    p3.add_observer(&c2);
    p3.add_observer(&c3);
    p1.notify_observer();
    p2.notify_observer();
    p3.notify_observer();


}

