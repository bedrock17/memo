# NFS 설정

## 설치
```bash
apt-get install nfs-common nfs-kernel-server portmap
```

## 설정
```bash
vi /etc/exports
```

## 형식
[경로] [접근가능 IP] [옵션]  
예시: /home/test/tmp * rw

## 옵션
ro: readonly  
rw: read/write
