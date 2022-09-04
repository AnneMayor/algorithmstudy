public class CrackingTheCodingInterview_Chapter2_PrintKthElement {

    static class LinkedListNode {
        LinkedListNode next = null;
        int data;

        public LinkedListNode(int data) {
            this.data = data;
        }
    }

    // recursive 1 : Don't return the element
    // int printKthToLastElement(LinkedListNode head, int k) {
    //     if(head == null) return 0;

    //     int index = printKthToLastElement(head, k) + 1;

    //     if(index == k) System.out.println(head.data);

    //     return index;
    // }

    // recursive 2 : return the node
    LinkedListNode printKthToLastElement(LinkedListNode head, int k, int idx) {
        if(head == null) return null;
        
        LinkedListNode next = printKthToLastElement(head.next, k, idx+1);
        if(idx == k) return head;

        return next;
    }

    // iterative
    LinkedListNode printKthToLastElement(LinkedListNode head, int k) {
        LinkedListNode p1 = head;
        LinkedListNode p2 = head;

        for(int i = 0; i < k; i++) {
            if(p1 == null) return null;
            p1 = p1.next;
        }

        while(p1 != null) {
            p1 = p1.next;
            p2 = p2.next;
        }

        return p2;
    }
}