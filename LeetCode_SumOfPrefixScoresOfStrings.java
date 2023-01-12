public class LeetCode_SumOfPrefixScoresOfStrings {

    static class TrieNode {

        private final TrieNode trieNode[] = new TrieNode[26];

        private boolean isEnd;
        private int score;

        public TrieNode() {
            score = 0;
        }

        public boolean containsKey(char value) {
            return trieNode[value - 'a'] != null;
        }

        public void put(char value, TrieNode node) {
            trieNode[value-'a'] = node;
        }

        public TrieNode findNode(char value) {
            return trieNode[value - 'a'];
        }

        public boolean isEnd() {
            return isEnd;
        }

        public void addOneScore() {
            score++;
        }

        public int getScore() {
            return score;
        }
    }

    public int[] sumPrefixScores(String[] words) {
        TrieNode root = new TrieNode();

        int[] ans = new int[words.length];
        
        for(String word : words) {
            TrieNode temp = root;
            int len = word.length();
            for(int i = 0; i < len; i++) {
                if(temp.findNode(word.charAt(i)) == null) {
                    temp.put(word.charAt(i), new TrieNode());
                }
                temp.findNode(word.charAt(i)).addOneScore();
                temp = temp.findNode(word.charAt(i));
            }
        }

        int len = words.length;
        for(int i = 0; i < len; i++) {
            TrieNode temp = root;
            int wLen = words[i].length();
            for(int j = 0; j < wLen; j++) {
                ans[i] += temp.findNode(words[i].charAt(j)).score;
                temp = temp.findNode(words[i].charAt(j));
            }
        }

        return ans;
    }
}
