import sys
import os

def cls():
    os.system(['clear','cls'][os.name == 'nt'])

cls()
with open('C:\Users\Mert\Desktop\Lol\Microsoft C\out.tx','r') as file:
	for line in file:
		i = 0
		for i in range( len(line)-1 ):
			sys.stdout.write( str(chr( ord(line[i]) + 7 )) )
		print ""
		
print("\n")
raw_input("Press Any Key to Exit...")
		
