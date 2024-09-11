a = input()
b = input()
c = input()

ans = int(0)

if a != "FizzBuzz" and a != "Fizz" and a != "Buzz" :
    ans = int(a) + 3
elif b != "FizzBuzz" and b != "Fizz" and b != "Buzz" :
    ans = int(b) + 2
else :
    ans = int(c) + 1

if ans % 3 == 0 and ans % 5 == 0 :
    print("FizzBuzz")
elif ans % 3 == 0 :
    print("Fizz")
elif ans % 5 == 0 :
    print("Buzz")
else :
    print(ans)