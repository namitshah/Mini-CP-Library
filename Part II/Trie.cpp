#include<bits/stdc++.h>
using namespace std;
//Implementation of a Trie, here for String Search
//and Insertion. EoK (End of Key) is 0 {init. 0 is not related}.
struct TrieNode
{
  char character = 0;
  vector<TrieNode> links;
};

bool trieFind(TrieNode croot, string &key, int index)
{
  if(index > key.length()) return true;
  char required = (index < key.length()?key[index]:0);
  for(auto next : croot.links)
  {
    if(next.character == required)
    {return trieFind(next, key, index + 1);}
  }
  return false;
}

void triePop(TrieNode &croot, string &key, int index)
{
  if(index > key.length()) return;
  char required = (index < key.length()?key[index]:0);
  for(int i = 0; i < croot.links.size(); i++)
  {
    auto &next = croot.links[i];
    if(next.character == required)
    {triePop(next, key, index + 1); return;}
  }
  TrieNode next;
  next.character = required;
  croot.links.push_back(next);
  triePop(croot.links[croot.links.size() - 1], key, index + 1);
}

int main()
{
  TrieNode root;
  int n; cin >> n;
  for(int i = 0; i < n; i++)
  {
    string s; cin >> s;
    triePop(root, s, 0);
  }
  int k; cin >> k;
  for(int i = 0; i < k; i++)
  {
    string s; cin >> s;
    cout << (trieFind(root, s, 0)?"YES":"NO") << endl;
  }
  return 0;
}
