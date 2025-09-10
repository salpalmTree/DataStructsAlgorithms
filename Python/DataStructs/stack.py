class Stack:
    def __init__(self):
        self._array = []

    def is_empty(self):
        if len(self._array) == 0:
            return True
        else:
            return False

    def peek(self): 
        if not self.is_empty():
            print("Taking a peek...")
            return self._array[-1]
        else:
            print("Stack is empty")

    def push(self, item):
        print(f"Now pushing {item} to stack...")
        self._array.append(item)

    def pop(self): 
        if not self.is_empty():
            print(f"Now popping {self._array[-1]}...")
            return self._array.pop()
        else:
            print("Stack is empty")

S = Stack()

for i in range(5):
    S.push(i)

print()

print(S.peek())

print()
for i in range(10):
    print(S.pop())
