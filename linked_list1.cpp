#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
class student {
	private:
	    string name;
		student *n;
	    student *p;
    public:
    	friend class list;
};
int count = 0;
class list {
	private:
		student *first, *final;
    public:
      student *create_node(string);
      void insert_begin();
      void insert_end();
      void insert_pos();
      void delete_pos();
      void search();
      void update();
      void display();
      void reverse();
      list() {
         first = NULL;
         final = NULL;
      }
};
int main() {
   int c;
   list ls;
   while (1) 
   {
      cout<<"1.Insert student"<<endl;
      cout<<"2.Delete at student"<<endl;
      cout<<"3.Update student"<<endl;
      cout<<"4.Search Element"<<endl;
      cout<<"5.Display List"<<endl;
      cout<<"6.Reverse List"<<endl;
      cout<<"7.Exit"<<endl;
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c) {
        case 1:
            cout<<"choose position:\n 1.begin\n 2.end \n 3.position";
            int z;
            cout<<"\nEnter your choice : ";
            cin>>z;
			switch(z){
				case 1:
					ls.insert_begin();
         		break;
         		case 2:
				 	ls.insert_end();
				break;
				case 3:
					ls.insert_pos();
				break;	 	
			}
		break;	
        case 2:
            ls.delete_pos();
        break;
        case 3:
            ls.update();
        break;
        case 4:
            ls.search();
        break;
        case 5:
            ls.display();
        break;
        case 6:
            ls.reverse();
        break;
        case 7:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
      }
   }
   return 0;
}
student* list::create_node(string v) {
   count++;
   student *t;
   t = new student;
   t->name = v;
   t->n = NULL;
   t->p = NULL;
   return t;
}
void list::insert_begin() {
   string v;
   cout<<endl<<"Enter the name to be inserted: ";
   cin>>v;
   student *t;
   t = create_node(v);
   if (first == final && first == NULL) {
      cout<<"name inserted in empty list"<<endl;
      first = final = t;
      first->n = final->n = NULL;
      first->p = final->p = NULL;
   } else {
      t->n = first;
      first->p = t;
      first = t;
      first->p = final;
      final->n = first;
      cout<<"name inserted"<<endl;
   }
}
void list::insert_end() {
   string v;
   cout<<endl<<"Enter the name to be inserted: ";
   cin>>v;
   student *t;
   t = create_node(v);
   if (first == final && first == NULL) {
      cout<<"name inserted in empty list"<<endl;
      first = final = t;
      first->n= final->n = NULL;
      first->p = final->p= NULL;
   } else {
      final->n= t;
      t->p= final;
      final = t;
      first->p = final;
      final->n= first;
   }
}
void list::insert_pos() {
   int pos, i;
   string v;
   cout<<endl<<"Enter the name to be inserted: ";
   cin>>v;
   cout<<endl<<"Enter the position of name inserted: ";
   cin>>pos;
   student *t, *s, *ptr;
   t = create_node(v);
   if (first == final && first == NULL) {
      if (pos == 1) {
         first = final = t;
         first->n = final->n = NULL;
         first->p = final->p = NULL;
      } else {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
   } else {
      if (count < pos) {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
      s = first;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->n;
         if (i == pos - 1) {
            ptr->n = t;
            t->p= ptr;
            t->n= s;
            s->p = t;
            cout<<"name inserted"<<endl;
            break;
         }
      }
   }
}
void list::delete_pos() {
   int pos, i;
   student *ptr, *s;
   if (first == final && first == NULL) {
      cout<<"List is empty, nothing to delete"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of name to be deleted: ";
   cin>>pos;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = first;
   if(pos == 1) {
      count--;
      final->n = s->n;
      s->n->p = final;
      first = s->n;
      free(s);
      cout<<"name Deleted"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->n;
      ptr = s->p;
   }
   ptr->n = s->n;
   s->n->p = ptr;
   if (pos == count) {
      final = ptr;
   }
   count--;
   free(s);
   cout<<"name Deleted"<<endl;
}
void list::update() {
   string v; 
   int i, pos;
   if (first == final && first == NULL) {
      cout<<"The List is empty, nothing to update"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of nodee to be updated: ";
   cin>>pos;
   cout<<"Enter the new value: ";
   cin>>v;
   student *s;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = first;
   if (pos == 1) {
      s->name = v;
      cout<<"student Updated"<<endl;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->n;
   }
   s->name = v;
   cout<<"



