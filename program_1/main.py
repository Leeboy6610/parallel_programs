# Python Implementation
import time

def main():
	start_time = time.time()
	lineno = 0
	count = 0
	with open('Human_MtDNA.txt', 'r') as inF:
		for line in inF:
			lineno += 1
			if 'GAAAAT' in line:
					count += 1
					print 'Found in line ', lineno
			# else:
					# print 'Not Found in line ', lineno
		runtime = time.time() - start_time
		print count, 'Inputs found in', runtime, 'seconds!!!'
		inF.close()

main()
