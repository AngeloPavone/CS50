from csv import DictReader
from os import name
from sys import argv, exit

def main():
    # Check number of arguments
    if len(argv) != 3:
        print("Usage: dna.py database.csv sequence.txt")

    # Open files
    csv_file = open(argv[1], 'r')
    txt_file = open(argv[2], 'r')

    # Read Files
    csv_obj = DictReader(csv_file)
    headers = csv_obj.fieldnames[1:] # pyright: ignore
    sequence = txt_file.read()
    csv_list = list(csv_obj)


    # Initialize all elements in the longest dict to 0
    longest = {}
    for seq in headers:
        longest[seq] = 0

    for subsequence in headers:
        longest[subsequence] = longest_match(sequence, subsequence)

    print_debug(csv_list, longest)

    for person in csv_list:
        match = 0
        for key in longest:
            if longest[key] == int(person[key]):
                match += 1
            if match == len(longest):
                print(person['name'])
                # Close files
                txt_file.close()
                csv_file.close()
                exit(0)

    print("no match")
    # Close files
    txt_file.close()
    csv_file.close()
    return

# Find longest sequence of consecutive matches
def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)
    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run

# Print for debug
def print_debug(csv_list, longest):
    for row in csv_list:
        print(row)
    print()
    print(longest)

if __name__ == "__main__":
    main()
