def fibo(n):
    memo={0:0,1:1}
    def f(n): 
        if n not in memo:
            memo[n]= f(n-1)+f(n-2)
        return memo[n]
        
    return f(n)
        
print(fibo(50))
print(fibo(1))
print(fibo(5))