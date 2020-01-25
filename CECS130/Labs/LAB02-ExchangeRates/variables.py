codes = ["cad", "eur", "jpy", "mxn", "nok", "usd"]

for each in codes:
    for each2 in codes:
        if each == each2:
            print("float " + each + "_" + each2 + " = amount;")
        else:
            print("float " + each + "_" + each2 + " = (amount / usd_" + each + "_rate) * usd_" + each2 + "_rate;")
