#!/usr/bin/python
import binascii
import struct

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

print "Printing Little Endian " %(struct.pack('>I',ba[0:4]))
print "Printing Big Endian " %(struct.pack('>I',ba[0:4]))
print struct.unpack('4B', ba[0:4])
# print binascii.b2a_hex(binstr)

#def lt_2_big_end ( arg, 
