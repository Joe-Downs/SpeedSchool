import random

min = 1
max = 6

guess = int(input("Guess a number of a 6-sided die: "))

print("Rolling a die...")

roll = int(random.randint(min, max))

print("You rolled a: %s" %roll)

if guess == roll:
           print("You guess correctly")
else:
           print("You guessed incorrectly")
