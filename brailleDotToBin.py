
while True:
    brailleKeys =0
    print("Enter Braille Dot Numbers")
    string = str(input())

    for char in string:
        brailleKeys = brailleKeys | 1 << (6-int(char))

    print(bin(brailleKeys))
