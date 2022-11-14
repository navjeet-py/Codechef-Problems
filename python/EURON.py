from bisect import bisect


N = int(input())
array = list(map(int, input().split()))
sorted_ = [array[0]]
sm = 0
for i in array[1:]:
    p = bisect(sorted_, i)
    sm += (len(sorted_) - p)
    # print(sm, sorted_)
    sorted_.insert(p, i)

print(sm)