#include<bits/stdc++.h>
using namespace std;
#define ll long long
class obj{
    public:
    string type;
    string value;
    obj(string type,string value){
        this->type=type;
        this->value=value;
    }
};
class old_inventory{

 public :
 obj * get_data(int key){
      obj* obj1=new obj("XML data","value");
      return obj1;
 }
};
class adapter{
     old_inventory * old;
    public:
    adapter(old_inventory * olde){
      this->old=olde;
    }
    void transform(obj * temp){
        temp->type="JSON data";
    }
    obj * get_data(int key){
        obj * temp=old->get_data(key);
        transform(temp);
        return temp;
    }
};
class new_inventory{
    adapter * adapt;
    old_inventory * old;

  public:

   new_inventory(old_inventory * olde){
    this->old=olde;
    this->adapt=new adapter(olde);
   }
   obj * get_data(int key){
    return adapt->get_data(key);

   }
};

int main(){
    old_inventory * old=new old_inventory();
    new_inventory * new1=new new_inventory(old);
    obj * obj1=old->get_data(1);
    cout<<obj1->type<<" "<<obj1->value<<endl;
    obj * obj2=new1->get_data(1);
   cout<<obj2->type<<" "<<obj2->value<<endl;



return 0;
}