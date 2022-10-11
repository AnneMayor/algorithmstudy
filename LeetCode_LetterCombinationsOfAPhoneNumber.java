import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class LeetCode_LetterCombinationsOfAPhoneNumber {

    public List<String> letterCombinations(String digits) {
		LinkedList<String> res = new LinkedList<>();
        Map<Integer, String> map = new HashMap<>();
        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");

        res.add("");

        int countOfDigits = digits.length();
        
        if(countOfDigits <= 0) return new ArrayList<>();

        while(res.peek().length() != countOfDigits) {
            String firstDigits = res.remove();

            int digit = digits.charAt(firstDigits.length()) - '0';
            String charactors = map.get(digit);

            for(char ch : charactors.toCharArray()) {
                res.add(firstDigits + ch);
            }
        }
        
        return res;
	}   
}
