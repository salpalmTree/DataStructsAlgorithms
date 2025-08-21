class node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class linked_list:
    def __init__(self):
        self.head = node()

    def insert(self, item):
        new_node = node(item)
        cur = self.head

        if cur is None:
            self.head = new_node
            return

        while cur:
            next = cur.next
            if not next:
                cur.next = new_node
            cur = next

    def length(self): 
        cur = self.head
        total = 0
        while cur.next is not None:
            total += 1
            cur = cur.next
        return total

    def display(self):
        cur = self.head
        while cur.next is not None:
            cur = cur.next
            print(f"{cur.data} ->", end=" ")
        print()

    def get(self, index):
        cur = self.head
        i = 0
        while cur.next is not None:
            cur = cur.next
            if i == index:
                return cur.data
            i += 1
        print("That index doesn't exist")
        return -999999

    def delete(self, item):
        succ = self.head
        while succ.next is not None:
            prev = succ
            succ = succ.next
            if succ.data == item:
                prev.next = succ.next
                del succ
                return
        print(f"Could not find {item} in the list.")

my_list = linked_list()
my_list.insert(3)
my_list.insert(4)
my_list.insert(5)
my_list.insert(6)
my_list.insert(7)
my_list.insert(8)
my_list.display()
print()

print("Accessing index 1...")
print(my_list.get(1))
print()

print("Deleting 7 from list")
my_list.delete(7)
my_list.display()
print()

print("Deleting 3 from list")
my_list.delete(3)
my_list.display()
print()
