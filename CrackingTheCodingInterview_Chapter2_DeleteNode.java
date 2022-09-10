public class CrackingTheCodingInterview_Chapter2_DeleteNode {

    static class LinkedListNode {
        LinkedListNode next = null;
        int data;

        public LinkedListNode(int data) {
            this.data = data;
        }
    }

    public boolean deleteNode(LinkedListNode node) {
        if(node == null || node.next == null) return false;

        LinkedListNode next = node.next;

        node.data = next.data;
        node.next = next.next;

        return true;
    }
}
