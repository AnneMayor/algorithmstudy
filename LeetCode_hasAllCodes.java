import java.util.HashSet;
import java.util.Set;

public class LeetCode_hasAllCodes {
    public boolean hasAllCodes(String s, int k) {
        Set<Integer> binaryGroup = new HashSet<>();
        
        StringBuilder sb = new StringBuilder();

        int index = k-1;
        int n = s.length();

        if(k >= n) return false;

        for(int i = 0; i < k; i++) {
            sb.append(s.charAt(i));
        }

        binaryGroup.add(convertBinaryStringToInt(sb.toString()));
        index++;
        while(index < n) {
            sb.deleteCharAt(0);
            sb.append(s.charAt(index));
            binaryGroup.add(convertBinaryStringToInt(sb.toString()));
            index++;
        }
        
        if(binaryGroup.size() == Math.pow(2, k)) return true;
        return false;
    }

    public int convertBinaryStringToInt(String number) {
        int res = 0;
        int digit = 1;
        int index = number.length() - 1;
        while(index >= 0) {
            int num = number.charAt(index) - '0';
            res += (num * digit);
            digit *= 2;
            index--;
        }

        return res;
    }
}