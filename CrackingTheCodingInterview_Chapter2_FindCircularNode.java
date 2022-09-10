public class CrackingTheCodingInterview_Chapter2_FindCircularNode {
    static class LinkedListNode {
        LinkedListNode next = null;
        int data;

        public LinkedListNode(int data) {
            this.data = data;
        }
    }

    public LinkedListNode findCircularNode(LinkedListNode head) {
        LinkedListNode slowRunner = head;
        LinkedListNode fastRunner = head;

        while(fastRunner != null && fastRunner.next != null) {
            slowRunner = slowRunner.next;
            fastRunner = fastRunner.next.next;
            if(slowRunner == fastRunner) break;
        }

        if(fastRunner == null || fastRunner.next == null) return null;

        slowRunner = head;
        while(slowRunner != fastRunner) {
            slowRunner = slowRunner.next;
            fastRunner = fastRunner.next;
        }

        return fastRunner;
    }
}
