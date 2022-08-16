# main duh
def main():
    ccn = get_input()
    ccn_reversed = reverse(ccn)
    result = double(ccn_reversed)
    cum = summ(ccn_reversed, result)
    print_card_type(ccn, cum)

# Get user input, with validation checking
def get_input():
    while True:
        try:
            ccn = input("CCN: ")
            # Make sure the input is greater than 0 and of length 13, 15, 16
            if (int(ccn) > 0):
                break
        except ValueError:
            print("ERROR: Invalid input")
    return ccn

# Double every second digit in ccn starting from right most digit
def double(ccn):
    result = 0
    num = 0
    # Start at index 1 and increment by 2 until the end of ccn
    for i in range(1, len(ccn), 2):
        num = int(ccn[i]) * 2
        if num > 9:
            x = [int(a) for a in str(num)]
            x2 = sum(x)
            result = result +x2
        else:
            result = result + num
    return result

def summ(ccn, result):
    num = 0
    for i in range(0, len(ccn), 2):
        num = num + int(ccn[i])
    num = num + result
    return num % 10

# Use slicing to reverse the string so that we can loop over it easily
def reverse(ccn):
    return ccn[::-1]

def print_card_type(ccn, cum):
    if cum != 0 and len(ccn) != 13 or len(ccn) != 15 or len(ccn) != 16:
        print("INVALID")
        return
    if validate_amex(ccn) == True:
        print("AMEX")
    if validate_mastercard(ccn) == True:
        print("MASTERCARD")
    if validate_visa(ccn) == True:
        print("VISA")
    return

def validate_amex(ccn):
    first_two = int(ccn[:2])
    if first_two == 34 or first_two == 37 and len(ccn) == 15:
        return True
    else:
        return False

def validate_mastercard(ccn):
    first_two = int(ccn[:2])
    # LOL this shit is so fucking stupid im to lazy to make it right
    if first_two == 51 or first_two == 52 or first_two == 53 or first_two == 54 or first_two == 55 and len(ccn) == 16:
        return True
    else:
        return False

def validate_visa(ccn):
    first_two = int(ccn[:2])
    if first_two == 4 and len(ccn) == 13 or len(ccn) == 16:
        return True
    else:
        return False

if __name__ == "__main__":
    main()
