# just a python implementation of perfectnum.c :P

beg = int(raw_input("Enter the starting number: "))
end  =int(raw_input("Enter the ending number: "))

if beg < 0 or end < 0:
	print "Choose the range from a positive infinity."
else:
	print "So the perfect numbers between %d and %d are as follows:" % (beg, end)
	for i in range(beg, (end + 1)):
		factors=[]
		divisor = i - 1
		while divisor > 0:
			if i == 1:
				factors.append(i)
				divisor -= 1
			else:
				if i % divisor == 0:
					factors.append(divisor)
					divisor -= 1
				else:
					divisor -=1
		pernum = 0
		for j in factors:
			pernum += j
		if pernum == i:
			print pernum
