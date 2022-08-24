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
      if(inp != 0 && inp->get_prev() != this){
        inp->set_prev(this);
      };
      return;
    };

    void set_prev (node *inp){
      prev = inp;
      if(inp != 0 &&inp->get_next() != this){
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
    node *fresh_node = new node(inp);
    fresh_node->set_prev(last);
    last = fresh_node;
    return;
  };
  //retun node on nth position, doesnt check for out of bounds instead returns 0
  node* get_node(int inp){
    clog<<"Getting node :";
    node *p;
    p=first;
    //check for first node to not mess up for loop
    if(inp=0){
      clog << p << endl;
      return p;
    };
    //get the node on "inp" position 0 is first node
    for (int i=0;i<inp;i++){
      if(p != 0){
        p = p->get_next();
      };
    };
    clog<<p << "\n" <<endl;
    clog << p << endl;
    return p;
  };
  int length (){
    int out =1;
    node *p = first;
    if(first == 0){
      return 0;
    }else{
      while(p->get_next() != 0){
        out++;
        p = p->get_next();
      };
      return out;
    };
  };
  // deletes given node, doesnt check if node is part of own list
  void delete_node (node *inp){
    clog<<"deleting node: "<< inp<<endl;
    node *temp_prev, *temp_next;
    temp_next = inp->get_next();
    temp_prev = inp->get_prev();
    clog << "temps all set next: "<<temp_next<<" prev: "<< temp_prev<<endl;
    //check if last node
    if(temp_next != 0){
      if(inp=first){
        first = temp_next;
      };
      if(inp=last){
        last=temp_prev;
      };
      clog<< "setting prev "<<endl;
     //only needs to conect one end to the other f.e. previous to next. Node is setup that atomaticly links both nodes ends together
      temp_next->set_prev(temp_prev);
    //check if first node
    }else if(temp_prev != 0){
      temp_prev->set_next(temp_next);
      if(inp=first){
        first = temp_next;
      };
      if(inp=last){
        last=temp_prev;
      };
    //when empty
    }else{
      first = 0;
      last = 0;
    };
    clog<<"node deleted\n"<<endl;
    return;
  };
//constructors
    list(cont *inp){
      node *temp =new node (inp);
      first = temp;
      last = first;
      return;
    };
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
  };
  tes.delete_node(tes.get_node(19));
  tes.delete_node(tes.get_node(0));
  cout<<tes.length()<<endl;
};