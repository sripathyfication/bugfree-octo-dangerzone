#/usr/bin/python

'''
    A simple tcp server/client application

    socket is an ipaddress/port.

    client operations

    create socket
    connect(server_address:ip,port)
    sendall
    recv
    close
'''

import socket
import sys


class Client:
    def __init__(self,ip_address,port):
        self.ip_address = ip_address
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_address = (self.ip_address,self.port)
        self.sock.connect(self.server_address)
    
    def start(self):
            try:
                message = " what's up doc?"
                print >>sys.stderr,".. message to be sent to server ::", message
                self.sock.sendall(message)
                amount_recvd = 0
                amount_expected = len(message)

                while amount_recvd < amount_expected:
                    data = self.sock.recv(16)
                    print >>sys.stderr, " .. got data ::", data
                    amount_recvd += len(data)

            finally:
                self.sock.close()


if __name__ == '__main__':
    client = Client('localhost',10001)
    client.start()
