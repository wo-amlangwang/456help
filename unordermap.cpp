#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef std::unordered_map<std::string,int> addressmap;

class mymap {
  addressmap map;
public:
  addressmap getmap();
  void insert(string,int);
  int findByname(string);
};

addressmap mymap :: getmap(){
  return map;
}

void mymap :: insert(string name,int position){
  std::pair<std::string,int> newpair (name,position);
  (this->map).insert(newpair);
}

int mymap :: findByname(string name){
  std::unordered_map<std::string,int>::const_iterator got = map.find (name);
  if(got == map.end()){
    return -1;
  }else{
    return got -> second;
  }
}

int main(int argc, char const *argv[]) {
  mymap map;
  map.insert("arg1",6);
  map.insert("arg2",99);
  map.insert("arg4",88);
  printf("arg1 is %d\n", map.findByname("arg1"));
  return 0;
}
