import java.util.HashSet;
import java.util.Set;

public class CrackingTheCodingInterview_Chapter2_DeleteDups {

    class LinkedListNode {
        LinkedListNode next = null;
        int data;

        public LinkedListNode(int data) {
            this.data = data;
        }
    }

    // time: O(n) | space: O(n)
    // public void deleteDups(LinkedListNode node) {
    //     Set<Integer> group = new HashSet<>();
    //     LinkedListNode previous = null;
    //     while(node != null) {
    //         previous = node;
    //         if(group.contains(node.data)) {
    //             previous.next = node.next;
    //         } else {
    //             group.add(node.data);
    //             previous = node;
    //         }

    //         node = node.next;
    //     }
        
    // }

    // time: O(N^2) | space: O(1)
    public void deleteDups(LinkedListNode node) {
        while(node != null) {
            LinkedListNode current = node;

            while(current.next != null) {
                if(current.next.data == node.data) {
                    current.next = current.next.next;
                } else {
                    current = current.next;
                }
            }

            node = node.next;
        }
    }
    
}
