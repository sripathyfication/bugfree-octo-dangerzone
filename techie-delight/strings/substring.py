#/usr/bin/python

def _adjust(main,len_):
    end_ = main[:len_-1]
    start_ = main[len_-1:]
    return  start_ + end_

def _check_match(sub, main):
    for c in sub:
        if c not in main:
            return False
    if len(sub) > len(main):
        return False

    if sub[len(sub) - 1] is not main[len(sub) - 1]:
            main = _adjust(main,len(sub))
            print main
            print sub
            _check_match(sub,main)
    else:
        return True
        
if __name__ == '__main__':
    main = "ksadkfhfasjssfihashripathysxkhrekaxkhrekaxkhrekaxkhrekaxkhrekaxkhrekaxkhrekaxkhrekaxkhrekaxkhrekaxkhreka"
    sub = "srip"
    print main
    print sub
    if _check_match(sub,main) is True:
        print "call is_substring"
    else:        
        print "not a substring"

    main = "tinku"
    sub = "srip"
    print main
    print sub
    if _check_match(sub,main) is True:
        print "call is_substring"
    else:        
        print "not a substring"

    main = "constantinople"
    sub = "nop"
    print main
    print sub
    if _check_match(sub,main) is True:
        print "call is_substring"
    else:        
        print "not a substring"
