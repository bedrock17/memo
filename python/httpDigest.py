import hashlib

m = hashlib.md5()
m.update(b"admin:nadatel@nadatel.com:1111")
# m.update("")
ha1 = m.hexdigest()

m.update(b"post:1111")
ha2 = m.hexdigest()

# s = str(s).replace("\\x", " ")

print(ha1)