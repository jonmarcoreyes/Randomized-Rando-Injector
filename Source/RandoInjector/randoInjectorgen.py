import random
import sys

Hex = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
cppFile = open("Main.cpp","w")

def randomHexer():
    randomHexVar1 = Hex[random.randrange(0,16)]
    randomHexVar2 = Hex[random.randrange(0,16)]
    cppFile.write(randomHexVar1 + randomHexVar2 + " \\\n") 
    
def header():
	headerFile = open("header.txt","r")
	for line in headerFile:
		cppFile.write(line)
		
def asmLines():
    cppFile.write("#define JUNKS \\\n")
    for x in range(0,200):
        cppFile.write('__asm _emit 0x')
        randomHexer()
			
def footer():
	footerFile = open("footer.txt","r")
	for line in footerFile:
		cppFile.write(line)
		
def main():
	header()
	asmLines()
	footer()
	cppFile.close()
	
if __name__ == "__main__":
    main()
