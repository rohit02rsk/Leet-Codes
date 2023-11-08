class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        distX = abs(sx - fx)
        distY = abs(sy - fy)
        
        if distX == 0 and distY == 0 and t == 1:
            return False

        diagonalDist = min(distX, distY)
        minTimeTaken = distX + distY - diagonalDist
        
        return minTimeTaken <= t