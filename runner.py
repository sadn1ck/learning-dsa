#! /usr/bin/python3

import sys
import os

file = sys.argv[1:]
filepath = " ".join(file)

if filepath[-3:].lower() == "cpp":
    print("$ Building ")
    os.system("g++ -std=c++17 "+filepath+" -o "+filepath[:-3]+"out")
    print("$ Executing ")
    os.system(filepath[:-3]+"out")

elif filepath[-2:].lower() == "kt":
    print("$ Building ")
    os.system("kotlinc "+filepath+" -include-runtime -d "+filepath[:-2]+"jar")
    print("$ Executing ")
    os.system("java -jar "+filepath[:-2]+"jar")

elif filepath[-2:].lower() == "py":
    print("$ Running ")
    os.system("python3 "+filepath)

else:
    print("$ Use good languages man")
