
# netplan
우분투에서 네트워크 설정하는 방법 중 하나

성정 파일 편집 (예시 파일 명)

```bash 
sudo vi /etc/netplan/01-netcfg.yaml
```

DHCP
```yaml
network:
  version: 2
  renderer: networkd
  ethernets:
    <인터페이스_이름>:
      dhcp4: true
```
STATIC
```yaml
network:
  version: 2
  renderer: networkd
  ethernets:
    <인터페이스_이름>:
      addresses:
        - 192.168.1.100/24
      gateway4: 192.168.1.1
      nameservers:
        addresses:
          - 8.8.8.8
          - 8.8.4.4
```

적용

```bash
sudo netplan apply
```

