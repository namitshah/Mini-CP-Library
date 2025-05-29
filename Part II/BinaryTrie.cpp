struct TrieNode
{
  bool bit = 0;
  vector<TrieNode> links;
};

void trieFind(TrieNode croot, int &key, int mask, int &output)
{
  if(!mask) return;
  bool required = (mask & key) / mask;
  for(auto next : croot.links)
  {
    if(next.bit == required)
    {trieFind(next, key, mask / 2, output); output += required * mask; return;}
  }
  required = !required;
  for(auto next : croot.links)
  {
    if(next.bit == required)
    {trieFind(next, key, mask / 2, output); output += required * mask; return;}
  }
  return;
}

void triePop(TrieNode &croot, int &key, int mask)
{
  if(!mask) return;
  bool required = (key & mask) / mask;
  if(croot.links.size() && croot.links[0].bit == required)
  {triePop(croot.links[0], key, mask / 2); return;}
  if(croot.links.size() > 1 && croot.links[1].bit == required)
  {triePop(croot.links[1], key, mask / 2); return;}

  TrieNode next;
  next.bit = required;
  croot.links.push_back(next);
  triePop(croot.links[croot.links.size() - 1], key, mask / 2);
}
//Mask should initially be the max element's MSB.
