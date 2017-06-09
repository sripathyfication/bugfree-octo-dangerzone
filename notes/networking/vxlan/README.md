--------------
What is VxLan:-
--------------

Source:-
http://www.cisco.com/c/en/us/products/collateral/switches/nexus-9000-series-switches/white-paper-c11-729383.html

VLAN is traditionally used in layer 2 networks. However, traditional VLAN has issues:

    1. Space ( 12 bits) - VLAN is defined by a space of 12 bits, limiting the total vlans in a
    network to 4096. In order to extend this we use vxlan (24 bits)

    2. VLAN uses Spanning tree protocol to eliminate loops in the underlying network. This makes
    half the link redundant thereby bringing down the total number of effective links.
    
