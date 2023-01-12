public class LeetCode_DetectCapitals {
    public boolean detectCapitalUse(String word) {
        int countOfUpperCaseLetters = 0;
        
        for(char letter : word.toCharArray()) {
            if( letter >= 'A'  && letter <= 'Z') {
                countOfUpperCaseLetters++;
            }
        }

        if(countOfUpperCaseLetters == 0 || countOfUpperCaseLetters == word.length()) return true;

        if(countOfUpperCaseLetters == 1) {
            if(word.toCharArray()[0] >= 'A' && word.toCharArray()[0] <= 'Z') return true;
        }

        return false;
    }
}
