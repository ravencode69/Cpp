def sumOfSeries(n):
    return sum([i*(i+1)/2 for i in range(1, n + 1)])

if _name_ == "_main_":
    n = 10
    print(sumOfSeries(n))