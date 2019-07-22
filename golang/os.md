# OS 패키지 관련 사용법


## file 처리
```go
// open
file, err := os.Open("file.go") // For read access.
if err != nil {
	log.Fatal(err)
}

//닫기
defer file.close()

fileInfo, fierr := file.Stat()

if fierr != nil {
	return fierr
}

//read
data := make(fileInfo.Size())

//
```