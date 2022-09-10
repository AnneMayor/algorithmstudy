public class CrackingTheCodingInterview_Chapter2_Intersection {

    static class LinkedListNode {
        LinkedListNode next = null;
        int data;
        
        public LinkedListNode(int data) {
            this.data = data;
        }
    }

    class Result {
        LinkedListNode node;
        int length;

        public Result(LinkedListNode node, int length) {
            this.node = node;
            this.length = length;
        }
    }

    public LinkedListNode findIntersection(LinkedListNode list1, LinkedListNode list2) {
        Result result1 = getLastNodeAndLength(list1);
        Result result2 = getLastNodeAndLength(list2);

        if(result1.node != result2.node) return null;
        
        // if(result1.length > result2.length) {
        //     for(int i = 0; i < result1.length - result2.length; i++) {
        //         list1 = list1.next;
        //     }
        // } else if(result1.length < result2.length) {
        //     for(int i = 0; i < result2.length - result1.length; i++) {
        //         list2 = list2.next;
        //     }
        // }

        // while(list1 != null && list2 != null) {
        //     if(list1 == list2) return list1;
        //     list1 = list1.next;
        //     list2 = list2.next;
        // }

        // return null;

        LinkedListNode shorter = result1.length < result2.length? list1 : list2;
        LinkedListNode longer = result1.length > result2.length? list1 : list2;

        longer = getKthNode(longer, Math.abs(result1.length - result2.length));

        while(shorter != longer) {
            shorter = shorter.next;
            longer = longer.next;
        }

        return shorter;
    }

    public Result getLastNodeAndLength(LinkedListNode list) {
        int length = 0;
        LinkedListNode lastNode = null;

        while(list != null) {
            lastNode = list;
            list = list.next;
            length++;
        }

        return new Result(lastNode, length);
    }

    public LinkedListNode getKthNode(LinkedListNode node, int length) {
        for(int i = 0; i < length; i++) {
            node = node.next;
        }

        return node;
    }

}
