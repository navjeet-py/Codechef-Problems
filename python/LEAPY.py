for _ in range(int(input())):
  y = int(input())
  if ((y % 400 == 0) or (y % 4 == 0 and y % 100 != 0)):
    print("It is a leap year.")
  else:
    while not (((y % 400 == 0) or (y % 4 == 0 and y % 100 != 0))):
      y += 1
    print("Not a leap year. Suggested:", y)