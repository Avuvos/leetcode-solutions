class ProductOfNumbers {
    
    private List<Integer> preProd;
    
    public ProductOfNumbers() {
        preProd = new ArrayList<>();
    }
    
    public void add(int num) {
        if (num == 0) {
            preProd = new ArrayList();
            return;
        }
        if (preProd.size() == 0) {
            preProd.add(num);
            return;
        }
        int idx = preProd.size() - 1;
        int lastProd = preProd.get(idx);
        preProd.add(num * lastProd);
    }
    
    public int getProduct(int k) {
        int n = preProd.size();
        if (k > n) return 0;
        if (k == n) return preProd.get(n - 1);
        return preProd.get(n - 1) / preProd.get(n - k - 1);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
