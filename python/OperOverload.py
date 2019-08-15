# 연산자 오버로딩 샘플코드
# __add__, __mul__ 같은 미리정의된 이름으로 오버로딩 가능.

from typing import *

class pos:
  def __init__(self, x :int, y :int):
    self.x :int = x
    self.y :int = y

  def __add__(self, p):
    return pos(self.x + p.x, self.y + p.y)


a = pos(1, 4)
b = pos(3, 5)

print((a+b).x, (a+b).y)