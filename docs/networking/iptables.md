# Iptables

    # apt-get install iptables

``iptables`` uses policy chains to decide the path of a packet to, from, through your system.

Tables
------

 - ``FILTER``: is the default table with chains ``INPUT``, ``FORWARD`` and ``OUTPUT``
 - ``NAT``: used to translate the packet source/destination field with chains ``PREROUTING``, ``OUTPUT`` and ``POSTROUTING``
 - ``MANGLE``: packet alteration with chains ``INPUT``, ``FORWARD``, ``POSTROUTING``, ``PREROUTING`` and ``OUTPUT``
 - ``RAW``

Chains
------

 - ``INPUT``: for packet to local machine
 - ``FORWARD``: for packet destined to another net

Jumps
-----

 - http://www.faqs.org/docs/iptables/targets.html

