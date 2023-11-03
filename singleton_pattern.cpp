// suppose we want only a single object of particular create in code (in  multithread als)
// suppose a application running it have only db connection objects throught the application becayse if here are multiple connection then 
//there is more ovehad 

#include<bits/stdc++.h>
using namespace std;




class dbconnect{
    
   static dbconnect * addr;
    dbconnect(){
        cout<<"connection successfull"<<endl;
        
    }
    public:
    static dbconnect* create(){
        if(addr==NULL){
            addr=new dbconnect();
            return addr;
        }
        cout<<"aleady creted"<<endl;
        
        return addr;
    }
};
dbconnect * dbconnect::addr=NULL;











int main(){
    dbconnect * address=NULL;
address=dbconnect::create();
address=dbconnect::create();
address=dbconnect::create();
address=dbconnect::create();
address=dbconnect::create();
address=dbconnect::create();
address=dbconnect::create();

return 0;
}