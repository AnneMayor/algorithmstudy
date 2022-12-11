import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode_SortCharactersByFrequency {

    public String frequencySort(String s) {

        Map<Character, Integer> alphabets = new HashMap<>();
        List<StringBuilder> buckets = new ArrayList<>();

        int n = s.length();

        for(int index = 0; index <= n; index++) {
            buckets.add(new StringBuilder());
        }

        for(int index = 0; index < n; index++) {
            alphabets.put(s.charAt(index), alphabets.getOrDefault(s.charAt(index), 0)+1);
        }

        for(char letter : alphabets.keySet()) {
            for(int count = 0; count < alphabets.get(letter); count++) {
                buckets.get(alphabets.get(letter)).append(letter);
            }
        }

        StringBuilder res = new StringBuilder();
        for(int index = n; index >= 0; index--) {
            res.append(buckets.get(index));
        }

        return res.toString();
    }
}