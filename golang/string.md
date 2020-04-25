# 문자열 관련

## byte array to string
```go
s := string(byteArray[:])
```

## string to byte array
```go
s := "HelloWorld"
byteArray := []byte(s) //[72 101 108 108 111 87 111 114 108 100]
```

## strings 패키지

### 문자열이 포함되어있는지 검사
```go
strings.Contains("ABC", "BC") //true
strings.Contains("ABC", "AC") //false
```
### 문자열 카운팅
```go
strings.Count("123 12 123", "12") //3
```

### 문자열의 위치 구하기
```go
strings.Index("123", "23") // 1
```
