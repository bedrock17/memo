# OS 패키지 관련 사용법


## file 처리
```go
// open
file, err := os.Open("file.go") // For read access.
if err != nil {
	log.Fatal(err)
}

//닫기
defer file.Close()

fileInfo, fierr := file.Stat()

if fierr != nil {
	return fierr
}

//read
data := make(fileInfo.Size())

n := file.Read(data)
```

## 파일이 있는지 확인
```go
if _, err := os.Stat(filePath); err == nil {
    // path/to/whatever exists
}
```

## 디렉토리 만들기
```go
os.Mkdir("dirname", 0700)
```