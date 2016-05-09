/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==NULL)
        {
            return NULL;
        }
        map<int, UndirectedGraphNode*> nodes;
        queue<UndirectedGraphNode*> q;
        q.push(node);

        while (q.empty()==false)
        {
            UndirectedGraphNode* tmp=q.front();
            q.pop();
            if (nodes.find(tmp->label)==nodes.end())
            {
                UndirectedGraphNode* newNode = new UndirectedGraphNode(tmp->label);
                nodes.insert(make_pair(newNode->label, newNode));
                for (int i=0;i<tmp->neighbors.size();i++)
                {
                    q.push(tmp->neighbors[i]);
                }
            }
        }

        q.push(node);
        while (q.empty()==false)
        {
            UndirectedGraphNode* tmp=q.front();
            q.pop();
            UndirectedGraphNode* existingNode = nodes[tmp->label];
            if (existingNode->neighbors.empty()==true && tmp->neighbors.empty()==false)
            {
                for (int i=0;i<tmp->neighbors.size();i++)
                {
                    existingNode->neighbors.push_back(nodes[tmp->neighbors[i]->label]);
                    q.push(tmp->neighbors[i]);
                }
            }
        }

        return nodes[nodes->label];
    }
};