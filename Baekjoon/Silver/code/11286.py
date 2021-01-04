import heapq
import sys

a = int(sys.stdin.readline())
i = 0
heap = []
while i < a:
    i += 1
    num = int(sys.stdin.readline())
    if num != 0:
        heapq.heappush(heap, (abs(num), num))
    else:
        if(len(heap) <= 0):
            print(0)
        else:
            weight, val = heapq.heappop(heap)
            print(val)
