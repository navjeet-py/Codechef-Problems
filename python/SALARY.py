for _ in range(int(input())):
      N = int(input())
      A = list(map(int, input().split()))
      print(sum(A) - N * min(A))