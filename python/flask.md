
# Flask

## api 구성에 필요한 기본적인 내용
```py
from flask import Response

@app.route('/hello', methods = ['GET'])
def api_hello():
    data = {
        'hello'  : 'world',
        'number' : 3
    }
    js = json.dumps(data)

    resp = Response(js, status=200, mimetype='application/json')
    resp.headers['Link'] = 'http://luisrei.com'

    return resp

```
출처 : http://blog.luisrei.com/articles/flaskrest.html (Implementing a RESTful Web API with Python & Flask)