class ans:
    def __init__(self, length):
        self.now = 0
        self.length = length

    def __iter__(self):
        return self

    def __next__(self):
        if self.now >= self.length-1:
            raise StopIteration

        self.now += 1
        return self.now ** 2


a = int(input())
square = ans(a)

for sq in square:
    print(sq)


def Naive(num_arr, pair_sum):
    # first element
    for i in range(len(num_arr) - 1):
        # second element
        for j in range(i + 1, len(num_arr)):
            if num_arr[i] + num_arr[j] == pair_sum:
                print(i, j)


L = [1, 2, 3, 4, 5, 6, 7, 8, 9]
pair_sum = int(input())
Naive(L, pair_sum)


class Student:

    def __init__(self, student_id, student_name, student_marks):
        self.student_id = student_id
        self.student_name = student_name
        self.student_marks = student_marks

    def display(self):
        print("Name   : ", self.student_name)
        print("RollNo : ", self.student_id)
        print("Marks1 : ", self.student_marks)

    def __add__(self, ob):
        return self.student_marks + ob.student_marks


s1 = Student(1, "Akki", 90)
s1.display()
s2 = Student(1, "SalmonBhai", 70)
s2.display()

print(s1+s2)
