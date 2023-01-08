from ctypes import *

f = CDLL("./main.so")
x = c_double(-20.0)
y = c_double(30.0)
z = c_double(13.0)
print(type(f))
f.connect()
f.generate_mycobot280pi.argtypes = [c_double, c_double, c_double]
res = c_double(f.generate_mycobot280pi(x, y, z))
print("done")