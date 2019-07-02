# samba 설정

## 설치
```bash
apt install samba
```

## 계정 설정
```bash
smbpasswd -a [계정명]
```

## 설정
```bash
vi /etc/samba/smb.conf
```

## 설정파일 계정 편집 예제
```conf
[sh]
comment = sh
path = /home/sh
valid users = sh
writeable = yes
create mask = 644
directory mask = 0755
```

## restart
/etc/init.d/smbd restart