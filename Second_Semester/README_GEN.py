import os
import markdown

WHITE_LIST = ('cpp', 'c')

FILES = list(filter(lambda x: x.split('.')[-1] in WHITE_LIST, os.listdir('.')))

result = '# Second semester, 10th grade\n'

for k, f in enumerate(FILES):
    with open(f, 'r', encoding='utf-8') as inp:
        data = inp.readlines()
    temp = []
    i = 0
    while True:
        if data[i][:2] != '//':
            break
        else:
            if data[i][2] == ' ':
                temp.append(data[i][3:])
            else:
                temp.append(data[i][2:])
        i += 1
    temp = list(map(lambda x: x[0].capitalize() + x[1:], temp))
    temp = list(map(lambda x: x.replace('\n', ''), temp))
    temp_str = '. '.join(temp)
    if len(temp) == 0: temp_str += f.split('.')[0] + '.'
    elif temp_str[-1] != '.': temp_str += '.'
    result += "{}. [{}]({})\n".format(k + 1, temp_str, f)

with open("README.md", "w", encoding="utf-8", errors="xmlcharrefreplace") as output_file:
    output_file.write(markdown.markdown(result))
    