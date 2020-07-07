# BackUp

简单的打包备份脚本

```python
import zipfile
import os
import time

source_dir = './testfiles'

target_dir = './targetdir'

today = target_dir + os.sep + \
         time.strftime('%Y%m%d')

now = time.strftime('%H%M%S')

comment = input('Enter a comment --> ')

if len(comment) == 0:
    target = today + os.sep + now + '.zip'
else:
    target = today + os.sep + now + '_' +\
                comment.replace(' ', '_') + '.zip'

if not os.path.exists(target_dir):
    os.mkdir(target_dir)

if not os.path.exists(today):
    os.mkdir(today)
    print('Successfully created directory', today)

zippedfile = zipfile.ZipFile(target,'w')

print('Running:')
for file in os.listdir(source_dir):
    curfile = source_dir + os.sep + file
    print("\tadding {0}".format(curfile))
    zippedfile.write(curfile)

if len(zippedfile.namelist()) == len(os.listdir(source_dir)) \
        and zippedfile.testzip() is None:
    print('Successful backup to', target)
else:
    print('Backup FAILED')

zippedfile.close()

```

