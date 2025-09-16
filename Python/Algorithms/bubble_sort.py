def bubble_sort(a_list):
    length = len(a_list)
    for i in range(length - 1):
        for j in range((length - 1) - i):
            if a_list[j] > a_list[j + 1]:
                a_list[j], a_list[j + 1] = a_list[j + 1], a_list[j]


my_list = [6, 2, 7, 1, 9, 12, 5, 0]
print("List before sorting: ")
print(my_list)

bubble_sort(my_list) 

print("\nList after sorting: ")
print(my_list)
