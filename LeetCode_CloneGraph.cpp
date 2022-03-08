#include <map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> graph;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;    

        if(graph.find(node) == graph.end()) {
            graph[node] = new Node(node -> val, {});
            
            for(auto current : node -> neighbors) {
                graph[node] -> neighbors.push_back(cloneGraph(current));
            }
        }

        return graph[node];
    }
};