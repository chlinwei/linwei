安装所需软件:
yum install -y dhcp vsftpd tftp-server xinetd  syslinux 


dhcpd的配置如~/linwei/install_os/dhcpd.conf文件


tftp 目录下是引导文件:
cd /var/lib/tftpboot
cp /media/isolinux/* ./
cp /usr/share/syslinux/pxelinux.0 ./
mkdir pxelinux.cfg && cp ../isolinux.cfg ./default
在对default文件进行修改,修改后的文件如~/linwei/install_os/tftpboot/pxelinux.cfg/default



vsftp 的主目录下包含:iso源和ks文件
cp -a /media/*  /var/ftp
cd /var/ftp/pub && touch ks.cfg (ks.cfg这个文件如~linwei/install_os/ks/ks6.8.cfg)


xinetd对tftp的配置如~/linwei/install_os/xinetd_tftp


syslinux 主要包括引导程序pxelinux.0
