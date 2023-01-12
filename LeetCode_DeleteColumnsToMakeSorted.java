public class LeetCode_DeleteColumnsToMakeSorted {

    public int minDeletionSize(String[] strs) {
        int countOfStrings = strs.length;
        int lengthOfString = strs[0].length();

        int ans = 0;

        for(int i = 0; i < lengthOfString; i++) {
            boolean isSortable = true;
            int prevCharactor = 0;
            for(int j = 0; j < countOfStrings; j++) {
                int currentCharactor = strs[j].charAt(i) - 'a';

                if(prevCharactor > currentCharactor) {
                    isSortable = false;
                    break;
                }
                prevCharactor = currentCharactor;
            }
            
            if(!isSortable) ans++;
        }

        return ans;
    }
    
}
