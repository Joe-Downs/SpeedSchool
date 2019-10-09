name = input()
cost = int(input())
discount = int(input())

discount_decimal = discount / 100

discounted_price = int(cost - (cost * discount_decimal))

print("A " + name.lower() + " costs " + str(cost) + " dollars.\nIf it is on sale for "+ str(discount) + " percent off, it will cost " + str(discounted_price) + " dollars instead.")
