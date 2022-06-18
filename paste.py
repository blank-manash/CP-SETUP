#!/usr/bin/python
import pyperclip as pp
f = open("in.in", "w")
t = pp.paste()
f.write(t)
f.close()
