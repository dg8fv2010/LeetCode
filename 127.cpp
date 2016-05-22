struct Node
{
	string str;
	int len;
	Node(string s, int l):str(s),len(l){}
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	queue<Node*> q;
    	q.push(new Node(beginWord, 1));
    	unordered_map<string, bool> m;
    	m[beginWord]=true;

    	while (q.empty()==false)
    	{
    		Node* n=q.front();
    		q.pop();

    		for (int i=0;i<n->str.length();i++)
    		{
    			for (char c='a';c<='z';c++)
    			{
    				string curStr=n->str;
    				curStr[i]=c;
    				if (curStr==n->str)
    				{
    					continue;
    				}

    				if (curStr==endWord)
    				{
    					return n->len+1;
    				}
    				if (wordList.find(curStr)!=wordList.end() && m[curStr]==false)
    				{
    					q.push(new Node(curStr, n->len+1));
    					m[curStr]=true;
    				}
    			}
    		}
    		delete n;
    		n=NULL;
    	}    
    	return 0;
    }
};