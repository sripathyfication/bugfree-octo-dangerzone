#/usr/bin/python


class Stack:
    def __init__(self):
        self.storage = []
        self.top = 0
        self.empty = True

    def is_empty(self):
        return self.empty

    def get_top(self):
        return self.storage[self.top - 1]

    def push(self, element):
        self.storage.insert(self.top, element)
        self.top = self.top + 1    
        self.empty = False 

    def pop(self):
        if self.empty is False:
            element = self.storage.pop(self.top -1)
            self.top = self.top -1
            if self.top is 0:
                self.empty = True
            return element
        else:
            print "Stack is empty"

    def flush(self):
        for i in range(0, len(self.storage) -1):
            self.storage.pop()

    def print_stack(self):
        print "STACK"
        print "-----"
        for element in self.storage:
            print str(element) + ' '     
        print "-----"

# Test Drive        
if __name__ == '__main__':
    
    x = Stack()
    x.push('sripathy')
    x.push('shrikanth')
    x.push('rena')
    x.push('dad')
    x.push('mom')

    x.print_stack()
    print "poping... " + str(x.pop())
    print "poping... " + str(x.pop())
    print "poping... " + str(x.pop())
    x.print_stack()

