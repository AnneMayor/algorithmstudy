public class Solution {
    public String reverseStr(String s, int k) {
        List<String> strings = new ArrayList<>();

        int index = 0;
        int n = s.length();

        if (k > n) {
            return s;
        }

        while(index <= n - 2 * k) {
            strings.add(s.substring(index, index + 2*k));
            index += 2 * k;
        }

        if (index < n) {
            strings.add(s.substring(index, n));
        }

        StringBuilder stringBuilder = new StringBuilder();
        for (String string : strings) {
            int len = string.length();

            if (k > len) {
                for (int i = len - 1; i >= 0; i--) {
                    stringBuilder.append(string.charAt(i));
                }
                continue;
            }

            for (int i = k - 1; i >= 0; i--) {
                stringBuilder.append(string.charAt(i));
            }

            for (int i = k; i < len; i++) {
                stringBuilder.append(string.charAt(i));
            }
        }

        return stringBuilder.toString();
    }

    public String conciseSolution(String s, int k) {
        char[] stringArray = s.toCharArray();

        int index = 0;
        int n = s.length();

        while (index < n) {
            swap(stringArray, index, Math.min(index+k-1, n-1));
            index += 2*k;
        }

        return new String(stringArray);
    }

    public void swap(char[] arr, int start, int end) {
        while (start < end) {
            char temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
    }
}