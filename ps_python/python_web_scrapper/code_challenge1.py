def plus(a, b):
    return int(a) + int(b)

def minus(a, b):
    return int(a) - int(b)

def product(a, b):
    return int(a) * int(b)

def quotient(a, b):
    return int(a) / int(b)

def remainder(a, b):
    return int(a) % int(b)

def power(a, b):
    return int(a) ** int(b)

def negate(a):
    return -int(a)

def calculator(operation, a, b=0):
    if operation == "plus":
        result = plus(a, b)
    elif operation == "minus":
        result = minus(a, b)
    elif operation == "product":
        result = product(a, b)
    elif operation == "quotient":
        result = quotient(a, b)
    elif operation == "remainder":
        result = remainder(a, b)
    elif operation == "power":
        result = power(a, b)
    elif operation == "negate":
        result = negate(a)
    
    print(result)

def main():
    calculator("plus", 10, "5")
    calculator("minus", 10, 5)
    calculator("product", 10, 5)
    calculator("quotient", "10", 5)
    calculator("remainder", 10, 4)
    calculator("power", 10, 5)
    calculator("negate", 10)
    
if __name__ == "__main__":
    main()