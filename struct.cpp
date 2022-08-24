#include <string>
#include<iostream>
using namespace std;

class cont{
  public:
    int val;
  
  cont(int inp){
    val = inp;
  };
};

class node {
  private:
    node *next = 0;
    node *prev =0;
    cont *data = 0;

  public:
//constructos
  node (cont *inp){
    data = inp;
    clog <<"node initilised"<<this<<endl;
  };

//setter
    void set_next (node *inp){
      next = inp;
      if(inp->get_prev() != this){
        inp->set_prev(this);
      };
      return;
    };

    void set_prev (node *inp){
      prev = inp;
      if(inp->get_next() != this){
        inp -> set_next(this); 
      };
      return;
    };

    void set_data(cont *inp){
      data = inp;
      return;
    };
//getter cont
     cont* get_data(){
      return data;
    };

    node* get_next(){
      return next;
    };

    node* get_prev(){
      return prev;
    };

};

class list {
  private:
    node *first =0;
    node *current =0;
    node *last =0;

//private functions
void add_one(){
  if(current->get_next()==NULL){
    return;
  }else{
  current = current->get_next();
  return;
  };
};
void sub_one(){
  if(current->get_prev()==NULL){
    return;
  }else{
  current = current->get_prev();
  return;
  };
};
void add (int inp){
  for (int i =0;i<inp;i++){
    add_one();
  };
};
void sub (int inp){
  for(int i =0; i< inp; i++){
    sub_one();
  };
};

  public:
//public function
  void add_node(cont *inp){
    clog<<"starting new node"<<endl;
    node *fresh_node = new node(inp);
    clog<<"hello fresh node"<< fresh_node<<endl;
    fresh_node->set_next(first);
    clog<<"by old start "<<first <<endl;
    first = fresh_node;
    clog<<"hello new start "<<first<<endl;
    clog << "noded added to list\n" <<endl;
    return;
  };

  int length (){
    int out =1;
    node *p = first;
    clog << p << " First "<< first<<endl;
    if(first == 0){
      return 0;
    }else{
      clog<<"next node is"<<p->get_next()<<endl;
      while(p->get_next() != 0){
        clog<<"nex node is"<<p->get_next()<<endl;
        out++;
        p = p->get_next();
        clog<< p ->get_next()<< endl;
      };
      clog << "end of while loop"<< endl;
      return out;
    };
  };

//constructors
    list(cont *inp){
      node *temp =new node (inp);
      first = temp;
      last = first;
      return;
    };
//

//setter

//getter
node* get_next(){
  return current -> get_next();
};
};

int main (){
  cont star(0);
  list tes(&star);
  for(int i = 1;i< 20;i++){
    cont *temp = new cont(i);
    tes.add_node(temp);
    clog << "can you hear me"<< i<<endl;
  };
  clog<<"for loop closed"<< endl;
  cout<<tes.length()<<endl;
};