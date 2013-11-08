HIIDeS
======

Hybrid Intelligent Intrusion Detection System using Genetic algorithm to optimize rulebase.


GaLib - C++ library for genetic algorithm
libPcap - packet capture library to sniff data out of network  


ABSTRACT
--------


The word ‘Hybrid’ in HIIDeS stands for a combination of a network based and host based intrusion detection system. A host-based IDS monitors file and process activities related to a software environment associated with a specific host. In HIIDesS, this is implemented as a separate utility which keeps track of the SHA-1 hash of all files and tracks all changes based on changes in the hash. A set of rules decides if any changes to a file can be classified as a threat or not. Rules are customizable. HIIDeS is a passive system which means that it does not prevent the activity from occurring; instead the activity is reported to system administrator via logs or email.
A network based IDS takes all raw packets passing through wire in promiscuous mode as input data and analyses it to detect anomalies. Packets are copied from the wire using a sniffer on interface and then passed through a threat detection engine which uses pattern matching module to compare it with a rule base (separate from what mentioned for host based) to detect threats. The primary aspect of this project is that the rule base is self learning and adapting. For this purpose, we uses genetic algorithm with a standard set of rules as initial population. Over generations, the algorithm adapts and ‘learns’ forming a rule base suited for that particular network. A new crossover function is introduced called ‘Netcross’ written specifically for a typical network environment.
