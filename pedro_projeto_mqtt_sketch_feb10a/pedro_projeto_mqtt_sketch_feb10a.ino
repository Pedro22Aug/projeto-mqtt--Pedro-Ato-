#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>

#include <SPI.h>
int pino2 = 2;
bool estado_sensor;



//Variável utilizada para enviar as mensagens utilizando o cliente MQTT
bool mensagem; 

//Define o endereço MAC que será utilizado
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };


//Inicia o cliente Ethernet
EthernetClient client;

//Inicia o client MQTT
PubSubClient mqttClient(client);


void setup() {
   //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    //Define o IP e Porta TCP do Broker MQTT que vamos utilizar
    mqttClient.setServer("54.210.160.207", 1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

     pinMode(pino2,INPUT_PULLUP); //Coloca o Pino 2 como Entrada

  }

void loop() {
 
 
    mqttClient.connect("pedroaugusto");
    estado_sensor=digitalRead(pino2);
    
    if (estado_sensor==1){
      mensagem = mqttClient.publish("pedroaugusto-o","aberto");
      Serial.println("o rack esta aberto");   
    }
    else { 
      mensagem = mqttClient.publish("pedroaugusto-o","fechado");
      Serial.println("o rack esta fechado");    
    }
    
     mqttClient.loop();
     
   

}
