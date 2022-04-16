# HTTP
工作原理
## 消息结构
客户端请求信息
请求行  请求头部  空行    请求数据
请求方法" "URL" "协议版本"\r\n"
头部字段名:值"\r\n"
....
头部字段名:值"\r\n"
"\r\n"
请求数据

edj:
GET /hello.txt HTTP/1.1
User-Agent:cur1/7.16.3 libcur1/7.16.3 OpenSSL/0.9.71 zlib/1.2.3
Host:www.example.com
Accept-Language:en,mi

服务器响应消息
状态行  消息报头  空行  响应正文

## 请求方式
GET
HEAD
POST
PUT
DELETE
CONNETCT
OPTIONS
TRACE
PATCH
## 响应头信息
## 状态码
常见
200请求成功
301资源被转移
404请求的资源不存在
500内部服务器错误
## content-type