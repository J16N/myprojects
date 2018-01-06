beg=int(raw_input("Enter the starting number: "))
end=int(raw_input("Enter the ending number: "))
if beg<0 or end<=0:
	print "Choose the range from increasing order of positive infinity."
else:
	print "So the prime numbers between %d and %d are as follows:" %(beg, end)
	for i in range(beg,(end+1)):
		factors=[]
		divisor=i-1
		while divisor>0:
			if i==1:
				factors.append(i)
				divisor-=1
			else:
				if i%divisor==0:
					factors.append(divisor)
					divisor-=1
				else:
					divisor-=1
		if len(factors)==1:
			print i
