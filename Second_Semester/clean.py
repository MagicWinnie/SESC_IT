import os
FILES = os.listdir('.')
TO_DELETE = ['o', 'exe']

for f in FILES:
    if f.split('.')[-1] in TO_DELETE:
        os.remove(f)

