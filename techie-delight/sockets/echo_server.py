#/usr/bin/python

'''
    A simple tcp server/client application

    socket is an ipaddress/port.

    Server operations:

    create socket
    bind to serveraddress(ip,port)
    listen(1)
    recv
    sendall
    close
'''

import socket
import sys


class Server:
    def __init__(self,ip_address,port):
        print " Setting up tcp server.."
        self.ip_address = ip_address
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_address = (self.ip_address,self.port)
        self.sock.bind(self.server_address)
    
    def start(self):
        self.sock.listen(1)

        while True:
            print >>sys.stderr," waiting for a connection"
            connection,client_address = self.sock.accept()

            try:
                print sys.stderr," accepted connection from ", client_address
                while True:
                    data = connection.recv(16)
                    print >>sys.stderr, ".. got data::", data
                    if not data:
                        print >>sys.stderr, "..no data from client ", client_address
                        break
                    else:    
                        connection.sendall(data)
                        print >>sys.stderr, ".. sending data back"
                        break
            finally:
                connection.close()



if __name__ == '__main__':
    server = Server('localhost',10001)
    server.start()

            
