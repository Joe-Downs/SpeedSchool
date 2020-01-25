codes = ["cad", "eur", "jpy", "mxn", "nok", "usd"]

for each in codes:
    string = 'printf("||\\t' + str.upper(each) + '\\t||    %.3f\\t||    %.3f\\t||    %.3f\\t||    %.3f\\t||    %.3f\\t||    %.3f\\t||\\n", '
    for each2 in codes:

        string += each + "_" + each2 + ", "
    print(string + ");")

