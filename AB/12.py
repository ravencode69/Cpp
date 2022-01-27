PI = 3.14
radius = float(input('Please Enter the Radius of a Cylinder: '))
height = float(input('Please Enter the Height of a Cylinder: '))

sa = 2 * PI * radius * (radius + height)
Volume = PI * radius * radius * height
L = 2 * PI * radius * height
T = PI * radius * radius

print("\n The Surface area of a Cylinder = %.2f" %sa)
print(" The Volume of a Cylinder = %.2f" %Volume)
print(" Lateral Surface Area of a Cylinder = %.2f" %L)
print(" Top OR Bottom Surface Area of a Cylinder = %.2f" %T)
