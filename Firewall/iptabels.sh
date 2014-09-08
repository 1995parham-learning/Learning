#!/bin/bash

IPTABLES=/sbin/iptables
MODPROBE=/sbin/modprobe
INT_NET=192.168.1.0/24
INT_IF=eth0
EXT_IF=eth1

### flush existing rules and set chain policy setting to DROP
echo "[+] Flushing existing iptables rules..."
$IPTABLES -F
$IPTABLES -F -t nat
$IPTABLES -X
$IPTABLES -P INPUT DROP
$IPTABLES -P OUTPUT DROP
$IPTABLES -P FORWARD DROP

### load connection-tracking modules
$MODPROBE ip_conntrack
$MODPROBE iptable_nat
$MODPROBE ip_conntrack_ftp
$MODPROBE ip_nat_ftp

###### INPUT chain ######
echo "[+] Setting up INPUT chain..."
### state tracking rules
$IPTABLES -A INPUT -m state --state INVALID -j LOG --log-prefix "DROP INVALID" --log-ip-options --log-tcp-options
$IPTABLES -A INPUT -m state --state INVALID -j DROP
$IPTABLES -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
### anti-spoofing rules
$IPTABLES -A INPUT -i $INT_IF -s !$INT_NET -j LOG --log-prefix "SPOOFED PKT"
$IPTABLES -A INPUT -i $INT_IF -s !$INT_NET -j DROP
### ACCEPT rules
$IPTABLES -A INPUT -i $INT_IF -p tcp -s $INT_NET --dport 22 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A INPUT -p icmp --icmp-type "echo-request" -j ACCEPT
### default INPUT LOG rule
$IPTABLES -A INPUT -i !lo -j LOG --log-prefix "DROP" --log-ip-options --log-tcp-options

###### OUTPUT chain ######
echo "[+] Setting up OUTPUT chain..."
### state tracking rules
$IPTABLES -A OUTPUT -m state --state INVALID -j LOG --log-prefix "DROP INVALID" --log-ip-options --log-tcp-options
$IPTABLES -A OUTPUT -m state --state INVALID -j DROP
$IPTABLES -A OUTPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
### ACCEPT rules for allowing connections out
$IPTABLES -A OUTPUT -p tcp --dport 21 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p tcp --dport 22 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p tcp --dport 25 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p tcp --dport 43 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p tcp --dport 80 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p tcp --dport 443 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p tcp --dport 4321 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p udp --dport 53 -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -p icmp --icmp-type "echo-request" -j ACCEPT
### default OUTPUT LOG rule
$IPTABLES -A OUTPUT -o !lo -j LOG --log-prefix "DROP" --log-ip-options --log-tcp-options

###### FORWARD chain ######
echo "[+] Setting up FORWARD chain ..."
### state tracking rules
$IPTABLES -A FORWARD -m state --state INVALID -j LOG --log-prefix "DROP INVALID" --log-ip-options --log-tcp-options
$IPTABLES -A FORWARD -m state --state INVALID -j DROP
$IPTABLES -A FORWARD -m state --state ESTABLISHED,RELATED -j ACCEPT
### anti-spoofing rules
$IPTABLES -A FORWARD -i $INT_IF -s !$INT_NET -j LOG --log-prefix "SPOOFED PKT"
$IPTABLES -A FORWARD -i $INT_IF -s !$INT_NET -j DROP
### ACCEPT rules
$IPTABLES -A FORWARD -i $INT_IF -p tcp -s $INT_NET --dport 21 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -i $INT_IF -p tcp -s $INT_NET --dport 22 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -i $INT_IF -p tcp -s $INT_NET --dport 25 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -i $INT_IF -p tcp -s $INT_NET --dport 43 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -i $INT_IF -p tcp -s $INT_NET --dport 4321 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -p tcp --dport 80 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -p tcp --dport 443 --syn -m state --state NEW -j ACCEPT
$IPTABLES -A FORWARD -p udp --dport 53 --syn -m state --state NEW -j ACCEPT
$IPTBALES -A FORWARD -p icmp --icmp-type "echo-request" -j ACCEPT
### default log rule
$IPTABLES -A FORWARD -i !lo -j LOG --log-prefix "DROP" --log-ip-options --log-tcp-options

###### NAT rules ######
echo "[+] Setting up NAT rules..."
$IPTABLES -t nat -A PREROUTING -p tcp -i $EXT_IF --dport 80 -j DNAT --to 192.168.1.2:80
$IPTABLES -t nat -A PREROUTING -p tcp -i $EXT_IF --dport 443 -j DNAT --to 192.168.1.2:443
$IPTABLES -t nat -A PREROUTING -p udp -i $EXT_IF --dport 53 -j DNAT --to 192.168.1.1:53
$IPTABLES -t nat -A POSTROUTING -s $INT_NET -o $EXT_IF -j MASQUERADE

###### forwarding ######
echo "[+] Enabling IP forwarding..."
echo 1 > /proc/sys/net/ipv4/ip_forward
