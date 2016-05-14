import random

n=10000
k=1500
ls = []
#a = n/100
#k = a/3
print n, k
while(len(ls)!=n):
	num = random.randint(0,100000)
	if (num not in ls):
		ls.append(num)
ls.sort()
#ls = list(set(ls))
#size = len(ls)
#print size
for i in ls:
	print i	 
