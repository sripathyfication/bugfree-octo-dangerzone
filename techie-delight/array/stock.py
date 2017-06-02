#/usr/bin/python

def when_to_trade(stocks):

    max_ = 0 
    max_diffi =0 
    bottom = stocks[0]
    diff = 0
    for i in range(1,len(stocks)):
        diff = diff + (stocks[i] - stocks[i-1])
        if diff > max_diffi:
            max_diffi = diff
            max_ = stocks[i]

        if stocks[i] < bottom:
            bottom = stocks[i]
            diff = 0

    return (max_ - max_diffi), max_


if __name__ == '__main__':
    stocks = [1,2,3,4,5,6,7,8,9]
    print stocks
    print when_to_trade(stocks)
    stocks = [1,2,3,4,5,2,3,4,5]
    print stocks
    print when_to_trade(stocks)
    stocks = [5,3,4,2,1,6,7,8,9]
    print stocks
    print when_to_trade(stocks)
