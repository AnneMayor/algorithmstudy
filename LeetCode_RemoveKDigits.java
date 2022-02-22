import java.util.Stack;

public class LeetCode_RemoveKDigits {

    public String removeKdigits(String num, int k) {
        int len = num.length();

        Stack<Character> st = new Stack<>();
        for(int i = 0; i < len; i++) {
            while(k > 0 && !st.isEmpty() && st.peek() - '0' > num.charAt(i) - '0') {
                st.pop();
                k--;
            }

            st.push(num.charAt(i));
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        StringBuilder sb = new StringBuilder();
        while(!st.isEmpty()) sb.append(st.pop());
        sb.reverse();
        int n = sb.length();
        for(int i = 0; i < n; i++) {
            if(sb.charAt(0) == '0') sb.deleteCharAt(0);
        }
        // System.out.println(sb.toString());

        if(sb.toString().equals("")) sb.append("0");

        return sb.toString();
    }
    
}
