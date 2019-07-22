import time
from datetime import datetime, timedelta


startTime = datetime(2019, 7, 2, 0, 0, 0)
endTime = datetime(2022, 5, 1, 0, 0, 0)

totTime = endTime - startTime
totTimeStamp = totTime.total_seconds()

print(startTime, endTime, datetime.now())


while True:
  now = datetime.now()
  leftTime = endTime - now

  nowTimeStamp = (now - startTime).total_seconds()

  print(leftTime, "(%d weeks)"%(leftTime.total_seconds() / (60 * 60 * 24 * 7)) , "%f%%"%(nowTimeStamp / totTimeStamp * 100))
  time.sleep(0.3)