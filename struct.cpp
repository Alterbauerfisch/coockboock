#include <string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ingredient;
class recipi;
class cont{
  private:
    string mode =NULL;
    ingredient *ingr =0;
    recipi *reci =0;
  public:
    cont(ingredient *inp){
      ingr=inp;
      mode="ingredient";
    }; 
    cont(recipi *inp){
      reci = inp;
      mode="recipi";   
    };
    string get_mode(){
      return mode;
    };
    ingredient* get_ingredient(){
      return ingr;
    };
    recipi* get_recipi(){
      return reci;
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
  cont* get_node(int inp){
    clog<<"Getting node :";
    node *p;
    p=first;
    //check for first node to not mess up for loop
    if(inp=0){
      clog << p << endl;
      return p->get_data();
    };
    //get the node on "inp" position 0 is first node
    for (int i=0;i<inp;i++){
      if(p != 0){
        p = p->get_next();
      };
    };
    clog<<p << "\n" <<endl;
    clog << p << endl;
    return p->get_data();
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
    list(){

    };
//setter

//getter
node* get_next(){
  return current -> get_next();
};
};

class baseIngredient{
    private:
      string name= NULL;
      string base_unit ="g";
      double base_ammount=0;

      double base_kcal =0;
      double base_protein=0;
      double base_fat =0;
      double base_carbs=0;
    public:
      baseIngredient(string in_name,string unit, double ammount, double kcal, double protein, double fat,double carbs){
        name= in_name;
        base_unit =unit;
        base_ammount=ammount;

        base_kcal =kcal;
        base_protein=protein;
        base_fat =fat;
        base_carbs=carbs;
      };
      
      string get_name(){
        return name;
      };
      string get_base_unit(){
        return base_unit;
      };
      double get_base_ammount(){
        return base_ammount;
      };
      double get_base_kcal(){
        return base_kcal;
      };
      double get_base_protein(){
        return base_protein;
      };
      double get_get_base_fat(){
        return base_fat;
      };
      double get_base_carbs(){
        return base_carbs;
      };
};

class ingredient{
  private: 
    baseIngredient *base = 0;
    double multiplyer = 0;
  public:
    ingredient(baseIngredient *in_base,double in_ammount){
      baseIngredient *base = in_base;
    double multiplyer = in_ammount;
    };
    ingredient(string in_name,string unit, double ammount, double kcal, double protein, double fat,double carbs,double in_multi){
      base = new baseIngredient(in_name,unit,ammount,kcal,protein,fat,carbs);
      multiplyer= in_multi;
    };
    void set_multiplyer(double inp){
      multiplyer = inp;
    };
    double get_multiplyer(){
      return multiplyer;
    };
    baseIngredient* get_base(){
      return base;
    };
    string get_name(){
      return base->get_name();
    };
    string get_base_unit(){
      return base->get_base_unit();
    };
    double get_base_ammount(){
      return base->get_base_ammount();
    };
    double get_base_kcal(){
      return base->get_base_kcal();
    };
    double get_base_protein(){
      return base->get_base_protein();
    };
    double get_get_base_fat(){
      return base->get_get_base_fat();
    };
    double get_base_carbs(){
      return base->get_base_carbs();
    };
};

class recipi{
  private:
    string name=NULL;
    list *ingredients= 0;
    vector <string> tags {};
    string assembly;
  public:
//constructor 
  recipi(string in_name){
    name=in_name;
  };
//public functions
  //only adds if not already there
  void add_tag(string inp){
    if(count(tags.begin(),tags.end(),inp)!=0){
      tags.push_back(inp);
    };
  };
  void add_ingriedient(ingredient *inp){
    ingredients->add_node(new cont(inp));
  };

//getter and setter
  void set_assembly(string inp){
    assembly = inp;
  };
  list* get_ingriedients(){
    return ingredients;
  };
  vector<string> get_tags(){
    return tags;
  };
  string get_assembly(){
    return assembly;
  };
};

class book{
  private:
    list *pages=0;
    int page=0;
  public:
  book (){
    pages = new list();
  };
  void add_recipi(recipi *inp){
    cont *temp = new cont(inp);
    pages ->add_node(temp);
  };
  recipi* get_current_page(){
    return pages->get_node(page)->get_recipi();
  };
  void next_page(int inp=1){
    if(page + inp < pages->length()&& page + inp >0){
      page += inp;
    };
  };
  void prev_page(int inp = 1){
    if(page - inp < pages->length()&& page - inp >0){
      page -= inp;
    };
  };
  void goto_page(int inp){
    if(inp <= pages->length()&&inp >=0 ){
      page = inp;
    };
  };

};

int main (){

};