#清楚默认规则
iptables -F 
iptables -X
iptables -Z
iptables -t nat -F
iptables -t nat -X
iptables -t nat -Z

#filter表的默认规则
iptables -P INPUT DROP
iptables -P OUTPUT ACCEPT
iptables -P FORWARD DROP


#INPUT链的基本规则
iptables -A INPUT -m state --state RELATED,ESTABLISHED -j ACCEPT
iptables -A INPUT -m state --state INVALID -j ACCEPT
iptables -A INPUT -i lo -j ACCEPT


#FORWARD基本规则
iptables -A FORWARD -m state --state RELATED,ESTABLISHED -j ACCEPT
iptables -A FORWARD -m state --state INVALID -j ACCEPT


#icmp
iptables -A INPUT -p icmp --icmp-type any -s 192.168.200.0/24 -j ACCEPT


#sshd
iptables -A INPUT -p tcp -s 192.168.200.0/24 --dport 22 -j ACCEPT
iptables -A INPUT -p udp -s 192.168.200.0/24 --dport 22 -j ACCEPT


#nginx
iptables -A INPUT -p tcp -s 192.168.200.0/24 --dport 80 -j ACCEPT
iptables -A INPUT -p udp -s 192.168.200.0/24 --dport 80 -j ACCEPT


 #/usr/libexec/iptables/iptables.init save 
 service iptables save
 systemctl	restart iptables 
