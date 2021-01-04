import heapq
import sys

heap = []
result = 0
n = int(sys.stdin.readline())
for _ in range(n):
    heapq.heappush(heap, int(sys.stdin.readline()))


def solution(heap):
    result = 0
    if len(heap) == 1:
        print(0)
        return
    while len(heap) > 0:
        first = heapq.heappop(heap)
        second = heapq.heappop(heap)
        result += (first + second)
        if len(heap) == 0:
            break
        heapq.heappush(heap, first+second)
    print(result)
    return


solution(heap)