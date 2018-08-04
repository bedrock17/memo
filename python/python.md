# Pyhton

## 집합처리
내장함수 set 사용  
set 은 중복을 제거해줌
```python
a = [1, 2, 3]
b = [2, 3, 4]
aset = set(a)
bset = set(b)
print(aset & bset) #교집합 2, 3
print(aset | bset) #합집합 1, 2, 3, 4
```
## 뒤집기
```py
s = "12345"
print(s[::-1]) #54321
```
## lambda
```py
f = lambda x: x**2
lst = [1,2,3]
lst=list(map(f,lst))
print(lst) #[1, 4, 9] 
```
## filter
인자로 들어온 함수의 결과가 참일 때 값만 골라냄
```py
lst = [1, 2, 3]
print(list(filter(lambda x: x < 2, lst))) # [1]
```
## 딕셔너리 키 확인
in 을 사용 있다면 True
```py
if 'key1' in dict.keys():
    print("있다")
else:
    print("없다")
```