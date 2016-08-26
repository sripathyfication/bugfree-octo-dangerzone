#!/usr/bin/env python


class bt:
      val
      left
      right
      def __init__(value):
          val = value
          left = None
          right = None

      def add_left(bt):
          left = bt
      def add_right(bt):
          right = bt

def print_bt(bt):

def create_bst(n):
    a = bt(1)
    b = bt(2)
    c = bt(3)
    a.add_left(b)
    a.add_right(c)


def main():
    n = raw_input("Enter the number of nodes in the binary tree")
    print n
    create_bst(n)

if __name__=='__main__':
    main()
