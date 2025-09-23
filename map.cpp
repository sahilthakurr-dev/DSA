#include<iostream>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<string, int> mp;
    //insertion
    pair<string,int> p = make_pair("sahil", 3);
    mp.insert(p);
    pair<string, int> pair2("thakur", 2);
    mp.insert(pair2);

    cout<<mp["sahil"]<<endl;
    cout<<mp.at("thakur")<<endl;
    cout<<mp.size()<<endl;

   cout<<mp.count("sahil")<<endl;
   mp.erase("sahil");
   cout<<mp.size()<<endl;

   for(auto pair : mp){
    cout<<pair.first<<" "<<pair.second<<endl;
   }

   unordered_map<string, int> :: iterator it = mp.begin();
   while( it != mp.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
   }

}