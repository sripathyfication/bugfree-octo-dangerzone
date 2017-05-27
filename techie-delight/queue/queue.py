#/usr/bin/python
#
# Queue operates on First in first out.
#
# So what went in first comes out first.
#
# supports 2 operations enqueue, dequeue
#
# enqueue adds an element to the rear of the queue
# dequeue removes an element from the front of the queue. 
#

class Queue:
    def __init__(self):
        self.list = []
        self.front = 0
        self.rear = 0
        
    def enqueue(self, value):
        self.list.insert(self.rear,value)
        self.rear = self.rear + 1
         
    def dequeue(self):
        element = self.list.pop(self.front)
        # now rearrange
        return element

    def is_empty(self):
        if len(self.list) is 0:
            return True
        else:    
            return False
    
    def print_queue(self):
        print " -- Queue -- "
        for i in self.list:
            print i        
        print " -- End -- "



if __name__ == '__main__':
    q = Queue()

    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(3)
    q.enqueue(2)


    q.print_queue()


    print " dequeue --> " + str(q.dequeue())
    print " dequeue --> " + str(q.dequeue())
    print " dequeue --> " + str(q.dequeue())

    q.print_queue()
