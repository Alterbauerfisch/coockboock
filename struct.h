#include <string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class cont;
class node;
class list;
class baseIngredient;
class ingredient;
class recipi;
class book;

class cont{
  private:
    string mode =NULL;
    ingredient *ingr =0;
    recipi *reci =0;
  public:
    cont(ingredient *inp); 
    cont(recipi *inp);
    string get_mode();
    ingredient* get_ingredient();
    recipi* get_recipi(); 
};

class node {
  private:
    node *next = 0;
    node *prev =0;
    cont *data = 0;

  public:
//constructos
  node (cont *inp);

//setter
    void set_next (node *inp);

    void set_prev (node *inp);

    void set_data(cont *inp);
//getter cont
     cont* get_data();

    node* get_next();

    node* get_prev();
};

class list {
  private:
    node *first =0;
    node *current =0;
    node *last =0;
//private functions
  void add_one();
  void sub_one();
  void add (int inp);
  
  void sub (int inp);

  public:
//public function
  void add_node(cont *inp);
  //retun node on nth position, doesnt check for out of bounds instead returns 0
  cont* get_node(int inp);
  int length ();
  // deletes given node, doesnt check if node is part of own list
  void delete_node (node *inp);
//constructors
    list(cont *inp);
//setter

//getter
node* get_next();
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
      baseIngredient(string in_name,string unit, double ammount, double kcal, double protein, double fat,double carbs);
      
      string get_name();
      string get_base_unit();
      double get_base_ammount;
      double get_base_kcal();
      double get_base_protein();
      double get_get_base_fat();
      double get_base_carbs();
};

class ingredient{
  private: 
    baseIngredient *base = 0;
    double multiplyer = 0;
  public:
    ingredient(baseIngredient *in_base,double in_ammount);
    ingredient(string in_name,string unit, double ammount, double kcal, double protein, double fat,double carbs,double in_multi);
    void set_multiplyer(double inp);
    double get_multiplyer();
    baseIngredient* get_base();
    string get_name();
    string get_base_unit();
    double get_base_ammount();
    double get_base_kcal();
    double get_base_protein();
    double get_get_base_fat();
    double get_base_carbs();
};

class recipi{
  private:
    string name=NULL;
    list *ingredients= 0;
    vector <string> tags {};
    string assembly;
  public:
//constructor 
  recipi(string in_name);
//public functions
  //only adds if not already there
  void add_tag(string inp);

  void add_ingriedient(ingredient *inp);

//getter and setter
  void set_assembly(string inp);
  list* get_ingriedients();
  vector<string> get_tags();
  string get_assembly();
};

class book{
  private:
    list *pages=0;
    int page=0;
  public:
  book ();
  void add_recipi(recipi *inp);
  recipi* get_current_page();
  void next_page(int inp=1);
 
  void prev_page(int inp = 1);
  
  void goto_page(int inp);

};
