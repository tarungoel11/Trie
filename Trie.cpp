// Trie
#include<iostream>
#include<vector>

using namespace std;

class TrieNode
{
	public:
	char data;
	TrieNode *child[27];
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

class TrieTerminatingNode:public TrieNode
{
	public:
	vector<pair<int, int>> info;
	TrieTerminatingNode():TrieNode('-')
	{
		
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
	
	insert(string s)
	{
		TrieNode *temp = root;
		for(int i = 0; i<s.length();i++)
		{
			if(temp->child[TrieNode::CharToIndex(s[i])] == NULL )
			{
				temp->child[TrieNode::CharToIndex(s[i])] = new TrieNode(s[i]);
				//cout<<"creating "<<temp<<endl;
			}
			temp = temp->child[TrieNode::CharToIndex(s[i])];
		}
		{
			temp->terminates = true;
			temp->child[27] = new TrieTerminatingNode();
		}
	}
	void remove(string s)
	{
		TrieNode *temp = root;
		int deletePos = 0;
		TrieNode *deleteNode = root;
		
		for(int i = 0; i<s.length();i++)
		{
			if(temp->child[TrieNode::CharToIndex(s[i])] == NULL )
			{
				return;
			}
			if(temp->terminates == true)
			{
				deletePos = i;
				deleteNode = temp;
			}
			temp = temp->child[TrieNode::CharToIndex(s[i])];
		}
	}
	bool find(string s)
	{
		TrieNode *temp = root;
		for(int i = 0; i<s.length();i++)
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
	t.insert("harry");
	t.insert("hari");
	cout<<t.find("hari");
}

