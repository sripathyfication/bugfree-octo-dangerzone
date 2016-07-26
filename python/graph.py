#!/usr/bin/env python
# A simple graph class, 
# a dictionary keyed on nodes, giving a list of edges
#
# methods:
#   1. Find a path
#   2. Find all paths.
#   3. Shortest path.
#   4. bf search
#   5. df search.
#
# Author: Sripathy Ramaswamy
# 07/25/2016

import sys

class Graph:
    name = ''
    graph = {}
    def __init__(self, g_name):
        self.name = g_name

    def add_node(self,node):
        self.graph[node] = []

    def show_graph(self):
        print ' Graph: ' + self.name
        print '--------------------'
        for node in self.graph.keys():
            graph_str =  node + '-->'
            for value in self.graph[node]:
                 graph_str = graph_str + ' : ' + value
            print graph_str
        print '--------------------'

    def add_edge(self,key,edges):
        self.graph[key] = edges

    def find_path(self, from_, to_, path=[]):
        path = path + [from_]
        if from_ == to_:
            return path

        if not self.graph.has_key(from_):
            return None 

        for node in self.graph[from_]:
            if node not in path:
                newpath = self.find_path(node,to_, path)
                if newpath: return newpath
        return None    

    def most_popular(self):
        weight = {} 
        friend_cnt = 0
        for person in self.graph.keys(): 
            for friends in self.graph[person]:
                friend_cnt = friend_cnt  + 1
            weight[person] = friend_cnt
            friend_cnt = 0

        max_ = 0
        for node in weight:
            if weight[node] > max_:
                most_popular_ = node
                max_ = weight[node]

        return most_popular_        


def main():
    x = Graph('People')

    x.add_node('Sripathy')
    x.add_node('Abhijit')
    x.add_node('Shrikanth')
    x.add_node('Fazil')
    x.add_node('Kapil')
    x.add_node('Jay')
    x.add_edge('Sripathy',['Jay','Abhijit','Shrikanth'])
    x.add_edge('Shrikanth',['Abhijit','Sripathy'])
    x.add_edge('Abhijit',['Fazil', 'Kapil', 'Sripathy', 'Shrikanth'])
    x.add_edge('Kapil', ['Fazil','Abhijit'])
    x.add_edge('Fazil', ['Kapil','Abhijit'])
    x.add_edge('Jay',['Sripathy'])

    x.show_graph()

    from_ = 'Jay'
    to_ = 'Abhijit'
    print ' '
    print ' finding a path from ' + from_ + ' to ' + to_ 
    path = x.find_path(from_, to_)
    print path

    most_popular_ = x.most_popular()
    print ' '
    print 'Most popular person is ' + most_popular_


if __name__=='__main__':
    main()

