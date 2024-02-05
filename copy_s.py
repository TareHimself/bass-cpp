import os
import sys
import shutil
files,dest = sys.argv[1:3]
#print(,dest)

for file in files.split(";"):
    file = os.path.normpath(file)
    dest_dir = os.path.normpath(os.path.join(dest,file.split(os.path.sep)[-1]))
    print(f"Copying [{file}] to [{dest_dir}]")
    shutil.copy(file,dest_dir)
