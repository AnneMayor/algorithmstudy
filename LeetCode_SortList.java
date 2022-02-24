import java.util.PriorityQueue;

public class LeetCode_SortList {

    public ListNode sortList(ListNode head) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(head.val);
        head = head.next;
        while(head != null) {
            pq.offer(head.val);
            head = head.next;
        }

        // 여기 풀이가 참...인상적이다...진짜 잊지 못하겠음...!
        ListNode fake = new ListNode(-1);
        ListNode ans = fake;
        while(!pq.isEmpty()) {
            ans.next = new ListNode(pq.poll());
            ans = ans.next;
        }

        return fake.next;
    }
    
}
