import re
import sys

"""
Quick and dirty script to update the values of a given symbol file with a fixed offset per symbol.
Argument 1: Filename to read from
Argument 2: Fixed hex number of bytes to offset. Additions only so far.
If you want to write it to a new file just add > new_file.txt

Example Usage: python3 symbol_updater.py file.txt 0x1234
"""

file_name = sys.argv[1]

with open(file_name, 'r') as f:
    for line in f:
        match = re.search(r"D_([0-9a-fA-F]*) = 0x([0-9a-fA-F]*);(.*)", line)
        if match:
            symbol_name = match.group(1)
            address = match.group(2)
            comments = match.group(3)
            updated_address = hex(int(address, 16)).upper()
            # print(f"symbol_name: {symbol_name}")
            # print(f"address: {address}")
            # print(f"comments: {comments}")
            # print(f"updated_address: {updated_address}")
            # print(f"new line: {symbol_name} = {updated_address};{comments}")
            if (symbol_name != address):
                print(f"{symbol_name} = {updated_address};{comments}")