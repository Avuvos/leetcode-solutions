class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        pts = set()
        for a, b, r in circles:
            for x in range(a - r, a + r + 1):
                for y in range(b - r, b + r + 1):
                    if ((x-a)**2 + (y-b)**2)**0.5 <= r:
                        pts.add((x, y))
        return len(pts)
