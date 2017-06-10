#/usr/bin/python

'''
    A simple python program demonstrating a producer consumer type program
    
    Main idea:
        Dont use locks, use conditions.

        if we used a lock, the consumer could acquire a lock when the queue is empty because
        the producer didn't get a chance to run, which would cause it to access an illegal
        queue index.

        Instead, if we used a condition, if the queue is empty in the consumer, we wait.
        The producer would get a chance to run at some point, produce something and 
        notify the consumer threads.
'''

from threading import Thread,Lock,Condition
import time
import random

queue = []
lock = Lock()
condition = Condition()    

class Producer(Thread):
    def run(self):
        print "In producer"
        global queue 
        nums = range(10)
        while True:
            num = random.choice(nums)
            print "produced " + str(num)
            condition.acquire()
            queue.append(num)
            condition.notify()
            condition.release()
            time.sleep(random.random())

class Consumer(Thread):
    def run(self):
        global queue
        while True:
            condition.acquire()
            if not queue:
                print "Queue is empty.. going to wait.. zzz"
                condition.wait()
                print "Got something.."
            num = queue.pop(0)
            condition.release()
            print " CONSUMING... " + str(num)
            time.sleep(random.random())


if __name__ == '__main__':
    producer = Producer()
    consumer = Consumer()
    producer.start()
    consumer.start()
