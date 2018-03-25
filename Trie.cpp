// Trie
#include<iostream>
using namespace std;

struct TrieNode
{
	char data;
	TrieNode *child[26];
	bool terminates;
	static int CharToIndex(char c)
	{
		//cout<<"accessing at index "<<int(c - 'a')<<endl;
		return int(c - 'a');
	}
	TrieNode(char c):data(c), terminates(false)
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
		TrieNode *temp = root;
		for(int i = 0; i<length;i++)
		{
			if(temp->child[TrieNode::CharToIndex(s[i])] == NULL )
			{
				temp->child[TrieNode::CharToIndex(s[i])] = new TrieNode(s[i]);
				//cout<<"creating "<<temp<<endl;
			}
			temp = temp->child[TrieNode::CharToIndex(s[i])];
		}
		temp->terminates = true;
	}
	remove(char *s, int length)
	{
		
	}
	bool find(char *s, int length)
	{
		TrieNode *temp = root;
		for(int i = 0; i<length;i++)
		{
			temp = temp->child[TrieNode::CharToIndex(s[i])];
			if(temp == NULL )
			{
				//cout<<"checking "<<temp<<endl;
				return false;
			}
		}
		if(temp->terminates == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Trie t;
	t.insert("harry", 5);
	cout<<t.find("harry", 5);
}

