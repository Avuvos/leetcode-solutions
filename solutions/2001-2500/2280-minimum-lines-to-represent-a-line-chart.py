class Solution:
    def minimumLines(self, stockPrices: List[List[int]]) -> int:
        N = len(stockPrices)
        if N == 1:
            return 0
        stockPrices.sort(key=lambda x: x[0])
        res = 1
        px, py = stockPrices[0]
        cx, cy = stockPrices[1]
        pdx, pdy = px - cx, py - cy
        px, py = cx, cy
        for i in range(2, N):
            cx, cy = stockPrices[i]
            cdx, cdy = px - cx, py - cy
            if pdy * cdx == pdx * cdy:
                pdx, pdy = cdx, cdy
                px, py = cx, cy
                continue
            else:
                pdx, pdy = cdx, cdy
                px, py = cx, cy
                res += 1
        return res
