//
// Created by Chahil Patel on 21-09-2018.
//

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* SSID ="Shreeji";
const char* PASS="8866551417Cc";
char web[] PROGMEM =R"=====(
<html>




<head>
<center><font size="100" color="#436a8e">IoT Dashboard</center></font>

<br>
<code><center><font size="40" color="#35266d">By Chahil Patel</center></code></font>
<br>
<br>




<style>


.button {
    background-color: #4CAF50; /* Green */
    border: none;
    color: white;
    padding: 32px 64px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 32px;
    margin: 16px 8px;
    -webkit-transition-duration: 0.4s; /* Safari */
    transition-duration: 0.4s;
    cursor: pointer;
}

.button2 {
    background-color: white;
    color: black;
    border: 2px solid #008CBA;
	padding: 16px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 32px;
    margin: 16px 8px;
}

.button2:hover {
    background-color: #008CBA;
    color: white;
	padding: 16px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 32px;
    margin: 16px 8px;
}

.button3 {
    background-color: white;
    color: black;
    border: 2px solid #f44336;
	padding: 16px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 32px;
    margin: 16px 8px;
}

.button3:hover {
    background-color: #f44336;
    color: white;
	padding: 16px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 32px;
    margin: 16px 8px;
}



</style>
</head>






<body>
<center><button class="button2" type="submit" onclick="UserAction1()">Relay 1 ON</button>
<button class="button3" type="submit" onclick="UserAction2()">Relay 1 OFF</button></center>
<br>
<center>
<button class="button2" type="submit" onclick="UserAction3()">Relay 2 ON</button>
<button class="button3" type="submit" onclick="UserAction4()">Relay 2 OFF</button>
</center>
<br>
<center>
<button class="button2" type="submit" onclick="UserAction5()">Relay 3 ON</button>
<button class="button3" type="submit" onclick="UserAction6()">Relay 3 OFF</button>
</center>
<br>
<center>
<button class="button2" type="submit" onclick="UserAction7()">Relay 4 ON</button>
<button class="button3" type="submit" onclick="UserAction8()">Relay 4 OFF</button>
</center>

<center>
<button class="button2" type="submit" onclick="UserAction9()"> All ON  </button>
<button class="button3" type="submit" onclick="UserAction10()">All OFF  </button>
</center>
<br>
<br>

<br>
<br>

<code><center><font size="5" color="#35266d">This Project is Fully Managed By Chahil Patel</center></code></font>
</body>

</html>
<script type="text/javascript" language="javascript">











































function UserAction1() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/1/1", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction2() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/1/0", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction3() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/2/1", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction4() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/2/0", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction5() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/3/1", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction6() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/3/0", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction7() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/4/1", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
}
function UserAction8() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/digital/4/0", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
	}
function UserAction9() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/function/allon", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
	}
function UserAction10() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "https://cloud.arest.io/chahil/function/alloff", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();
    var response = JSON.parse(xhttp.responseText);
	}

</script>
*/
)=====";
ESP8266WebServer server(80);
void root();
void setup()
{
    pinMode(D4,OUTPUT);
    Serial.begin(9600);
    WiFi.begin(SSID,PASS);
    while (WiFi.status()!= WL_CONNECTED)
    {
        Serial.print("..");
        delay(200);

    }
    Serial.println(WiFi.localIP());
    server.on("/",root);
    server.begin();
}

void loop()
{
    server.handleClient();
}

void root()
{
    int value = server.arg("value").toInt();
    digitalWrite(D4,!value);
    server.send(200,"text/html",web);

    }

