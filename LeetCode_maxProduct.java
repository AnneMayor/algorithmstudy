public class LeetCode_maxProduct {

    public int ans;
    public int maxProduct(String s) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        ans = 0;

        recursiveSearch(0, s, s1, s2);

        return ans;
    }
    
    public void recursiveSearch(int start, String s, StringBuilder first, StringBuilder second) {
        if(start >= s.length()) {

            if(isPalindrom(first.toString()) && isPalindrom(second.toString())) {
                ans = Math.max(ans, first.toString().length() * second.toString().length());
            }

            return;
        }

        recursiveSearch(start+1, s, first, second);

        first.append(s.charAt(start));
        recursiveSearch(start+1, s, first, second);
        first.deleteCharAt(first.toString().length()-1);

        second.append(s.charAt(start));
        recursiveSearch(start+1, s, first, second);
        second.deleteCharAt(second.toString().length()-1);
    }

    public boolean isPalindrom(String s) {
        boolean res = true;

        int start = 0, end = s.length() - 1;

        while(start < end) {
            if(s.charAt(start) != s.charAt(end)) return false;
            start++;
            end--;
        }

        return res;
    }
    
}
