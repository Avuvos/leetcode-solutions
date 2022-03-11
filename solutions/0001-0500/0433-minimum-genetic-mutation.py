class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        if start == end: return 0
        if end not in bank: return -1
        
        bank = set(bank)
        bank.add(start)
        geneOptions = ['A', 'C', 'G', 'T']
        
        q = [start]
        res = 0
        
        while q:
            size = len(q)
            for i in range(size):
                gene = q.pop(0)
                if gene == end:
                    return res
                if gene not in bank:
                    continue
                bank.remove(gene)
                for j in range(len(gene)):
                    first = gene[0:j]
                    last = gene[j+1:]
                    for c in geneOptions:
                        st = first + c + last
                        if st != gene: q.append(st)
            res += 1
            
        return -1
                        
        
