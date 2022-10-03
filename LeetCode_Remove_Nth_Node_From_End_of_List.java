public class LeetCode_Remove_Nth_Node_From_End_of_List {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode current = head;
        int size = 0;
        while(current != null) {
            size++;
            current = current.next;
        }

        current = head;

        if(size == n) return head.next;

        n = size-n+1;
        int pos = 0;
        
        while(current!=null){
             pos++;

             System.out.println("val: " + head.val);
            
              if(pos==n-1){
                  current.next = current.next.next;
              }else{
                  current = current.next;
              }
           
        }
        return head;
    }
}
