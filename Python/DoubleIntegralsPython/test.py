def rectangular_double(f, a, b, c, d, n):
	hx = (b - a)/float(n)
	hy = (d - c)/float(n)
	result = 0
	for i in range(n):
		for j in range(n):
			xi = a + hx/2 + i*hx
			yj = c + hy/2 + j*hy
			result += hx*hy*f(xi,yj)
	return result

fxy = input("Enter your function: ")
f = lambda x,y:eval(fxy)
n = int(input("Enter the accuracy: "))
a = int(input("Enter a: "))
b = int(input("Enter b: "))
c = int(input("Enter c: "))
d = int(input("Enter d: "))
print(double_rect(f,g,a,b,c,d,n))