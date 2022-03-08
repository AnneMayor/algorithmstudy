#include <map>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        map<Node*, Node*> visited;
        Node* current = head;
        while (current != NULL)
        {
            Node* newNode = new Node(current->val);
            visited[current] = newNode;
            current = current->next;
        }

		Node *currentRandom=head;
		while(currentRandom){
			visited[currentRandom]->next=visited[currentRandom->next];
			visited[currentRandom]->random=visited[currentRandom->random];
			currentRandom=currentRandom->next;
		}

        return visited[head];
    }

};