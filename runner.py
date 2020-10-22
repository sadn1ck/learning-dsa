#! /usr/bin/python3

import sys
import os

file = sys.argv[1:]
filepath = " ".join(file)

if filepath[-3:].lower() == "cpp":
    print("$ Building ")
    os.system("g++ "+filepath+" -o "+filepath[:-3]+"out")
    print("$ Executing ")
    os.system(filepath[:-3]+"out")
elif filepath[-2:].lower() == "py":
    print("$ Running ")
    os.system("python3 "+filepath)

else:
    print("$ Languages other than cpp or py not accounted for, sadly")
