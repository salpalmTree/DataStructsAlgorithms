def binary_search(sorted_list, target):
    left_p = 0
    right_p = len(sorted_list)

    while left_p < right_p:
        mid_idx = (left_p + right_p) // 2
        mid_val = sorted_list[mid_idx]

        if target == mid_val:
            return mid_idx
        if target < mid_val:
            right_p = mid_idx
        if target > mid_val: 
            left_p = mid_idx + 1
    return -1

def binary_search_rec(sorted_list, left_p, right_p, target):
    if left_p >= right_p:
        return -1
    mid_idx = (left_p + right_p) // 2
    mid_val = sorted_list[mid_idx]

    if target == mid_val:
        return mid_idx
    if target < mid_val:
        return binary_search_rec(sorted_list, left_p, mid_idx, target)
    if target > mid_val:
        return binary_search_rec(sorted_list, mid_idx + 1, right_p, target)
    




my_list = [3, 6, 9, 12, 15, 18, 21, 24]
target = 18

print(f"Applying binary search (rec) on list: {my_list}")
found = binary_search_rec(my_list, 0, len(my_list), target)
if found > 0:
    print(f"Found {target} at index {found}")
else:
    print("Item not in list.")
