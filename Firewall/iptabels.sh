#!/bin/bash

IPTABLES=/sbin/iptables
MODPROBE=/sbin/modprobe
INT_NET=192.168.1.0/24
INT_IF=eth0

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
