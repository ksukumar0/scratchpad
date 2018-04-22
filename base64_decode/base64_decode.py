#!/usr/bin/python
import binascii

#binstr=b"thisisunreadablebytes"

# Read from File
file = open("input_b64encoded.txt", "r") 
encoded = file.readline()

# Decode string
# encoded=binascii.b2a_base64(binstr)
# print encoded
decoded=binascii.a2b_base64(encoded)
# print "%s Length is :%d" %( decoded, len(decoded) )

ba=bytearray(decoded)
print("%s, Length is: %d" %(list(ba), len(ba)))

# print binascii.b2a_hex(binstr)
