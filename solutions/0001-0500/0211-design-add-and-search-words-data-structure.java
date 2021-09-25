public class TrieNode {
    Map<Character, TrieNode> charToNode;
    boolean isEnd = false;
    public TrieNode() {
    charToNode = new HashMap<>();
    }
}
class WordDictionary {
        TrieNode root;
        public WordDictionary() {
            root = new TrieNode();
        }
        
        public void addWord(String word) {
            TrieNode node = root;
            for (int i=0; i<word.length(); i++) {
                char ch = word.charAt(i);
                if (!node.charToNode.containsKey(ch)) {
                    node.charToNode.put(ch, new TrieNode());
                }
                node = node.charToNode.get(ch);
            }
            node.isEnd = true;
        }
        public boolean search(String word) {
            return dfs(root, word, 0);
        }
        public boolean dfs(TrieNode node, String word, int ind){
            for (int i=ind; i<word.length(); i++) {
                char ch = word.charAt(i);
                if (ch == '.') {
                        for (Map.Entry<Character, TrieNode> entry:                                    node.charToNode.entrySet()) {
                            if (dfs(entry.getValue(), word, i + 1)) {
                                return true;
                            }
                        }
                        return false;
                }
                else {
                    if (!node.charToNode.containsKey(ch)) {
                        return false;
                    }
                    node = node.charToNode.get(ch);
                }
            }
            return node.isEnd;
        }
    }

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
