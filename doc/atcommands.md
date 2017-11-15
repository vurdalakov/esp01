# ESP-01 supported AT commands

### AT - Ping device

```
AT
OK
```

### AT+GMR - Get version information

```
AT+GMR
0018000902-AI03
OK
```

### AT+RST - Reset device

```
OK
??SOF?BS??F
?!???b????)?
[Vendor:www.ai-thinker.com Version:0.9.2.4]
ready
```

### ATE0 - Switch command echo off

```
ATE0
OK
```

### ATE1 - Switch command echo on

```
ATE1
OK
```

### AT+CWMODE=? - Get list of supported WiFi modes

```
AT+CWMODE=?
+CWMODE:(1-3)
OK
```

WiFi modes:
* 1: station mode
* 2: access point (AP) mode
* 3: dual mode (station + access point)

### AT+CWMODE? - Get current WiFi mode

```
AT+CWMODE?
+CWMODE:1
OK
```

### AT+CWMODE= - Set current WiFi mode

```
AT+CWMODE=1
OK
```

### AT+CWLAP - List available WiFi networks

```
AT+CWLAP
+CWLAP:(3,"ssid1",-89,"3c:48:11:5f:a1:39",8)
+CWLAP:(4,"ssid2",-87,"30:b7:c4:ba:15:5a",1)
+CWLAP:(3,"ssid3",-63,"1c:b2:2e:d7:d4:b0",11)
OK
```

(ecn,"ssid",rssi,"mac",channel)

Encryption methods (ecn):
* 0: OPEN
* 1: WEP
* 2: WPA_PSK
* 3: WPA2_PSK
* 4: WPA_WPA2_PSK
* 5: WPA2_Enterprise (not supported)

### AT+CWJAP - Connect to WiFi network

```
AT+CWJAP="ssid","password"
OK
```

### AT+CWJAP? - Get SSID of WiFi network device is connecyted to

```
AT+CWJAP?
+CWJAP:"ssid"
OK
```

### AT+CWQAP - Disconnect from WiFi network

```
AT+CWQAP
OK
```

### AT+CIFSR - Get device IP address

WiFi mode 1 (connected):

```
AT+CIFSR
192.168.1.96
OK
```

WiFi mode 2:

```
AT+CIFSR
192.168.4.1
OK
```

WiFi mode 3 (connected):

```
AT+CIFSR
192.168.4.1
192.168.1.96
OK
```

### AT+CWSAP - Configure access point

"ssid","password",channel,ecn

```
AT+CWSAP="esp01","password",12,4
OK
```

### AT+CWSAP? - Get access point configuration

```
+CWSAP:"esp01","password",12,4
OK
```

### AT+CIPMUX? - Get multiple connection status

```
AT+CIPMUX?
+CIPMUX:0
OK
```

Values:
* 0: Single connection
* 1: Multiple connections (max 4)

This mode can only be changed after all connections are disconnected. If server is started, reboot is required.

### AT+CIPMUX - Set multiple connection status

```
AT+CIPMUX=1
OK
```

### AT+CWLIF - Get list of stations connected to device

IP, MAC address

```
AT+CWLIF
192.168.1.1,3c:48:11:5f:a1:39
OK
```

### AT+CIPSTATUS - Get connection status

```
AT+CIPSTATUS
STATUS:4
```

Connection statuses:
* 2: Got IP
* 3: Connected
* 4: Disconnected
