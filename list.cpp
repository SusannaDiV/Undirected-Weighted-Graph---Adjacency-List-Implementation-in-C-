//Gruppo 23: Susanna Di Vita, Filippo Alberti, Enea Dervishi  
#include "list.h"

using namespace list;


void list::clear(List& l){
    l.size = 0;
    l.maxsize = BLOCKDIM;
    Elem* aux = new Elem[BLOCKDIM];
    delete[] l.list;

    l.list = aux;
}


/****************************************************************/
void list::set(int pos, Elem e, List& l) // "set" nel senso di "assegna un valore", non nel senso di "insieme"! E' una terminologia standard, non fate confusione con gli insiemi
{
   if (pos < 0 || pos > (l.size)-1) return;
   l.list[pos] = e;
}


/****************************************************************/
void list::add(int pos, Elem e, List& l) // aggiunge e nella posizione pos
{
   if (pos < 0 || pos > l.size) return;

   if (l.size == l.maxsize) 
      {
      List auxList;
      auxList.size = l.size+1;
      auxList.maxsize = l.maxsize + BLOCKDIM;
      Elem* auxArray = new Elem[auxList.maxsize];
      auxList.list = auxArray;
      for (int i=0; i<pos; ++i)
          auxList.list[i] = l.list[i];
      auxList.list[pos] = e;
      for (int i=pos+1; i<auxList.size; ++i)
          auxList.list[i] = l.list[i-1];
      delete[] l.list;
      l = auxList;
      return;
      }
	l.size++;
     for (int i=l.size-1; i>pos; --i)
           l.list[i] = l.list[i-1];
     l.list[pos] = e;
}



/****************************************************************/
void list::addBack(Elem e, List& l) 
{
   add(l.size, e, l);
}


/****************************************************************/
void list::addFront(Elem e, List& l) 
{
   return add(0, e, l);
}

/****************************************************************/
void list::removePos(int pos, List& l)
{
   if (pos < 0 || pos >= l.size)
      return;
   if (l.maxsize-l.size+1==BLOCKDIM && l.maxsize>BLOCKDIM)
   {
      List auxList;
      auxList.size = l.size-1;
      auxList.maxsize = l.maxsize-BLOCKDIM;
      Elem* auxArray = new Elem[auxList.maxsize];
      auxList.list = auxArray;
      for (int i=0; i<pos; ++i)
          auxList.list[i] = l.list[i];
      for (int i=pos; i<auxList.size; ++i)
          auxList.list[i] = l.list[i+1];
      delete[] l.list;
      l = auxList;
      return;
   }
     for (int i=pos+1; i<l.size; ++i)
           l.list[i-1]=l.list[i];
     l.size--;
}


/****************************************************************/

List list::createEmpty(){
    List l;
    l.size = 0;
    l.maxsize = BLOCKDIM;
    Elem* aux = new Elem[BLOCKDIM];
    l.list = aux;
    return l;
}

/****************************************************************/
Elem list::get(int pos, const List& l)
{
   if (pos < 0 || pos >= l.size)
      return emptyElem;
   return l.list[pos];
}


/****************************************************************/
bool list::isEmpty(const List& l)
{
   return (l.size == 0);
}

/****************************************************************/
int list::size(const List& l)
{
   return l.size;
}


/****************************************************************/
void printList(const List& l)
{
cout << endl;
for (int i=0; i<l.size; ++i)
   cout << l.list[i] << "; ";
cout << endl;
}




