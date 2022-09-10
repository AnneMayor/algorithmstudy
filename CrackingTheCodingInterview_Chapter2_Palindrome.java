import java.util.Stack;

public class CrackingTheCodingInterview_Chapter2_Palindrome {

    static class LinkedListNode {
        LinkedListNode next = null;
        int data;
    }

    class Result {
        LinkedListNode node;
        boolean isPalindrome = false;

        public Result(LinkedListNode node, boolean isPalindrome) {
            this.node = node;
            this.isPalindrome = isPalindrome;
        }
    }

    public boolean isPalindrome(LinkedListNode head) {
        LinkedListNode fast = head;
        LinkedListNode slow = head;
        
        Stack<Integer> stack = new Stack<>();

        while(fast != null && fast.next != null) {
            stack.push(slow.data);
            slow = slow.next;
            fast = fast.next.next;
        }

        if(fast != null) {
            slow = slow.next;
        }

        while(slow != null) {
            int value = stack.pop();
            if(value != slow.data) return false;
            slow = slow.next;
        }

        return true;
    }

    public boolean isPalindromeRecursive(LinkedListNode node) {
        int length = lengthOfList(node);
        Result p = isPalindrome(node, length);
        return p.isPalindrome;
    }
    
    public int lengthOfList(LinkedListNode node) {
        int res = 0;
        while(node != null) {
            res++;
            node = node.next;
        }

        return res;
    }

    public Result isPalindrome(LinkedListNode node, int length) {
        if(node == null || length <= 0) {
            return new Result(node, true);
        } else if(length == 1) {
            return new Result(node.next, true);
        }

        Result res = isPalindrome(node.next, length-2);

        if(res.node == null || res.isPalindrome == false) return res;

        res.isPalindrome = (res.node.data == node.data);
        res.node = res.node.next;

        return res;
    }
}
