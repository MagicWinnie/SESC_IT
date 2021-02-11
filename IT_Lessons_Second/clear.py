import os

files = list(filter(lambda x: os.path.isfile(x), os.listdir('.')))

white_list = ['cpp', 'c', 'txt', 'dat', 'json']

for f in files:
    if f.split('.')[-1] not in white_list:
        os.remove(f)
