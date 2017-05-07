#!/usr/bin/python
import sys

'''
sorted array, find range.
'''
def bsearch(a,t,l):
	low = 0
	mid = (len(a) - 1)/ 2
	high = len(a) - 1 
	found = False

	if t < a[low] or t > a[high]:
		l[0] = -1
		l[1] = 1
		return

	while a[mid] is not t:
		if t > a[mid]:
			low = mid
			high = len(a) - 1
			mid = (low + high) /2 
		if t < a[mid]:
			low = 0
			high = mid
			mid = (low + high) /2 
	if a[mid] is t:
		# check if the next few elements
		found = True
		i = mid
		while a[i] is t:
			i = i +1
			
		l[0] = mid
		l[1] = i - 1

	return


def main():
	t = input("Enter the number to find\n")
	print "..looking for %d" % t
	a = [5,7,7,8,8,9]
	l = [0,0]
	bsearch(a,t,l)
	print a,t, l


if __name__ == '__main__':
    main()

