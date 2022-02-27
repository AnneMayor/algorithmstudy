import java.util.HashMap;
import java.util.Map;

public class LeetCode_Weekly_282_No2 {

    public int minSteps(String s, String t) {
        Map<Character, Integer> spellCheck = new HashMap<>();
        int numOfDuplicateCharacters = 0;
        int sLen = s.length();
        for(int i = 0; i < sLen; i++) {
            if(spellCheck.containsKey(s.charAt(i))) {
                spellCheck.put(s.charAt(i), spellCheck.get(s.charAt(i)) + 1);
            } else {
                spellCheck.put(s.charAt(i), 1);
            }
        }

        int tLen = t.length();
        for(int i = 0; i < tLen; i++) {
            if(spellCheck.containsKey(t.charAt(i))) {
                int numOfLeftChar = spellCheck.get(t.charAt(i));
                if(numOfLeftChar > 0) numOfDuplicateCharacters++;
                spellCheck.put(t.charAt(i), numOfLeftChar- 1);
            }
        }

        return (sLen - numOfDuplicateCharacters) + (tLen - numOfDuplicateCharacters);
    }
    
}
