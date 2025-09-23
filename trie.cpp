#include <iostream>
#include <string>
using namespace std;
class trieNode
{
public:
   char data;
   trieNode *children[26];
   bool isTerminal;

   trieNode(char ch)
   {
      this->data = ch;
      for (int i = 0; i < 26; i++)
      {
         children[i] = NULL;
      };
      isTerminal = false;
   }
};

class trie{
public:
trieNode *root;
 trie(){
   root = new trieNode('\0');
 };
   void insertUtil(trieNode *root, string word)
   {
      // base case
      if (word.length() == 0)
      {
         root->isTerminal = true;
         return;
      };

      int index = word[0] - 'A';
      trieNode *child;

      if (root->children[index] != NULL)
      {
         child = root->children[index];
      }
      else
      {
         child = new trieNode(word[0]);
         root->children[index] = child;
      };

      insertUtil(child, word.substr(1));
   };

   void insertWord(string word)
   {

      insertUtil(root, word);
   };
   
   bool searchUtil( trieNode* root, string word){
      //base case 
      if(word.length() == 0){
         return root->isTerminal;
      };

      int index = word[0] - 'A';
      trieNode* child;

      if(root->children[index] != NULL){
         child = root->children[index];
      } else{
         return false;
      };

      return searchUtil(child, word.substr(1));

   }
   bool search(string word){
     return searchUtil(root,word);
   }
  
   void removeWordUtil(trieNode* root, string word){
      //base case
      if(word.length() == 0){
         root->isTerminal = false;
         return;
      };

      int index = word[0]-'A';
      trieNode* child;
      if(root->children[index] != NULL){
         child = root->children[index];
      } else{
         return;
      };
      removeWordUtil(child, word.substr(1));
   }
   void removeWord(string word){
      removeWordUtil(root,word);
   }
};

int main()
{

   trie* t = new trie();

   t->insertWord("ABCD");

  if(t->search("ABCD")){
   cout<<"Is Present"<<endl;
  } else{
   cout<<"Is Absent"<<endl;
  }

  t->removeWord("ABCD");
   if(t->search("ABCD")){
   cout<<"Is Present"<<endl;
  } else{
   cout<<"Is Absent"<<endl;
  }

   return 0;
}
