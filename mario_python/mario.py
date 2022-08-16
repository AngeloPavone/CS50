while True:
    try:
        height = int(input("Height: "))
        if height <= 136:
            break
    except ValueError:
        print("This program only excepts integers.")

for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * (i), end="")
    print(" ", end="")
    print("#" * (i))
