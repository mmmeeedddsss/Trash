import os
def cls():
    os.system(['clear','cls'][os.name == 'nt'])
	
def add_data( input ):
	with open('C:\Users\Mert\Desktop\Lol\Microsoft C\out.tx','a') as file:
		for c in range(0,len(input)):
			file.write( chr(ord(input[c]) - 7) )
		file.write("\n")
		

cls()
add_data( raw_input(">") )
while raw_input("Cont y/n") == 'y':
	cls()
	add_data(raw_input(">"))