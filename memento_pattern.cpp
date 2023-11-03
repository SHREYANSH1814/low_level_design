#include<bits/stdc++.h>
using namespace std;
#define ll long long
class memento{
   public:
   int state;
   memento * next;
   memento * prev;
   memento(int state){
    this->state=state;
   }

};
class caretaker{
    memento * curr;
public:
void save(memento * temp){
    if(curr==NULL){
        curr=temp;
        return;
    }

    curr->next=temp;
    temp->prev=curr;
    curr=temp;

}
memento * getmemento(int ind){
    if(ind==1){
        //redo
        return curr->next;

    }
    if(ind==-1){
        //undo
        return curr->prev;
    }

    return NULL;
}

void update(memento * t){
    curr=t;
    return;
}
};

class originator{
    int state;
    caretaker * care;
    public:
    originator(){
        this->care=new caretaker();
        set(0);

    }
    void set(int st){
        memento * temp =new  memento(st);
        this->state=st;
        care->save(temp);
        return;
    }
    void setmemento(memento *t){
        if(t!=NULL){
            care->update(t);
            this->state=t->state;
        }
        return;

        
    }
    void undo(){
       memento *prev= care->getmemento(-1);
       setmemento(prev);
       return;
       

       
    }
    void redo(){
        memento * next=care->getmemento(1);
        setmemento(next);
        return;



    }
    void get(){
        cout<<this->state<<endl;
    }

};
int main(){

    originator org;
    org.get();
    org.set(1);
    org.set(2);
    org.set(3);
    org.undo();
    org.undo();
    org.get();
    org.redo();
    org.set(4);
    org.set(5);
    org.undo();
    org.undo();
    org.redo();
    org.redo();
    org.get();

return 0;
}