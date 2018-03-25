// Trie
#include<iostream>
using namespace std;

struct TrieNode
{
	char data;
	TrieNode *child[26];
	
	TrieNode(char c):data(c)
	{
		std::fill(child, child + 26, (TrieNode*)NULL);
	}	
};

class Trie
{
	TrieNode *root;
	
	public:
	Trie()
	{
		root = new TrieNode('*');
	}
	
	insert(char *s, int length)
	{
		
	}
	remove(char *s, int length)
	{
		
	}
	bool find(char *s, int length)
	{
		
	}
};

int main()
{
	Trie t;
}

