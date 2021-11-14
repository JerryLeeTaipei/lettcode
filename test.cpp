// constructing maps
#include <iostream>
#include <map>

using namespace std;

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  // declare container and iterator
  map<char,int> map1;
  map<char,int>::iterator iter;
  map<char,int>::reverse_iterator iter_r;
  // insert element
  map1.insert(pair<char,int>('a', 10));
  map1['b']=30;
  map1['c']=50;
  map1['d']=70;

  //traversal
  for(iter = map1.begin(); iter != map1.end(); iter++)
                cout << iter->first << ":" << iter->second << " ";
  cout << endl;
  for(iter_r = map1.rbegin(); iter_r != map1.rend(); iter_r++)
                cout << iter_r->first << ":" << iter_r->second << " ";
  cout << endl;
  //find and erase the element
  iter = map1.find('b');
  if ( iter != map1.end() ){
       cout << "Find, the value is "<< iter->second << ". Delete it." << endl;
       // erase the element
       map1.erase(iter);
  } else
       cout << "Do not Find" << endl;

  map<char,int> map2 (map1.begin(),map1.end());
  for(iter = map1.begin(); iter != map1.end(); iter++)
                cout << iter->first << ":" << iter->second << " ";
  cout << endl;

  map<char,int> map3 (map2);
  map<char,int,classcomp> map4; // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  return 0;
}
