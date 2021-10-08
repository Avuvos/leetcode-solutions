class Trie {
    class TrieNode {
         Map<Character, TrieNode> charToNode;
         boolean isEnd = false; 
         public TrieNode() {
            charToNode = new HashMap<>();
        }
     }
    /** Initialize your data structure here. */
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (!node.charToNode.containsKey(ch)) {
                node.charToNode.put(ch, new TrieNode());
            }
            node = node.charToNode.get(ch);
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (!node.charToNode.containsKey(ch)) {
                return false;
            }
            node = node.charToNode.get(ch);
        }
        return node.isEnd;
    }

    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            if (!node.charToNode.containsKey(ch)) {
                return false;
            }
            node = node.charToNode.get(ch);
        }
        return true;
    }
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
