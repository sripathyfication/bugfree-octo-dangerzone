from stack import Stack

close_braces = [')']

def is_duplicate(exp):
    st = Stack()
    pushed = False
    for c in exp:
        print c
        if c in close_braces and pushed is False:
            st.push(c)
            pushed = True
            continue
        if pushed is True and c not in close_braces:
           st.push(c)
        if pushed is True and c in close_braces:
            t = st.pop()
            if t in close_braces:
                return True
        if pushed is True and c is '(':
            # flush the stack
            st.flush()
            pushed = False

    return False     

if __name__ == '__main__':
    exp = "((x+y))"
    print exp
    print is_duplicate(exp)
    exp = "((x+y)+1)"
    print exp
    print is_duplicate(exp)
    exp = "((x+y) + ((y)))"
    print exp
    print is_duplicate(exp)
