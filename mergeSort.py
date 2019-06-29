# Merge Sort -> Python Source Code

# Chen Tang, 2019

def mergeTwoParts(a, idx_low, idx_mid, idx_high) :
#{
	tmp = []

	i = idx_low
	j = idx_mid + 1
	
	while i <= idx_mid and j <= idx_high :
		if a[i] < a[j] :
			tmp.append(a[i])
			i += 1
		else :
			tmp.append(a[j])
			j += 1
			
	while i <= idx_mid :
		tmp.append(a[i])
		i += 1
		
	while j <= idx_high :
		tmp.append(a[j])
		j += 1
		
	for i in range(len(tmp)) :
		a[i+idx_low] = tmp[i]
	
	del tmp
	
	return
#}

def mergeSortKernel(a, idx_low, idx_high) :
#{
	if idx_low < idx_high :
	
		idx_mid = (idx_low + idx_high) // 2
		
		mergeSortKernel(a, idx_low, idx_mid)
		mergeSortKernel(a, idx_mid+1, idx_high)
		
		mergeTwoParts(a, idx_low, idx_mid, idx_high)
	
	return
#}

def mergeSort(a) :
#{
	n = len(a)
	
	if n < 1 :
		return
	else :
		mergeSortKernel(a, 0, n-1)

	return
#}

def main() :
#{
	n = 100

	a = []
	
	print("\n\n\nInput data:", end="\n\n\n")
	
	for i in range(n) :
		a.append(n-i)
		print(a[i], end=", ")
		
	print(end="\n\n\n")
	
	mergeSort(a)
	
	print("n =", n, end="\n\n\n")
	print("After mergeSort, ", end="\n\n\n")
	
	for i in range(n) :
		print(a[i], end=", ")
		
	print(end="\n\n\n")
	
	del a
	
	return
#}

if __name__ == '__main__' :
	main()

