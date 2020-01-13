with open("planned-output-escaped.txt") as f:
    original_line_array = f.readlines()
    #Each line in the file is an item in the above array

formatted_lines_array = []
    
for line in original_line_array:
    line = line.rstrip("\n\"")
    formatted_line = "printf(\"" + line + "\\n\");"
    print(formatted_line)
    formatted_lines_array.append(formatted_line)

with open("formatted_lines.txt", "w") as f:
    for line in formatted_lines_array:
        f.write(line + "\n")
