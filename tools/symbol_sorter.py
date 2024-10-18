import re
import sys

"""
Quick and dirty script to sort symbols

Example Usage: python3 symbol_updater.py file.txt 0x1234
"""

file_name = sys.argv[1]
symbol_dict = {}

with open(file_name, 'r') as f:
    for line in f:
        match = re.search(r"(.*) = 0x([0-9a-fA-F]*);(.*)", line)
        if match:
            symbol_name = match.group(1)
            address = match.group(2)
            comments = match.group(3)
            updated_address = hex(int(address, 16)).upper()
            address_int = int(address, 16)

            symbol_dict[address_int] = line
            # print(f"symbol_name: {symbol_name}")
            # print(f"address: {address}")
            # print(f"comments: {comments}")
            # print(f"updated_address: {updated_address}")
            # print(f"new line: {symbol_name} = {updated_address};{comments}")

sorted_symbols_dict = dict(sorted(symbol_dict.items()))

for key, value in sorted_symbols_dict.items():
    #print(f"key: {key} - value: {value}")
    print(value, end="")