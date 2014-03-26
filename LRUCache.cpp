#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v): key(k), value(v){}
};

class LRUCache {
	public:
		LRUCache(int capacity) {
			size = capacity;
		}
		int get(int key) {
			if (cacheMap.find(key) == cacheMap.end())
			{
				return -1;
			} else {
				cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
				cacheMap[key] = cacheList.begin();
				return cacheMap[key]->value;
			}
		}
		void set(int key, int value) {
			if (cacheMap.find(key) == cacheMap.end())
			{
				if (cacheList.size() == size)
				{
					cacheMap.erase(cacheList.back().key);
					cacheList.pop_back();
				}
				cacheList.push_front(CacheNode(key,value));
				cacheMap[key] = cacheList.begin();
			} else {
				cacheMap[key]->value = value;
				cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
				cacheMap[key] = cacheList.begin();
			}
		}
	private:
		list<CacheNode> cacheList;
		map<int, list<CacheNode>::iterator>cacheMap;
		int size;
};

int main () 
{
  list<string> Milkshakes;
  list<string>::iterator MilkshakeIterator;
  Milkshakes.push_back("Chocolate");
  Milkshakes.push_back("Strayberry");
  Milkshakes.push_front("Lime");
  Milkshakes.push_front("Vanilla");
  Milkshakes.push_front("The Milkshake Menu");
  Milkshakes.push_back("***That's the end.***");
  MilkshakeIterator=Milkshakes.begin();
  while(MilkshakeIterator != Milkshakes.end()) {
  	cout << *MilkshakeIterator << "  ";
  	MilkshakeIterator++;
  }
  system("pause");
  return 0;
}