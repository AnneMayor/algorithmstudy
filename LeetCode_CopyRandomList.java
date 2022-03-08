import java.util.Map;
import java.util.HashMap;

public class Solution {

    public Node copyRandomList(Node head) {
        Node responseGetNode = null;
        Node current = head;
        
        Map<Node, Node> hmap = new HashMap<>();

        while(current != null) {
            responseGetNode = new Node(current.val);
            hmap.put(current, responseGetNode);
            current = current.next;
        }

        current = head;
        while(current != null) {
            responseGetNode = hmap.get(current);

            responseGetNode.next = hmap.get(current.next);
            responseGetNode.random = hmap.get(current.random);

            hmap.put(current, responseGetNode);
            current = current.next;
        }

        return hmap.get(head);
    }
    
}