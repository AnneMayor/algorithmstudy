public class CrackingTheCodingInterview_Chapter2_SumLists {
    static class LinkedListNode {
        LinkedListNode next = null;
        int data;

        public LinkedListNode(int data) {
            this.data = data;
        }
    }

    class PartialSum {
        LinkedListNode sum = null;
        int carry = 0;
    }
    
    // problem: (7 -> 1 -> 6) + (5 -> 9 -> 2) = (2 -> 1 -> 9)
    public LinkedListNode sumList(LinkedListNode first, LinkedListNode second, int carry) {
        if(first == null && second == null && carry == 0) return null;
        
        LinkedListNode res = new LinkedListNode(0);
        int value = carry;
        if(first != null) {
            value += first.data;
        }

        if(second != null) {
            value += second.data;
        }

        res.data = value % 10;

        if(first != null || second != null) {
            res.next = sumList(first.next, second.next, carry >= 10 ? 1 : 0);
        }

        return res;
    }
    
    // problem: (6 -> 1 -> 7) + (2 -> 9 -> 5) = (9 -> 1 -> 2)
    public LinkedListNode sumList(LinkedListNode first, LinkedListNode second) {
        int firstLength = length(first);
        int secondLength = length(second);

        if(firstLength > secondLength) {
            second = addPaddingZero(second, firstLength - secondLength);
        }

        if(firstLength < secondLength) {
            first = addPaddingZero(first, secondLength - firstLength);
        }

        PartialSum sum = addListsHelper(first, second);
        
        if(sum.carry == 0) return sum.sum;
        LinkedListNode res = insertBefore(sum.sum, sum.carry);
        return res;
    }

    public PartialSum addListsHelper(LinkedListNode first, LinkedListNode second) {
        if(first == null && second == null) {
            PartialSum sum = new PartialSum();
            return sum;
        }

        PartialSum sum = addListsHelper(first.next, second.next);

        int val = sum.carry + first.data + second.data;

        LinkedListNode full_res = insertBefore(sum.sum, val % 10);

        sum.sum = full_res;
        sum.carry = val / 10;
        return sum;
    }

    public LinkedListNode addPaddingZero(LinkedListNode node, int padding) {
        LinkedListNode head = node;
        for(int i = 0; i < padding; i++) {
            head = insertBefore(head, 0);
        }

        return head;
    }

    public LinkedListNode insertBefore(LinkedListNode list, int data) {
        LinkedListNode node = new LinkedListNode(data);
        if(list != null) {
            node.next = list;
        }

        return node;
    }

    public int length(LinkedListNode node) {
        int res = 0;

        while(node != null) {
            res++;
            node = node.next;
        }

        return res;
    }
}