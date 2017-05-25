#/usr/bin/python
from stack import Stack

def is_balanced(exp):
    st = Stack()
    open_braces = ['{','(','[']
    close_braces = ['}',')',']']

    for c in exp:
        if c in open_braces:
            st.push(c)
        elif c in close_braces:
            tmp = st.pop()
            if (tmp is '{' and c is not '}') or (tmp is '[' and c is not ']') or (tmp is '(' and c
                    is not ')'):
                return False
    return st.is_empty()

if __name__=='__main__':
    exp1 = "{[{}{}]}[()]" 
    exp2 = "{{}{}}"
    exp3 = "[]{}()"
    exp4 = "{()}[)"
    exp5 = "{(})"
    print exp1
    print is_balanced(exp1)
    print exp2
    print is_balanced(exp2)
    print exp3
    print is_balanced(exp3)
    print exp4
    print is_balanced(exp4)
    print exp5
    print is_balanced(exp5)
    
