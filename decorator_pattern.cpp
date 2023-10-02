//decortator pattern is used to avoid class explosion(beacause if we made classes for all different different combination so we have to made enumerate classes )
//we are going to understand the decorator pattern with the example of pizza
// pizza-> vegdeligh, margheeta,zombose
//topping -> panner  cheese mushroom
#include<bits/stdc++.h>
using namespace std;
class topping{
  public:  
 virtual  class base_pizza * add(class base_pizza *b)=0;

};


class base_pizza{
    public:
string pizza_name;    
int cost;
virtual void display_cost()=0;
};
class veg_delight:public base_pizza{
    public:
    veg_delight(){
        this->cost=100;
        this->pizza_name="veg_delight";
    }
    void display_cost(){
        cout<<this->pizza_name<<" "<<this->cost<<endl;return;
    }
};
class margheeta:public base_pizza{
    public:
    margheeta(){
        this->cost=200;
        this->pizza_name="margheeta";
    }
    void display_cost(){
        cout<<this->pizza_name<<" "<<this->cost<<endl;return;
    }
};
class zombose:public base_pizza{
    public:
    zombose(){
        this->cost=300;
        this->pizza_name="zombose";
    }
    void display_cost(){
        cout<<this->pizza_name<<" "<<this->cost<<endl;
        return;
    }
};

class extraCheese:public topping{
  public:
   base_pizza * add( base_pizza * b){
    b-> cost=b->cost+10;
    b->pizza_name=b->pizza_name+"+ "+"extraCheese";
    return b;
  }
};
class extraPanner:public topping{
  public:
   base_pizza * add( base_pizza * b){
    b-> cost=b->cost+20;
    b->pizza_name=b->pizza_name+"+ "+"extraPaneer";
    return b;
  }
};
class extraMushroom:public topping{
  public:
   base_pizza * add( base_pizza * b){
    b-> cost=b->cost+30;
    b->pizza_name=b->pizza_name+"+ "+"extraMushroom";
    return b;
  }
};

int main(){
base_pizza* v1=new veg_delight();
base_pizza* m1=new margheeta();
base_pizza  * z1=new zombose();

extraCheese ec;
extraPanner ep;
extraMushroom em;
base_pizza *b1;
b1=ec.add(em.add(ep.add(ec.add(m1))));
b1->display_cost();
b1=ec.add(em.add(ep.add(ec.add(v1))));
b1->display_cost();
b1=ec.add(em.add(ep.add(ec.add(z1))));
b1->display_cost();

return 0;
}


