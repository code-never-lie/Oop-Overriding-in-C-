Inheritance
  1- Extension
  2- Improvement
Overriding 
Method overriding, in object oriented programming, is a language feature that allows a subclass or child class to provide a specific implementation of a method that is already provided by one of its superclasses or parent classes. 

The implementation in the subclass overrides (replaces) the implementation in the superclass by providing a method that has same name, same parameters or signature, and same return type as the method in the parent class.

Major Object ( Why Overriding)

- we want to improve the logic of parent class 
............................................................
class Calculator {
public :
void add() { cout<<" old add  logic"<<endl;}
void sub() { cout<<"old sub logic"<<endl;}
void memory () { cout <<" memory function"<<endl;}

};
class ImprovedCalculator:public Calculator{

public :
void add() { cout<<" new add  logic"<<endl;}
void sub() { cout<<"new sub logic"<<endl;}

};

void main() {
ImprovedCalculator ob;
ob.add();//new improved add
ob.sub();//new improved sub
ob.Calculator::add();// it will call parent class add
ob.memory();

}
..........................................................
Example List Class
Assumtion Data is already Sorted

class List{
private :
 int size;
 int *a;
public :
   List (int s ){size=s; a= new int [size];}
  void  setElement(int d,int index) {
       a[index]=d;      
  }

  int getElement (int index){ return a[index];}
  bool search(int key){
    int i=0;
    while ((i<size)&&(a[i]!=key))
             i=i+1;
    if (i<size)
        return true;

    else
         return false;

  }

};

void main () {
List list(5);
int j;
for (int i=0;i<5;i++){
  cout<<" enter element no "<<i<<" ";
  cin>>j;
  list.setElement(j,i);
} 
cout<<"\n Enter Element to Search "; cin>>j;
if (list.search(j))
  cout<<" Found ";
else
  cout<<" Not Found ";
  

}
..................................................

We want to improve List class with new Search Logic i.e Binary Search

class List{
private :
 int size;
 int *a;
public :
   List (int s ){size=s; a= new int [size];}
  void  setElement(int d,int index) {
       a[index]=d;      
  }
  int getSize(){ return size;}
  int getElement (int index){ return a[index];}
  bool search(int key){
    int i=0;
    while ((i<size)&&(a[i]!=key))
             i=i+1;
    if (i<size)
        return true;

    else
         return false;

  }
};
class ImprovedList:public List {
public :
ImprovedList(int s):List(s)  {}
bool search(int key){
    int low=0,high=getSize()-1;
    int mid=(low+high)/2;
    while ((low<high)&&(getElement(mid)!=key)){
          if (key>getElement(mid))
              low=mid+1;
           else
                high=mid-1;
           mid=(low+high)/2;
     }
   if (low<high)
       return true;
   else
        return false;
}
};
void main () {
ImprovedList list(5);
int j;
for (int i=0;i<5;i++){
  cout<<" enter element no "<<i<<" ";
  cin>>j;
  list.setElement(j,i);
} 
cout<<"\n Enter Element to Search "; cin>>j;
if (list.search(j))
  cout<<" Found ";
else
  cout<<" Not Found \n";
//....Print List ......................
for (i=0;i<list.getSize();i++)
  cout<<list.getElement(i)<<endl;
}
.........................................................








