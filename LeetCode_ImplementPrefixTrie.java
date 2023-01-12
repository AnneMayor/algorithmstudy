public class LeetCode_ImplementPrefixTrie {

    static class TrieNode {
        private TrieNode[] links;

        private final int R = 26;

        private boolean isEnd;

        public TrieNode() {
            links = new TrieNode[R];
        }

        public boolean containsKey(char ch) {
            return links[ch - 'a'] != null;
        }

        public TrieNode get(char ch) {
            return links[ch - 'a'];
        }

        public void put(char ch, TrieNode node) {
            links[ch - 'a'] = node;
        }

        public void setEnd() {
            isEnd = true;
        }

        public boolean getEnd() {
            return isEnd;
        }
    }

    static class Trie {

        private TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        public void insert(String word) {
            TrieNode node = root;
            for(int i = 0; i < word.length(); i++) {
                char currentChar = word.charAt(i);
                if(!node.containsKey(currentChar)) {
                    node.put(currentChar, new TrieNode());
                }
                node = node.get(currentChar);
            }

            node.setEnd();
        }
        
        private TrieNode searchPrefix(String prefix) {
            TrieNode node = root;
            for(int i = 0; i < prefix.length(); i++) {
                char currentChar = prefix.charAt(i);
                if(node.containsKey(currentChar)) {
                    node = node.get(currentChar);
                } else return null;
            }

            return node;
        }

        public boolean search(String word) {
            TrieNode node = searchPrefix(word);
            return node != null && node.getEnd();
        }
        
        public boolean startsWith(String prefix) {
            TrieNode node = searchPrefix(prefix);
            return node != null;
        }
    }
    
}
