public class LeetCode_SwapPairs {

    // public class ListNode {
    //     int val;
    //     ListNode next;

    //     ListNode() {
    //     }

    //     ListNode(int val) {
    //         this.val = val;
    //     }

    //     ListNode(int val, ListNode next) {
    //         this.val = val;
    //         this.next = next;
    //     }
    // }

    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode nextHead = swapPairs(head.next.next);

        ListNode temp = head.next;
        head.next = nextHead;
        temp.next = head;

        return temp;
    }
}
