samba 설정
--
# 설치
```bash
sudo apt install samba
```

# 설정
```bash
sudo vi /etc/samba/smb.conf
```

# 주요 설정 
```ini
security = [share|user]

[share]
  comment = Share Directories
  path = #[설정할 경로]
  read only = no
  guest = ok
```
