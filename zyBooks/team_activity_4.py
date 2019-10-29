iterations = int(input())
guess = float(input())
roots = [guess]
answer = guess

for x in range(1, iterations + 1):
    answer = (answer) - (((answer * answer)) / (2 * answer))
    roots.append(answer)

print(roots)

for entry in roots:
    print("x " + str(roots.index(entry)) + " = " + str(entry))
