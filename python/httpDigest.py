import hashlib

def get_md5(data):
    if isinstance(data, str):
        data = data.encode('utf-8')
    return hashlib.md5(data).hexdigest()

# m.update("")
# s = str(s).replace("\\x", " ")

username = "admin"
realm = "nadatel@nadatel.com"
password = "password1111"
method = "POST"
uri = "/index.html"

ha1 = get_md5(f"{username}:{realm}:{password}")
ha2 = get_md5(f"{method}:{uri}")

print(f"HA1: {ha1}")
print(f"HA2: {ha2}")
