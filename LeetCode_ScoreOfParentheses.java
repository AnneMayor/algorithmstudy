import java.util.Deque;
import java.util.LinkedList;

public class Solution {

    class Score {
        char parenthesis;
        int depth;

        public Score(char parenthesis, int depth) {
            this.parenthesis = parenthesis;
            this.depth = depth;
        }
    }

    public int scoreOfParentheses(String s) {
        Deque<Score> dq = new LinkedList<>();

        int n = s.length();

        int ans = 0;

        dq.offer(new Score(s.charAt(0), 1));

        for(int i = 1; i < n; i++) {
            Score current = dq.peekLast();
            switch(s.charAt(i)) {
                case '(':
                    if(current.parenthesis == '(') {
                        dq.offer(new Score(s.charAt(i), current.depth+1));
                    } else {
                        dq.offer(new Score(s.charAt(i), current.depth));
                    }
                    break;

                case ')':
                    if(current.parenthesis == '(') {
                        ans += Math.pow(2, current.depth-1);
                        dq.offer(new Score(s.charAt(i), current.depth));
                    } else {
                        dq.offer(new Score(s.charAt(i), current.depth-1));
                    }
                    break;
            }
        }

        return ans;
    }

    public int scoreOfParentheses_O(N)_Time_And_Space_Complexity(String s) {
        Deque<Integer> dq = new LinkedList<>();
        dq.offer(0);

        for(char c : s.toCharArray()) {
            if(c == '(') {
                dq.offer(0);
            } else {
                int multiple = dq.pollLast();
                int totalSum = dq.pollLast();
                dq.addLast(totalSum + Math.max(2*multiple, 1));
            }
        }

        return dq.peekLast();
    }

    public int scoreOfParentheses_O(N)_Time_And_O(1)_Space_Complexity(String s) {
        int depth = 0;
        int ans = 0;

        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s.charAt(i) == '(') depth++;
            else {
                depth--;
                if(s.charAt(i-1) == '(') {
                    ans += (1 << depth);
                }
            }
        }

        return ans;
    }
    
}
