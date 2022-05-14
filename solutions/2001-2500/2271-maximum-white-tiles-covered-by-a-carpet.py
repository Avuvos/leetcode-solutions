class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort() #by starting index
        n = len(tiles)
        res = 0
        prefix = [tiles[0][1] - tiles[0][0] + 1]
        starts = [tiles[i][0] for i in range(n)]
        for i in range(1, n):
            prefix.append(prefix[i - 1] + tiles[i][1] - tiles[i][0] + 1)


        for i in range(n):
            s, e = tiles[i][0], tiles[i][1]
            if e - s >= carpetLen:
                return carpetLen
            idx = bisect_right(starts, s + carpetLen - 1) - 1
            curr = 0
            if tiles[idx][1] > s + carpetLen - 1:
                curr = tiles[idx][1] - s - carpetLen + 1
            if i > 0:
                res = max(res, prefix[idx] - prefix[i - 1] - curr)
            else:
                res = max(res, prefix[idx] - curr)
        return res
