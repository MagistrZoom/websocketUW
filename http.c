#include "server.h"
/*
GET / HTTP/1.1
Host: localhost:2812
Connection: Upgrade
Pragma: no-cache
Cache-Control: no-cache
Upgrade: websocket
Origin: http://localhost
Sec-WebSocket-Version: 13
User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.80 Safari/537.36
Accept-Encoding: gzip, deflate, sdch
Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4,bg;q=0.2
Sec-WebSocket-Key: 59dD1Ffrr2yih5LBb+QTfA==
Sec-WebSocket-Extensions: permessage-deflate; client_max_window_bits
*/
int extract_key_from_valid_headers(char *headers, unsigned char *key){
	char *sec_websocket_key = strstr(headers, "Sec-WebSocket-Key: ") + 19;
	//skip header to reach key (19 is length of head)
	if(sec_websocket_key == NULL)
		return 1;
	memcpy(key, sec_websocket_key, 24);
	return 0;
}