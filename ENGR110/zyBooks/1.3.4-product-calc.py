answer = " "
numbers_array = []

while answer != "":
    answer = input("Choose your numbers: ")
    if answer != "":
        numbers_array.append(int(answer))
        #print(numbers_array)
        
product = 1
for entry in numbers_array:
    #print(entry)
    product *= entry

print("The product is: " + str(product))
