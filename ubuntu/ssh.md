SSH 설정
--
# 서버 설치
sudo apt install openssh-server

# 클라이언트 설치
sudo apt-get install ssh

# 서버 설정 파일 편집
sudo vim /etc/ssh/sshd_config

# 재시작
service ssh restart
