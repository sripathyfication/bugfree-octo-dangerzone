#!/usr/bin/env python
import sys
import os
import pprint
from datetime import datetime as dt
import collections
import argparse

#
# What this script does?
#
# 1. Decodes csco_hai_intf.log and saves it in intf.log
# 2. Ask for l2::Vlan, l2::interface, l3::interface, l2::Portgroup, l3::Vrf, etc,
# 3. decodes fwk, intf.log and gives the sequence of events from a given timestamp
# 4. decode eltmc logs
# 5. intersperse eltmc logs and sdk logs based on timestamp
# 6. log into to switch and do all of this.
#


class log_debugger:
    log_lists = [[]]
    time_dict = {}
    severity_dict = {}
    event_dict = {}
    log_group = "intf" # logging group of interest
    dump_to_file = False # flag controlling whether or not dump debug output to tmp file
    dump_ = None # file to dump debug outputs
    dlog_ = None # decoded file namee
    sw_f_ = None # log file from switch
    f_ = None # file handle to be worked upon
    from_ = ""
    to_ = ""
    groups = { "intf": "csco_hai_sb255_svc2_wk0_intf.log",
               "rtg": "csco_hai_sb255_svc2_wk0_rtg.log",
               "ep" : "csco_hai_sb255_svc2_wk0_ep.log",
             }
    tmp_g =  {
               "csco_hai_sb255_svc2_wk0_intf.log" : "intf.log",
               "csco_hai_sb255_svc2_wk0_rtg.log" : "rtg.log",
               "csco_hai_sb255_svc2_wk0_ep.log" : "ep.log",
             }

    def __init__(self,lg_,tf_,f_):
        self.log_group = lg_
        self.dump_to_file = tf_
        self.sw_f_ = self.groups[self.log_group] 

        # decode this file and dump to another temp file
        cmd = "cat " + self.sw_f_ + " | log_decode > " + self.tmp_g[self.sw_f_]
        os.system(cmd)
        self.dlog_ = self.tmp_g[self.sw_f_]
        self.extract_log_lists()
        self.extract_timestamps()
        self.extract_severity()
         #self.extract_events()
        
    # Extract funtions
    def extract_timestamps(self):
        # find the first '['
        with open(self.dlog_, "r") as self.f_:
            for line in self.f_:  
                time_ =  line.find('[') 
                date_ = dt.strptime(line[:time_-1],'%b %d %Y %Z %H:%M:%S.%f')
                self.time_dict[date_] = line[time_+30:]

    # Extract funtions
    def extract_severity(self):
        # find the first '['
        with open(self.dlog_, "r") as self.f_:
            for line in self.f_:  
                b_ = line.find('[') 
                e_ = line.find(']')
                sev_ = line[b_+1:e_]
                if self.severity_dict.has_key(sev_):
                   self.severity_dict[sev_].add(line[:b_] + ' ' + line[e_+25:])
                else:           
                   self.severity_dict[sev_] = set()
                   self.severity_dict[sev_].add(line[:b_] + ' ' + line[e_+25:]) 

    def display_timestamp(self,from_,to_):
        from_date_ = dt.strptime(str(from_),'%b %d %Y %Z %H:%M:%S')
        to_date_ = dt.strptime(str(to_),'%b %d %Y %Z %H:%M:%S')

        ordered_time_dict = collections.OrderedDict(sorted(self.time_dict.items()))
        time_scan_ = ordered_time_dict.iteritems()

        for start_,log_ in time_scan_:
            if (start_ >= from_date_) and (start_ <= to_date_):
               print str(start_) + " : " + str(log_.rstrip('\n'))

    def display_severity(self,sev):
        if self.severity_dict.has_key(sev):
           for l in self.severity_dict[sev]: 
               string = sev + ' : ' +  str(l).rstrip('\n') 
               print string 

def main():
    # Setup the parser
    parser = argparse.ArgumentParser()
    parser.add_argument("-s",help="switch ip", required=True)
    parser.add_argument("-g",help="logs group", required=True)
    parser.add_argument("-u",help="username", required=True)
    parser.add_argument("--to_file",help="dump to file tmp.log")
    parser.add_argument("--fr_time",help="from timestamp",nargs="+")
    parser.add_argument("--to_time",help="to timestamp",nargs="+")
    parser.add_argument("--gpd",help="dump all global pd logs")
    parser.add_argument("--apd",help="dump all asic pd logs")
    parser.add_argument("--events",help="dump all event history logs")
    parser.add_argument("--sev",help="dump all logs based on severity level")

    # Parse the args
    args = parser.parse_args()

    # Do stuff
    f_got_logs = False
    if args.s is not None and args.u is not None:
       cmd = "scp " + args.u + "@" + args.s + ":/tmp/logs/csco* ."
       os.system("echo " + cmd)
       os.system(cmd)
       f_got_logs = True

    # handle any error in fetching logs
    if f_got_logs is not True:
       os.system("echo interface_log.py: encountered an error while fetching logs!")
       parser.print_help()
       sys.exit(0)
           
    # No errors, proceed to extract different information from logs based on logs group
    d_o = log_debugger(args.g,args.to_file,None)

    if args.fr_time is not None and args.to_time is not None:
       f = ''
       t = ''
       #from and to times come in as lists, convert to strings
       for i in range(0,len(args.fr_time)):
           f += args.fr_time[i] + ' ' 
       for j in range(0,len(args.to_time)):
           t += args.to_time[j] + ' ' 
       d_o.display_timestamp(f.rstrip(' '),t.rstrip(' '))

    if args.sev is not None:
       d_o.display_severity(args.sev)
        
if __name__=='__main__':
    main()
