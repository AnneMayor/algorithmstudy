import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode_LetterCombinationsOfAPhoneNumber_Recursive {

    private List<String> result;
    private Map<Integer, String> map;

    public List<String> letterCombinations(String digits) {
        map = new HashMap<>();
        result = new ArrayList<>();

        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");

        int countOfDigits = digits.length();

        recursiveBuild(digits, 0, countOfDigits, new StringBuilder());

        return result;
    }

    public void recursiveBuild(String digits, int currentCount, int countOfDigits, StringBuilder sb) {
        if(currentCount >= countOfDigits) {
            result.add(sb.toString());
            return ;
        }

        String values = map.get(digits.charAt(currentCount) - '0');
        int valuesLen = values.length();

        for(int i = 0; i < valuesLen; i++) {
            sb.append(values.charAt(i) + "");
            recursiveBuild(digits, currentCount+1, countOfDigits, sb);
            sb.deleteCharAt(sb.toString().length() - 1);
        }
    }
}
