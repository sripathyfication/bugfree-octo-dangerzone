
#/usr/bin/python

# binary search implementation
#

def search(a_thing, in_things):
    if type(a_thing) is str:
        print "string"
    elif type(a_thing) is int:
        print "integer"
    elif type(a_thin) is float: 
        print "float"

if __name__ == '__main__':
    a_thing = 5
    in_things = [2,4,6,8,1,2,4,5]
    search(a_thing, in_things)
