

# JSON


## 사용될 구조체

```golang
type memo struct {
	Title   string `json:"title"` // tag를 보고 key를 만든다.
	Content string `json:"content"`
}
```

```golang
	var data memo 
	err := json.Unmarshal(bytearaay, &data) // 바이트 배열을 구조체에 맞춰서 채워준다.

	if err != nil {
		fmt.Println(err)
		panic(err)
	}
	fmt.Println(data)

  //json 바이트 배열로 구조체를 변환한다.
  //key는 tag를 사용
	b, err := json.Marshal(data) 
	if err != nil {
		fmt.Println(err)
		panic(err)
  }
```
