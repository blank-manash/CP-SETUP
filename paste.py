#!/usr/bin/python
import pyperclip as pp
f = open("input.txt", "w")
t = pp.paste()
f.write(t)
f.close()
