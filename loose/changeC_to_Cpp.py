from os import walk
import os

path = "/home/danilocsm/Dropbox/Computação/EstruturaDeDados/EstruturaDeDados2/"
for root,dirs,files in walk(path):

	for i in range(0,len(dirs)):

		subpath = path+dirs[i]
		print("Lendo diretório {0}".format(dirs[i]))

		for sub_dir_path,sub_dir,sub_dir_files in walk(subpath):

			#print(sub_dir_files)
			for j in range(0,len(sub_dir_files)):
				#print(sub_dir_files[j])
				if(sub_dir_files[j].find(".c")!= -1):
					aux = sub_dir_files[j].replace(".c",".cpp")
					new = subpath + '/' +aux
					old = subpath + '/' +sub_dir_files[j]
					os.rename(old,new)

			break
