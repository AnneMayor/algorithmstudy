import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class GenerateParenthesis {

    public List<String> generateParenthesis(int n) {
        int totalLength = 2 * n;

        String[] parenthesis = {"(", ")"};

        List<String> ans = new ArrayList<>();
        recursiveSearch(0, totalLength, parenthesis, new ArrayList<String>(), ans);

        return ans;
    }

    public void recursiveSearch(int current, int total, String[] parenthesis, List<String> temp, List<String> ans) {
        if(current >= total) {
            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < total; i++) {
                sb.append(temp.get(i));
            }

            if(isGoodParenthesis(sb.toString())) {
                ans.add(sb.toString());
            }
            return ;
        }

        for(int i = 0; i < 2; i++) {
            temp.add(parenthesis[i]);
            recursiveSearch(current+1, total, parenthesis, temp, ans);
            temp.remove(temp.size()-1);
        }
    }
    
    public boolean isGoodParenthesis(String temp) {
        boolean res = true;

        Deque<Character> q = new LinkedList<>();
        int len = temp.length();

        for(int i = 0; i < len; i++) {
            if(q.isEmpty()) q.addLast(temp.charAt(i));
            else {
                if(temp.charAt(i) == '(') {
                    q.addLast(temp.charAt(i));
                } else {
                    if(q.getLast() == '(') q.pollLast();
                    else q.addLast(temp.charAt(i));
                }
            }
        }

        if(!q.isEmpty()) res = false;

        return res;
    }
}
