// Elismar Silva 
// 28 de novembro de 2023
// Ciencia da Computação - UDF

//Inclusão de bibliotecas
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

//Configuração de rede 
const char* ssid = "";  
const char* password = "";

// Seu numero de telefone ex: 556199999999
String numero_Telefone = "";

//Sua chave Api
//Passo a passo em:  https://www.callmebot.com/blog/free-api-whatsapp-messages/
//EX: 1616722
String chave_Api = "";

String msm = "Mensagem recebida";

//Função enviar mensagem
void enviarMensagem(String mensagem) {

  String url = "http://api.callmebot.com/whatsapp.php?phone=" + numero_Telefone + "&apikey=" + chave_Api + "&text=" + urlEncode(mensagem);

  WiFiClient client;

  HTTPClient http;

  http.begin(client, url);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded");


  int httpResponseCode = http.POST(url);

  if (httpResponseCode == 200) {

    Serial.print("Message sent successfully");


  }

  else {

    Serial.println("Error sending the message");

    Serial.print("HTTP response code: ");

    Serial.println(httpResponseCode);
  }

  http.end();
}

//Inciando configiração
void setup() {

  //Iniciando comunicação serial
  Serial.begin(115200);
  //Comunicação WiFi
  WiFi.begin(ssid, password);

  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");
  }

  Serial.println("");

  Serial.print("Connected to WiFi network with IP Address: ");

  Serial.println(WiFi.localIP());
  enviarMensagem(msm);
}

void loop() {
}