# Pyhton

## 집합처리
내장함수 set 사용  
```python
a = [1, 2, 3]
b = [2, 3, 4]
aset = set(a)
bset = set(b)
print(aset & bset) #교집합 2, 3
print(aset | bset) #합집합 1, 2, 3 ,4
```