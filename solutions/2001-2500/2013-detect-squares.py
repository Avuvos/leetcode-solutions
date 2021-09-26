class DetectSquares:
    
    def __init__(self):
        self.ptsCounter = defaultdict(int)
        self.pts = []

    def add(self, point: List[int]) -> None:
        self.ptsCounter[tuple(point)] += 1
        self.pts.append(point)
        
    def count(self, point: List[int]) -> int:
        cnt = 0
        x, y = point
        
        for pt in self.pts:
            currX, currY = pt
            if abs(currX-x) != abs(currY-y) or currX == x or currY == y:
                continue
            cnt += self.ptsCounter[(x, currY)] * self.ptsCounter[(currX, y)]
            
        return cnt
    
# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
